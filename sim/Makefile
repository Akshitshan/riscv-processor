# ============================================================
#  Makefile — RV32IM Processor Project
#
#  COMMANDS:
#    make single              → Phase 2: single-cycle CPU test
#    make pipeline            → Phase 3: pipelined CPU test
#    make build-verify        → Phase 4: compile verify sim (once)
#    make verify TEST=test_alu → Phase 4: run one verification test
#    make regress             → Phase 4: run all 5 tests
#    make clean               → delete all build files
#    make waves               → open GTKWave
#
#  Phase 2 and Phase 3 always use: ../sw/test_program.s
#  Phase 4 uses:                   ../sw/tests/<TEST>.s
# ============================================================

GCC       = riscv64-unknown-elf-gcc
OBJCOPY   = riscv64-unknown-elf-objcopy
VERILATOR = verilator
ARCH      = -march=rv32im -mabi=ilp32

# ── Shared RTL (used by all designs) ─────────────────────────
SHARED = \
    ../rtl/riscv_pkg.sv     \
    ../rtl/alu.sv           \
    ../rtl/imm_gen.sv       \
    ../rtl/pc_reg.sv        \
    ../rtl/instr_mem.sv     \
    ../rtl/reg_file.sv      \
    ../rtl/data_mem.sv      \
    ../rtl/control_unit.sv

# ── Phase 2: single-cycle ────────────────────────────────────
SINGLE_RTL = $(SHARED) ../rtl/riscv_top.sv

# ── Phase 3: pipeline ────────────────────────────────────────
PIPELINE_RTL = $(SHARED)              \
    ../rtl/pipeline_regs.sv           \
    ../rtl/hazard_unit.sv             \
    ../rtl/forward_unit.sv            \
    ../rtl/branch_predictor.sv        \
    ../rtl/icache.sv                  \
    ../rtl/riscv_pipeline.sv

# ── Phase 4: verification ────────────────────────────────────
VERIFY_RTL = $(PIPELINE_RTL)

# ── Original test program (Phases 2 and 3) ───────────────────
ORIG_SRC = ../sw/test_program.s
ORIG_ELF = original.elf
ORIG_HEX = program.hex

# ── Phase 4 test program (set with TEST=xxx) ─────────────────
TEST     ?= test_alu
VERI_SRC  = ../sw/tests/$(TEST).s
VERI_ELF  = verify.elf
VERI_HEX  = program.hex
EXPECTED  = expected_regs.hex

# ─────────────────────────────────────────────────────────────
#  PHASE 2 — single-cycle CPU
# ─────────────────────────────────────────────────────────────
single:
	@echo "[1/3] Compiling original test program..."
	$(GCC) $(ARCH) -nostdlib -nostartfiles -Ttext=0x0 \
	    -o $(ORIG_ELF) $(ORIG_SRC)
	@echo "[2/3] Converting to hex..."
	$(OBJCOPY) -O verilog $(ORIG_ELF) $(ORIG_HEX)
	@echo "[3/3] Running single-cycle simulation..."
	@mkdir -p obj_single
	$(VERILATOR) --binary --timing -sv -Wno-fatal --trace \
	    --top-module tb_riscv -Mdir obj_single \
	    $(SINGLE_RTL) ../tb/tb_riscv.sv
	./obj_single/Vtb_riscv

# ─────────────────────────────────────────────────────────────
#  PHASE 3 — pipelined CPU
# ─────────────────────────────────────────────────────────────
pipeline:
	@echo "[1/3] Compiling original test program..."
	$(GCC) $(ARCH) -nostdlib -nostartfiles -Ttext=0x0 \
	    -o $(ORIG_ELF) $(ORIG_SRC)
	@echo "[2/3] Converting to hex..."
	$(OBJCOPY) -O verilog $(ORIG_ELF) $(ORIG_HEX)
	@echo "[3/3] Running pipeline simulation..."
	@mkdir -p obj_pipeline
	$(VERILATOR) --binary --timing -sv -Wno-fatal --trace \
	    --top-module tb_pipeline -Mdir obj_pipeline \
	    $(PIPELINE_RTL) ../tb/tb_pipeline.sv
	./obj_pipeline/Vtb_pipeline

# ─────────────────────────────────────────────────────────────
#  PHASE 4 — verification (build sim binary once, reuse for all tests)
# ─────────────────────────────────────────────────────────────

# Step A: Build the verification sim binary (do this ONCE)
build-verify:
	@echo "Building verification simulation binary..."
	@echo "(This takes ~15 seconds. Only need to do it once.)"
	@mkdir -p obj_verify
	$(VERILATOR) --binary --timing -sv -Wno-fatal --trace \
	    --top-module tb_verify -Mdir obj_verify \
	    $(VERIFY_RTL) ../tb/tb_verify.sv
	@echo "Done. Binary: obj_verify/Vtb_verify"
	@echo "Now run: make verify TEST=test_alu"

# Step B: Run one verification test
#   Usage: make verify TEST=test_alu
#          make verify TEST=test_hazards
#          make verify TEST=test_branch
#          make verify TEST=test_memory
#          make verify TEST=test_mext
verify:
	@echo "=== Verifying: $(TEST) ==="
	@echo "[1/3] Compiling $(TEST).s..."
	$(GCC) $(ARCH) -nostdlib -nostartfiles -Ttext=0x0 \
	    -o $(VERI_ELF) $(VERI_SRC)
	$(OBJCOPY) -O verilog $(VERI_ELF) $(VERI_HEX)
	@echo "[2/3] Running Python reference model..."
	python3 ../sw/rv32im_sim.py $(VERI_HEX) $(EXPECTED) 2000
	@echo "[3/3] Running RTL verification..."
	./obj_verify/Vtb_verify

# Step C: Run all 5 tests via the Python regression runner
regress: build-verify
	python3 run_regression.py

# ─────────────────────────────────────────────────────────────
#  UTILITIES
# ─────────────────────────────────────────────────────────────
waves:
	gtkwave wave.vcd 2>/dev/null || gtkwave wave_verify.vcd &

disasm:
	riscv64-unknown-elf-objdump -d $(ORIG_ELF) 2>/dev/null || \
	riscv64-unknown-elf-objdump -d $(VERI_ELF)

clean:
	rm -rf obj_single obj_pipeline obj_verify obj_branch obj_icache
	rm -f  *.vcd *.elf *.hex expected_regs.hex
	@echo "Cleaned."

.PHONY: single pipeline build-verify verify regress waves disasm clean unit-alu branch-bench icache-bench

# ── Unit test: ALU in isolation (no pipeline, no clock needed) ─
unit-alu:
	@echo "Running isolated ALU unit test..."
	@mkdir -p obj_unit_alu
	$(VERILATOR) --binary --timing -sv -Wno-fatal \
	    --top-module tb_alu_unit -Mdir obj_unit_alu \
	    ../rtl/riscv_pkg.sv ../rtl/alu.sv ../tb/tb_alu_unit.sv
	./obj_unit_alu/Vtb_alu_unit

# ── Phase 5: Branch predictor benchmark ──────────────────────
BP_RTL = $(PIPELINE_RTL)

branch-bench:
	@echo "[1/3] Compiling test_loop.s..."
	$(GCC) $(ARCH) -nostdlib -nostartfiles -Ttext=0x0 \
	    -o loop.elf ../sw/tests/test_loop.s
	$(OBJCOPY) -O verilog loop.elf program.hex
	@echo "[2/3] Building branch predictor benchmark..."
	@mkdir -p obj_branch
	$(VERILATOR) --binary --timing -sv -Wno-fatal --trace \
	    --top-module tb_branch_bench -Mdir obj_branch \
	    $(BP_RTL) ../tb/tb_branch_bench.sv
	@echo "[3/3] Running..."
	./obj_branch/Vtb_branch_bench

# ── Phase 5b: Instruction cache benchmark ────────────────────
icache-bench:
	@echo "[1/3] Compiling test_loop.s..."
	$(GCC) $(ARCH) -nostdlib -nostartfiles -Ttext=0x0 \
	    -o loop.elf ../sw/tests/test_loop.s
	$(OBJCOPY) -O verilog loop.elf program.hex
	@echo "[2/3] Building instruction cache benchmark..."
	@mkdir -p obj_icache
	$(VERILATOR) --binary --timing -sv -Wno-fatal --trace \
	    --top-module tb_icache_bench -Mdir obj_icache \
	    $(PIPELINE_RTL) ../tb/tb_icache_bench.sv
	@echo "[3/3] Running..."
	./obj_icache/Vtb_icache_bench
