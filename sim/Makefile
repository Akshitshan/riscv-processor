# ============================================================
#  Makefile — RV32IM Single-Cycle CPU
#  Run from inside sim/: cd sim && make
# ============================================================

GCC       = riscv64-unknown-elf-gcc
OBJCOPY   = riscv64-unknown-elf-objcopy
VERILATOR = verilator
ARCH      = -march=rv32im -mabi=ilp32

# Package MUST be first — defines types used by all other modules
RTL_FILES = \
    ../rtl/riscv_pkg.sv    \
    ../rtl/alu.sv          \
    ../rtl/imm_gen.sv      \
    ../rtl/pc_reg.sv       \
    ../rtl/instr_mem.sv    \
    ../rtl/reg_file.sv     \
    ../rtl/data_mem.sv     \
    ../rtl/control_unit.sv \
    ../rtl/riscv_top.sv

TB_FILE  = ../tb/tb_riscv.sv
ASM_SRC  = ../sw/test_program.s
ELF_FILE = test_program.elf
HEX_FILE = program.hex

all: $(HEX_FILE) sim

# Step 1: Compile assembly to ELF binary
$(ELF_FILE): $(ASM_SRC)
	@echo "[1/3] Compiling RISC-V assembly..."
	$(GCC) $(ARCH) -nostdlib -nostartfiles -Ttext=0x0 \
	    -o $(ELF_FILE) $(ASM_SRC)
	@echo "      -> $(ELF_FILE) created"
	@echo "      First 3 instructions (disassembly):"
	@riscv64-unknown-elf-objdump -d $(ELF_FILE) | head -15 | tail -8

# Step 2: Convert ELF to hex (byte-addressed verilog format)
$(HEX_FILE): $(ELF_FILE)
	@echo "[2/3] Converting to hex..."
	$(OBJCOPY) -O verilog $(ELF_FILE) $(HEX_FILE)
	@echo "      -> $(HEX_FILE) created"
	@echo "      First line of hex file:"
	@head -2 $(HEX_FILE)

# Step 3: Simulate with Verilator
# --trace enables VCD waveform output (needed for GTKWave)
sim: $(HEX_FILE)
	@echo "[3/3] Running Verilator simulation..."
	@mkdir -p obj_dir
	$(VERILATOR) --binary --timing -sv -Wno-fatal \
	    --trace \
	    --top-module tb_riscv \
	    -Mdir obj_dir \
	    $(RTL_FILES) $(TB_FILE)
	@echo "      -> Running simulation..."
	./obj_dir/Vtb_riscv

# Open GTKWave (make sure VcXsrv is running on Windows)
waves:
	gtkwave wave.vcd &

# Show full disassembly of the test program
disasm: $(ELF_FILE)
	@echo "=== Full Disassembly ==="
	riscv64-unknown-elf-objdump -d $(ELF_FILE)

# Delete all generated files and rebuild from scratch
clean:
	rm -rf obj_dir *.vcd *.elf *.hex

.PHONY: all sim waves disasm clean
