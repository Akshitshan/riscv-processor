# ============================================================
#  Makefile — RV32IM CPU Project
#  Handles both the single-cycle (Phase 2) and pipeline (Phase 3)
#
#  HOW TO USE (run from inside the sim/ folder):
#
#    make single    → simulate the Phase 2 single-cycle CPU
#    make pipeline  → simulate the Phase 3 pipelined CPU  ← main one
#    make clean     → delete all generated files
#    make disasm    → show disassembly of the test program
#    make waves     → open GTKWave waveform viewer
# ============================================================

GCC       = riscv64-unknown-elf-gcc
OBJCOPY   = riscv64-unknown-elf-objcopy
VERILATOR = verilator
ARCH      = -march=rv32im -mabi=ilp32

# ── Source file lists ─────────────────────────────────────────
#  Files shared by BOTH designs (same hardware modules reused)
SHARED_RTL = \
    ../rtl/riscv_pkg.sv     \
    ../rtl/alu.sv           \
    ../rtl/imm_gen.sv       \
    ../rtl/pc_reg.sv        \
    ../rtl/instr_mem.sv     \
    ../rtl/reg_file.sv      \
    ../rtl/data_mem.sv      \
    ../rtl/control_unit.sv

#  Phase 2: single-cycle top-level
SINGLE_RTL = $(SHARED_RTL) ../rtl/riscv_top.sv
SINGLE_TB  = ../tb/tb_riscv.sv

#  Phase 3: pipeline adds 4 new modules + new top-level
PIPELINE_RTL = $(SHARED_RTL)        \
    ../rtl/pipeline_regs.sv         \
    ../rtl/hazard_unit.sv           \
    ../rtl/forward_unit.sv          \
    ../rtl/riscv_pipeline.sv
PIPELINE_TB = ../tb/tb_pipeline.sv

# ── Common source files ───────────────────────────────────────
ASM_SRC  = ../sw/test_program.s
ELF_FILE = test_program.elf
HEX_FILE = program.hex

# ── Step 1: Compile the assembly test program ─────────────────
#  This step is identical for both designs — same test program
$(ELF_FILE): $(ASM_SRC)
	@echo ""
	@echo "[ 1/3 ] Compiling RISC-V assembly..."
	$(GCC) $(ARCH) -nostdlib -nostartfiles -Ttext=0x0 \
	    -o $(ELF_FILE) $(ASM_SRC)
	@echo "        done → $(ELF_FILE)"

# ── Step 2: Convert ELF → hex ────────────────────────────────
$(HEX_FILE): $(ELF_FILE)
	@echo "[ 2/3 ] Converting to hex..."
	$(OBJCOPY) -O verilog $(ELF_FILE) $(HEX_FILE)
	@echo "        done → $(HEX_FILE)"
	@echo "        First instruction bytes: $$(head -2 $(HEX_FILE) | tail -1 | cut -c1-11)..."

# ── SINGLE-CYCLE simulation (Phase 2) ────────────────────────
single: $(HEX_FILE)
	@echo "[ 3/3 ] Running SINGLE-CYCLE simulation (Phase 2)..."
	@mkdir -p obj_single
	$(VERILATOR) --binary --timing -sv -Wno-fatal --trace \
	    --top-module tb_riscv \
	    -Mdir obj_single \
	    $(SINGLE_RTL) $(SINGLE_TB)
	@echo "        Running..."
	./obj_single/Vtb_riscv

# ── PIPELINE simulation (Phase 3) ────────────────────────────
pipeline: $(HEX_FILE)
	@echo "[ 3/3 ] Running PIPELINE simulation (Phase 3)..."
	@mkdir -p obj_pipeline
	$(VERILATOR) --binary --timing -sv -Wno-fatal --trace \
	    --top-module tb_pipeline \
	    -Mdir obj_pipeline \
	    $(PIPELINE_RTL) $(PIPELINE_TB)
	@echo "        Running..."
	./obj_pipeline/Vtb_pipeline

# ── Shortcuts ─────────────────────────────────────────────────
all: pipeline

waves:
	gtkwave wave.vcd &

disasm: $(ELF_FILE)
	@echo "=== Program Disassembly ==="
	riscv64-unknown-elf-objdump -d $(ELF_FILE)

clean:
	rm -rf obj_single obj_pipeline *.vcd *.elf *.hex
	@echo "Cleaned all build files."

.PHONY: all single pipeline waves disasm clean
