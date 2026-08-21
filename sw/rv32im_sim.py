#!/usr/bin/env python3
"""
rv32im_sim.py — Python behavioral reference model for RV32IM

WHAT THIS IS:
  A software simulation of your RISC-V CPU written in Python.
  It reads the same program.hex your hardware runs, executes
  every instruction step by step, and outputs what the final
  register values SHOULD be.

  This is called a "golden model" in chip verification.
  If your RTL disagrees with this — the RTL has a bug.

USAGE:
  python3 rv32im_sim.py <hex_file> <output_file> [max_instructions]

  hex_file    : the program.hex produced by objcopy
  output_file : where to write expected register values
  max_instrs  : how many instructions to execute (default 2000)

OUTPUT FORMAT (expected_regs.hex):
  32 lines, one 8-digit hex value per line.
  Line 0 = x0 (always 00000000)
  Line 1 = x1, Line 2 = x2 ... Line 31 = x31
  The SV testbench reads this with $readmemh.
"""

import sys

# ── Sign extension helper ────────────────────────────────────
# Converts an N-bit number to a Python signed integer.
# Example: sign_ext(0xFF, 8) = -1
#          sign_ext(0x7F, 8) = 127

def sign_ext(val, bits):
    val &= (1 << bits) - 1          # keep only N bits
    if val >> (bits - 1):            # if top bit is 1 → negative
        val -= (1 << bits)
    return val & 0xFFFFFFFF          # return as unsigned 32-bit

def to_s32(val):
    """Unsigned 32-bit → signed Python integer"""
    val &= 0xFFFFFFFF
    return val - 0x100000000 if val >= 0x80000000 else val


class RV32IMSim:
    def __init__(self):
        self.regs = [0] * 32    # x0 to x31
        self.mem  = bytearray(4096)  # 4 KB (code + data)
        self.pc   = 0

    def load_hex(self, path):
        """Load objcopy -O verilog hex file into memory"""
        addr = 0
        with open(path) as f:
            for line in f:
                line = line.strip()
                if not line: continue
                if line.startswith('@'):
                    addr = int(line[1:], 16)
                else:
                    for byte_str in line.split():
                        if addr < len(self.mem):
                            self.mem[addr] = int(byte_str, 16)
                        addr += 1

    # ── Register file read/write ─────────────────────────────
    def rd(self, r):
        return 0 if r == 0 else (self.regs[r] & 0xFFFFFFFF)

    def wr(self, r, v):
        if r != 0:
            self.regs[r] = v & 0xFFFFFFFF

    # ── Memory helpers (little-endian) ───────────────────────
    def mem_rd32(self, addr):
        a = addr & 0xFFF
        return (self.mem[a] | (self.mem[a+1]<<8) |
                (self.mem[a+2]<<16) | (self.mem[a+3]<<24))

    def mem_wr32(self, addr, val):
        a = addr & 0xFFF
        self.mem[a]   = val & 0xFF
        self.mem[a+1] = (val >> 8)  & 0xFF
        self.mem[a+2] = (val >> 16) & 0xFF
        self.mem[a+3] = (val >> 24) & 0xFF

    def step(self):
        """Execute one instruction. Returns False to stop."""
        if self.pc >= 4096: return False

        pc = self.pc
        instr = (self.mem[pc] | (self.mem[pc+1]<<8) |
                 (self.mem[pc+2]<<16) | (self.mem[pc+3]<<24))

        # ── Decode ───────────────────────────────────────────
        opcode = instr & 0x7F
        rd_    = (instr >>  7) & 0x1F
        f3     = (instr >> 12) & 0x7
        rs1    = (instr >> 15) & 0x1F
        rs2    = (instr >> 20) & 0x1F
        f7     = (instr >> 25) & 0x7F

        imm_i = sign_ext(instr >> 20, 12)
        imm_s = sign_ext(((f7 << 5) | rd_), 12)
        imm_b = sign_ext(
            ((instr>>31)<<12) | (((instr>>7)&1)<<11) |
            (((instr>>25)&0x3F)<<5) | (((instr>>8)&0xF)<<1), 13)
        imm_u = (instr >> 12) << 12
        imm_j = sign_ext(
            ((instr>>31)<<20) | (((instr>>12)&0xFF)<<12) |
            (((instr>>20)&1)<<11) | (((instr>>21)&0x3FF)<<1), 21)

        v1  = self.rd(rs1);  v2 = self.rd(rs2)
        s1  = to_s32(v1);    s2 = to_s32(v2)
        npc = (pc + 4) & 0xFFFFFFFF

        # ── Execute ──────────────────────────────────────────
        if opcode == 0x37:   self.wr(rd_, imm_u & 0xFFFFFFFF)         # LUI
        elif opcode == 0x17: self.wr(rd_, (pc + imm_u) & 0xFFFFFFFF)  # AUIPC
        elif opcode == 0x6F:                                            # JAL
            self.wr(rd_, npc)
            npc = (pc + imm_j) & 0xFFFFFFFF
        elif opcode == 0x67:                                            # JALR
            self.wr(rd_, npc)
            npc = (v1 + imm_i) & ~1 & 0xFFFFFFFF
        elif opcode == 0x63:                                            # BRANCH
            taken = {0:v1==v2, 1:v1!=v2, 4:s1<s2,
                     5:s1>=s2, 6:v1<v2, 7:v1>=v2}.get(f3, False)
            if taken: npc = (pc + imm_b) & 0xFFFFFFFF
        elif opcode == 0x03:                                            # LOAD
            a = (v1 + imm_i) & 0xFFF
            if   f3==0: self.wr(rd_, sign_ext(self.mem[a], 8))
            elif f3==1: self.wr(rd_, sign_ext(self.mem[a]|(self.mem[a+1]<<8), 16))
            elif f3==2: self.wr(rd_, self.mem_rd32(a))
            elif f3==4: self.wr(rd_, self.mem[a])
            elif f3==5: self.wr(rd_, (self.mem[a]|(self.mem[a+1]<<8))&0xFFFF)
        elif opcode == 0x23:                                            # STORE
            a = (v1 + imm_s) & 0xFFF
            if   f3==0: self.mem[a] = v2 & 0xFF
            elif f3==1: self.mem[a]=v2&0xFF; self.mem[a+1]=(v2>>8)&0xFF
            elif f3==2: self.mem_wr32(a, v2)
        elif opcode == 0x13:                                            # OP-IMM
            sh = imm_i & 0x1F
            ops = {0:(v1+imm_i)&0xFFFFFFFF, 1:(v1<<sh)&0xFFFFFFFF,
                   2:1 if s1<to_s32(imm_i&0xFFFFFFFF) else 0,
                   3:1 if v1<(imm_i&0xFFFFFFFF) else 0,
                   4:(v1^imm_i)&0xFFFFFFFF,
                   6:(v1|imm_i)&0xFFFFFFFF, 7:(v1&imm_i)&0xFFFFFFFF}
            if f3==5:
                ops[5]=(s1>>sh)&0xFFFFFFFF if f7==0x20 else (v1>>sh)&0xFFFFFFFF
            if f3 in ops: self.wr(rd_, ops[f3])
        elif opcode == 0x33:                                            # OP / M-ext
            if f7 == 0x01:  # M extension
                if   f3==0: self.wr(rd_, (s1*s2)&0xFFFFFFFF)
                elif f3==1: self.wr(rd_, ((s1*s2)>>32)&0xFFFFFFFF)
                elif f3==2: self.wr(rd_, ((s1*v2)>>32)&0xFFFFFFFF)
                elif f3==3: self.wr(rd_, ((v1*v2)>>32)&0xFFFFFFFF)
                elif f3==4: self.wr(rd_, 0xFFFFFFFF if s2==0 else
                    (abs(s1)//abs(s2)*(-1 if (s1<0)^(s2<0) else 1))&0xFFFFFFFF)
                elif f3==5: self.wr(rd_, 0xFFFFFFFF if v2==0 else (v1//v2)&0xFFFFFFFF)
                elif f3==6: self.wr(rd_, v1 if s2==0 else
                    (s1-(abs(s1)//abs(s2)*(-1 if (s1<0)^(s2<0) else 1)*s2))&0xFFFFFFFF)
                elif f3==7: self.wr(rd_, v1 if v2==0 else (v1%v2)&0xFFFFFFFF)
            else:
                ops={0:(v1-v2)&0xFFFFFFFF if f7==0x20 else (v1+v2)&0xFFFFFFFF,
                     1:(v1<<(v2&31))&0xFFFFFFFF, 2:1 if s1<s2 else 0,
                     3:1 if v1<v2 else 0, 4:(v1^v2)&0xFFFFFFFF,
                     5:(s1>>(v2&31))&0xFFFFFFFF if f7==0x20 else (v1>>(v2&31))&0xFFFFFFFF,
                     6:(v1|v2)&0xFFFFFFFF, 7:(v1&v2)&0xFFFFFFFF}
                if f3 in ops: self.wr(rd_, ops[f3])

        self.regs[0] = 0  # x0 always hardwired to 0
        self.pc = npc
        return True

    def run(self, max_instrs=2000):
        prev_pc = -1
        for _ in range(max_instrs):
            if self.pc == prev_pc: break   # halt: infinite loop (j done)
            prev_pc = self.pc
            if not self.step(): break

    def write_expected(self, path):
        """Write 32 expected register values for $readmemh"""
        with open(path, 'w') as f:
            for v in self.regs:
                f.write(f"{v & 0xFFFFFFFF:08x}\n")

    def print_nonzero(self):
        for i, v in enumerate(self.regs):
            if v: print(f"  x{i:<2} = 0x{v:08x} ({v})")


if __name__ == '__main__':
    hex_in  = sys.argv[1] if len(sys.argv) > 1 else 'program.hex'
    out_f   = sys.argv[2] if len(sys.argv) > 2 else 'expected_regs.hex'
    max_i   = int(sys.argv[3]) if len(sys.argv) > 3 else 2000
    sim = RV32IMSim()
    sim.load_hex(hex_in)
    sim.run(max_i)
    sim.write_expected(out_f)
    print(f"[ref] {hex_in} → {out_f}")
    sim.print_nonzero()
