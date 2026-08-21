#!/usr/bin/env python3
"""
run_regression.py — Phase 4 Regression Runner

HOW IT WORKS:
  For each test program in sw/tests/:
    1. Compile assembly → ELF → hex (using RISC-V GCC)
    2. Run Python reference model → expected_regs.hex
    3. Run Verilator RTL simulation → parse actual register values
    4. Compare expected vs actual register by register
    5. Print PASS / FAIL per test

USAGE (run from inside the sim/ folder):
  python3 run_regression.py

REQUIREMENTS:
  - Run 'make build-verify' once first to compile the Verilator sim
  - riscv64-unknown-elf-gcc must be installed
"""

import subprocess, os, sys, re

# ── Tools ─────────────────────────────────────────────────────
GCC     = "riscv64-unknown-elf-gcc"
OBJCOPY = "riscv64-unknown-elf-objcopy"
PY_SIM  = "../sw/rv32im_sim.py"
SIM_BIN = "./obj_verify/Vtb_verify"

# ── Test list ─────────────────────────────────────────────────
TESTS = [
    ("ALU Instructions",     "test_alu"),
    ("Pipeline Hazards",     "test_hazards"),
    ("Branch Instructions",  "test_branch"),
    ("Memory Load / Store",  "test_memory"),
    ("M-Extension (mul/div)","test_mext"),
]

# ── Helpers ───────────────────────────────────────────────────

def run(cmd, **kw):
    """Run a shell command, raise on failure"""
    return subprocess.run(cmd, capture_output=True, text=True,
                          check=True, **kw)

def compile_test(name):
    """Compile sw/tests/<name>.s → program.hex in sim/"""
    src = f"../sw/tests/{name}.s"
    elf = "temp_test.elf"
    run([GCC, "-march=rv32im", "-mabi=ilp32",
         "-nostdlib", "-nostartfiles", "-Ttext=0x0",
         "-o", elf, src])
    run([OBJCOPY, "-O", "verilog", elf, "program.hex"])
    print(f"  [1/3] Compiled {name}.s → program.hex")

def run_reference():
    """Run Python reference model → expected_regs.hex"""
    run(["python3", PY_SIM, "program.hex", "expected_regs.hex", "2000"])
    # Read expected values back
    regs = []
    with open("expected_regs.hex") as f:
        for line in f:
            line = line.strip()
            if line:
                regs.append(int(line, 16))
    nz = sum(1 for v in regs[1:] if v)
    print(f"  [2/3] Reference model: {nz} non-zero registers")
    return regs

def run_rtl_sim():
    """Run Verilator RTL simulation, parse register dump"""
    result = subprocess.run([SIM_BIN], capture_output=True, text=True)
    regs   = [0] * 32
    in_dump = False
    for line in result.stdout.split('\n'):
        if 'REGDUMP_START' in line: in_dump = True;  continue
        if 'REGDUMP_END'   in line: in_dump = False; continue
        if in_dump:
            m = re.match(r'x(\d+)=0x([0-9a-fA-F]+)', line)
            if m:
                regs[int(m.group(1))] = int(m.group(2), 16)
    print(f"  [3/3] RTL simulation complete")
    return regs, result.stdout

def compare(expected, actual):
    """Compare register files, return (pass_count, fail_list)"""
    fails = []
    passes = 0
    for i in range(1, 32):
        e = expected[i] & 0xFFFFFFFF
        a = actual[i]   & 0xFFFFFFFF
        if e == a:
            passes += 1
        else:
            fails.append((i, e, a))
    return passes, fails


# ── Main ──────────────────────────────────────────────────────

def main():
    total_pass = total_fail = 0
    results = []

    print("\n" + "="*58)
    print("  Phase 4 — Regression Test Suite")
    print("="*58)

    # Check the simulation binary exists
    if not os.path.isfile(SIM_BIN):
        print(f"\n[ERROR] {SIM_BIN} not found.")
        print("  Run 'make build-verify' first to compile the simulation.")
        sys.exit(1)

    for desc, name in TESTS:
        print(f"\n  ── {desc} ({name}.s) ──")
        try:
            compile_test(name)
            expected = run_reference()
            actual, stdout = run_rtl_sim()
            p, fails = compare(expected, actual)

            total_pass += p
            total_fail += len(fails)

            if not fails:
                print(f"  ✓  PASSED  ({p} registers verified)")
            else:
                print(f"  ✗  FAILED  ({len(fails)} mismatches):")
                for r, e, a in fails:
                    print(f"       x{r:<2}: expected 0x{e:08x}  got 0x{a:08x}")
            results.append((desc, len(fails) == 0))

        except subprocess.CalledProcessError as e:
            print(f"  ✗  ERROR: {e.stderr[:200]}")
            results.append((desc, False))
            total_fail += 1
        except FileNotFoundError as e:
            print(f"  ✗  FILE NOT FOUND: {e}")
            results.append((desc, False))
            total_fail += 1

    # ── Summary ───────────────────────────────────────────────
    print("\n" + "="*58)
    print("  RESULTS")
    print("="*58)
    for desc, ok in results:
        mark = "✓ PASS" if ok else "✗ FAIL"
        print(f"  {mark}  {desc}")

    print(f"\n  Total register checks : {total_pass + total_fail}")
    print(f"  Passed : {total_pass}")
    print(f"  Failed : {total_fail}")

    if total_fail == 0:
        print("\n  *** ALL TESTS PASSED — CPU FULLY VERIFIED ***")
    else:
        print("\n  *** FAILURES DETECTED — debug with GTKWave ***")
    print("="*58 + "\n")

    return 0 if total_fail == 0 else 1

if __name__ == '__main__':
    sys.exit(main())
