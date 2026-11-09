# ============================================================
# Desktop compiler configuration
# ============================================================

CC ?= gcc
CFLAGS := -O3 -Wall -Wextra -Wpedantic -std=c11
LDFLAGS :=
LDLIBS := -lm -lsqlite3
CPU_THREADS := $(shell nproc)
MAKE_JOBS := $(shell echo $$(( $(CPU_THREADS) * 3 )))
MAKEFLAGS += -j$(MAKE_JOBS)

GPU_CFLAGS := -Wno-overlength-strings -Wno-unused-function
GPU_LDLIBS := -lOpenCL


# ============================================================
# Optional desktop acceleration tools
# ============================================================

ifneq (,$(shell command -v ccache 2>/dev/null))
    CC_CMD := ccache $(CC)
else
    CC_CMD := $(CC)
endif

ifneq (,$(shell command -v mold 2>/dev/null))
    LDFLAGS += -fuse-ld=mold
endif


# ============================================================
# Targets and directories
# ============================================================

STRENGTH_TARGET := strength-app
STRENGTH_SOURCE := strength.c
STRENGTH_OUTPUT := strength

GREENHOUSE_TARGET := greenhouse-app
GREENHOUSE_SOURCE := greenhouse.c
GREENHOUSE_OUTPUT := greenhouse

BRAKING_TARGET := braking-app
BRAKING_SOURCE := braking.c
BRAKING_OUTPUT := braking

BRAKING_GPU_TARGET := braking-gpu
BRAKING_GPU_SOURCE := braking_gpu_demo.c
BRAKING_GPU_OUTPUT := braking_gpu

DEMO_TARGET := fuzzy-demo
DEMO_SOURCE := demo_all.c
DEMO_OUTPUT := demo-all

SUGENO_TARGET := sugeno-app
SUGENO_SOURCE := sugeno_demo.c
SUGENO_OUTPUT := sugeno

GPU_TARGET := demo-all-gpu
GPU_SOURCE := demo_all_gpu.c
GPU_OUTPUT := demo-gpu

FUZZY_NEURON_TARGET := fuzzy-neuron
FUZZY_NEURON_SOURCE := fuzzy_neuron_train.c
FUZZY_NEURON_PLUGIN := fuzzy_model_rules.so
FUZZY_NEURON_KERNEL := fuzzy_neuron_kernels.cl
FUZZY_NEURON_OUTPUT := fuzzy-neuron-output
FUZZY_NEURON_MODEL := $(FUZZY_NEURON_OUTPUT)/fuzzy_neuron_model.csv
FUZZY_NEURON_TEST_OUTPUT := $(FUZZY_NEURON_OUTPUT)/fuzzy_neuron_test_predictions.csv
FUZZY_NEURON_ORIGINAL_OUTPUT := $(FUZZY_NEURON_OUTPUT)/fuzzy_neuron_original_predictions.csv
FUZZY_NEURON_DATASET := sugeno/sugeno_complex_sweep.csv

FUZZY_NEURON_EPOCHS ?= 2000
FUZZY_NEURON_BATCH_SIZE ?= 4096
FUZZY_NEURON_LEARNING_RATE ?= 0.01
FUZZY_NEURON_REPORT_INTERVAL ?= 100

FUZZY_NEURON_TEMPERATURE ?= 50
FUZZY_NEURON_LOAD ?= 50
FUZZY_NEURON_VIBRATION ?= 5
FUZZY_NEURON_TEST_DATASET ?= fuzzy-neuron-test.csv

SIM_8051_ROOT := sim-8051

MAMDANI_8051_TARGET := sim-8051-app
MAMDANI_8051_SOURCE := controller_8051.c
MAMDANI_8051_OUTPUT := $(SIM_8051_ROOT)/desktop

MAMDANI_EMBEDDED_SOURCE := controller_8051.c
MAMDANI_EMBEDDED_OUTPUT := $(SIM_8051_ROOT)/embedded
MAMDANI_EMBEDDED_BASENAME := controller_8051

SUGENO_EMBEDDED_OUTPUT := $(SUGENO_OUTPUT)/embedded
SUGENO_EMBEDDED_BASENAME := sugeno_8051


# ============================================================
# Embedded 8051 tools
# ============================================================

SDCC ?= sdcc
PACKIHX ?= packihx
SDCDB ?= sdcdb
SVG_CONVERTER ?= rsvg-convert

ifdef S51
    SIMULATOR_COMMAND := $(S51)
else ifneq (,$(shell command -v ucsim_51 2>/dev/null))
    SIMULATOR_COMMAND := ucsim_51
else ifneq (,$(shell command -v s51 2>/dev/null))
    SIMULATOR_COMMAND := s51
else
    SIMULATOR_COMMAND :=
endif


# ============================================================
# ESP32-S3 tools
# ============================================================

ESP32_CHIP ?= esp32s3

ESP32_CC ?= xtensa-esp-elf-gcc
ESP32_OBJCOPY ?= xtensa-esp-elf-objcopy
ESP32_SIZE ?= xtensa-esp-elf-size

ESP32_SOURCE := esp32_demo.c
ESP32_ROOT := esp32
ESP32_BUILD := $(ESP32_ROOT)/build

ESP32_ELF := $(ESP32_BUILD)/esp32_demo.elf
ESP32_BIN := $(ESP32_BUILD)/esp32_demo.bin

ESP32_SIM ?= esp-emu

ESP32_CFLAGS := \
    -O2 \
    -Wall \
    -Wextra \
    -Wpedantic \
    -ffunction-sections \
    -fdata-sections \
    -mlongcalls \
    -I.

ESP32_LDFLAGS := \
    -Wl,--gc-sections \
    -Wl,-Map,$(ESP32_BUILD)/esp32_demo.map

ESP32_LDLIBS := -lm


# ============================================================
# Main targets
# ============================================================

.PHONY: \
    all \
    desktop \
    embedded \
    esp32 \
    esp32-build \
    esp32-bin \
    run-esp32 \
    check-esp32 \
    clean-esp32 \
    run-strength \
    run-greenhouse \
    run-braking \
    run-braking-gpu \
    run-demo \
    run-sugeno \
    run-gpu \
    run-fuzzy-neuron \
    train-fuzzy-neuron \
    test-fuzzy-neuron \
    test-fuzzy-neuron-csv \
    compare-fuzzy-neuron \
    plots-fuzzy-neuron \
    time-fuzzy-neuron-train \
    time-fuzzy-neuron-test \
    time-braking \
    time-braking-gpu \
    time-demo \
    time-gpu \
    run-sim-8051 \
    embedded-mamdani \
    embedded-sugeno \
    build-8051 \
    build-sugeno-8051 \
    simulate-8051 \
    simulate-sugeno \
    debug-8051 \
    check-dependencies \
    install-dependencies \
    png \
    png-strength \
    png-greenhouse \
    png-braking \
    png-braking-gpu \
    png-demo \
    png-sugeno \
    png-gpu \
    png-sim-8051 \
    png-fuzzy-neuron \
    pdf \
    pdf-strength \
    pdf-greenhouse \
    pdf-braking \
    pdf-braking-gpu \
    pdf-demo \
    pdf-sugeno \
    pdf-gpu \
    pdf-sim-8051 \
    pdf-fuzzy-neuron \
    clean \
    clean-desktop \
    clean-embedded \
    clean-embedded-mamdani \
    clean-embedded-sugeno \
    clean-fuzzy-neuron \
    clean-esp32 \
    help

all: desktop embedded

desktop: \
    $(STRENGTH_TARGET) \
    $(GREENHOUSE_TARGET) \
    $(BRAKING_TARGET) \
    $(BRAKING_GPU_TARGET) \
    $(DEMO_TARGET) \
    $(SUGENO_TARGET) \
    $(GPU_TARGET) \
    $(MAMDANI_8051_TARGET) \
    $(FUZZY_NEURON_TARGET) \
    $(FUZZY_NEURON_PLUGIN)

embedded: embedded-mamdani embedded-sugeno


# ============================================================
# Directory creation
# ============================================================

$(STRENGTH_OUTPUT) \
$(GREENHOUSE_OUTPUT) \
$(BRAKING_OUTPUT) \
$(BRAKING_GPU_OUTPUT) \
$(DEMO_OUTPUT) \
$(SUGENO_OUTPUT) \
$(GPU_OUTPUT) \
$(MAMDANI_8051_OUTPUT) \
$(MAMDANI_EMBEDDED_OUTPUT) \
$(SUGENO_EMBEDDED_OUTPUT) \
$(FUZZY_NEURON_OUTPUT) \
$(ESP32_BUILD):
	mkdir -p $@


# ============================================================
# Desktop builds
# ============================================================

$(STRENGTH_TARGET): $(STRENGTH_SOURCE) fuzzy.h | $(STRENGTH_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Building $@ from $<..."
	@echo "============================================================"
	$(CC_CMD) $(CFLAGS) $< $(LDFLAGS) -o $@ $(LDLIBS)
	@echo "[OK] Built $@"


$(GREENHOUSE_TARGET): $(GREENHOUSE_SOURCE) fuzzy.h | $(GREENHOUSE_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Building $@ from $<..."
	@echo "============================================================"
	$(CC_CMD) $(CFLAGS) $< $(LDFLAGS) -o $@ $(LDLIBS)
	@echo "[OK] Built $@"


$(BRAKING_TARGET): $(BRAKING_SOURCE) fuzzy.h | $(BRAKING_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Building CPU braking demonstration from $<..."
	@echo "============================================================"
	$(CC_CMD) $(CFLAGS) $< $(LDFLAGS) -o $@ $(LDLIBS)
	@echo "[OK] Built $@"


$(BRAKING_GPU_TARGET): $(BRAKING_GPU_SOURCE) fuzzy.h | $(BRAKING_GPU_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Building OpenCL GPU braking demonstration from $<..."
	@echo "GPU/CPU comparison and hedge-extreme tests enabled"
	@echo "GPU acceleration mode: -DFUZZY_OPENCL"
	@echo "============================================================"
	$(CC_CMD) $(CFLAGS) $(GPU_CFLAGS) $< $(LDFLAGS) -o $@ $(GPU_LDLIBS) $(LDLIBS)
	@echo "[OK] Built $@"


$(DEMO_TARGET): $(DEMO_SOURCE) fuzzy.h | $(DEMO_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Building $@ from $<..."
	@echo "CPU sweep mode"
	@echo "============================================================"
	$(CC_CMD) $(CFLAGS) $< $(LDFLAGS) -o $@ $(LDLIBS)
	@echo "[OK] Built $@"


$(SUGENO_TARGET): $(SUGENO_SOURCE) fuzzy.h | $(SUGENO_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Building $@ from $<..."
	@echo "Desktop simulation mode: -DSIMULATION"
	@echo "============================================================"
	$(CC_CMD) $(CFLAGS) -DSIMULATION $< $(LDFLAGS) -o $@ $(LDLIBS)
	@echo "[OK] Built $@"


$(GPU_TARGET): $(GPU_SOURCE) fuzzy.h | $(GPU_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Building OpenCL GPU demonstration from $<..."
	@echo "GPU COG sweep and GPU interpolation sweep enabled"
	@echo "GPU acceleration mode: -DFUZZY_OPENCL"
	@echo "============================================================"
	$(CC_CMD) $(CFLAGS) $(GPU_CFLAGS) $< $(LDFLAGS) -o $@ $(GPU_LDLIBS) $(LDLIBS)
	@echo "[OK] Built $@"


$(MAMDANI_8051_TARGET): $(MAMDANI_8051_SOURCE) fuzzy.h | $(MAMDANI_8051_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Building $@ from $<..."
	@echo "Desktop simulation mode: -DSIMULATION"
	@echo "============================================================"
	$(CC_CMD) $(CFLAGS) -DSIMULATION $< $(LDFLAGS) -o $@ $(LDLIBS)
	@echo "[OK] Built $@"


$(FUZZY_NEURON_PLUGIN): $(FUZZY_NEURON_SOURCE) fuzzy.h
	@echo ""
	@echo "============================================================"
	@echo "Building fuzzy-neuron model plugin"
	@echo "Source: $(FUZZY_NEURON_SOURCE)"
	@echo "Output: $(FUZZY_NEURON_PLUGIN)"
	@echo "============================================================"
	$(CC_CMD) $(CFLAGS) $(GPU_CFLAGS) -DFUZZY_MODEL_PLUGIN_ONLY -fPIC -shared $(FUZZY_NEURON_SOURCE) $(LDFLAGS) -o $(FUZZY_NEURON_PLUGIN) $(GPU_LDLIBS) $(LDLIBS)
	@echo "[OK] Built $(FUZZY_NEURON_PLUGIN)"


$(FUZZY_NEURON_TARGET): $(FUZZY_NEURON_SOURCE) fuzzy.h $(FUZZY_NEURON_KERNEL)
	@echo ""
	@echo "============================================================"
	@echo "Building fuzzy-neuron training, testing, and comparison CLI"
	@echo "============================================================"
	$(CC_CMD) $(CFLAGS) $(GPU_CFLAGS) -rdynamic $(FUZZY_NEURON_SOURCE) $(LDFLAGS) -o $(FUZZY_NEURON_TARGET) $(GPU_LDLIBS) -ldl $(LDLIBS)
	@echo "[OK] Built $(FUZZY_NEURON_TARGET)"


# ============================================================
# ESP32 build
# ============================================================

$(ESP32_ELF): $(ESP32_SOURCE) fuzzy.h | $(ESP32_BUILD)
	@echo ""
	@echo "============================================================"
	@echo "Building ESP32 demo from $<..."
	@echo "Compiler: $(ESP32_CC)"
	@echo "============================================================"
	$(ESP32_CC) $(ESP32_CFLAGS) $(ESP32_LDFLAGS) $< -o $@ $(ESP32_LDLIBS)
	@echo "[OK] Built $@"
	@$(ESP32_SIZE) $@


$(ESP32_BIN): $(ESP32_ELF)
	@echo ""
	@echo "============================================================"
	@echo "Converting ESP32 ELF to binary"
	@echo "============================================================"
	$(ESP32_OBJCOPY) -O binary $< $@
	@echo "[OK] Built $@"


esp32-build: $(ESP32_ELF)


esp32-bin: $(ESP32_BIN)


esp32: esp32-bin
	@echo ""
	@echo "============================================================"
	@echo "ESP32 build complete"
	@echo "============================================================"
	@echo "Source: $(ESP32_SOURCE)"
	@echo "ELF:    $(ESP32_ELF)"
	@echo "BIN:    $(ESP32_BIN)"


run-esp32: esp32
	@echo ""
	@echo "============================================================"
	@echo "Running ESP32-S3 firmware"
	@echo "============================================================"
	@if ! command -v $(ESP32_SIM) >/dev/null 2>&1; then \
		echo "Error: $(ESP32_SIM) was not found."; \
		exit 1; \
	fi
	$(ESP32_SIM) --chip $(ESP32_CHIP) --firmware $(ESP32_BIN)


check-esp32:
	@echo ""
	@echo "============================================================"
	@echo "Checking ESP32 toolchain"
	@echo "============================================================"
	@for cmd in $(ESP32_CC) $(ESP32_OBJCOPY) $(ESP32_SIZE); do \
		if command -v $$cmd >/dev/null 2>&1; then \
			echo "[OK]       $$cmd"; \
		else \
			echo "[MISSING]  $$cmd"; \
		fi; \
	done
	@if command -v $(ESP32_SIM) >/dev/null 2>&1; then \
		echo "[OK]       $(ESP32_SIM)"; \
	else \
		echo "[MISSING]  $(ESP32_SIM)"; \
	fi


# ============================================================
# Desktop execution
# ============================================================

run-strength: $(STRENGTH_TARGET)
	@echo ""
	@echo "============================================================"
	@echo "Running paint-strength example"
	@echo "============================================================"
	./$(STRENGTH_TARGET)


run-greenhouse: $(GREENHOUSE_TARGET)
	@echo ""
	@echo "============================================================"
	@echo "Running greenhouse example"
	@echo "============================================================"
	./$(GREENHOUSE_TARGET)


run-braking: $(BRAKING_TARGET)
	@echo ""
	@echo "============================================================"
	@echo "Running CPU braking demonstration"
	@echo "============================================================"
	./$(BRAKING_TARGET)


run-braking-gpu: $(BRAKING_GPU_TARGET)
	@echo ""
	@echo "============================================================"
	@echo "Running OpenCL GPU braking demonstration"
	@echo "============================================================"
	./$(BRAKING_GPU_TARGET)


run-demo: $(DEMO_TARGET)
	@echo ""
	@echo "============================================================"
	@echo "Running complete CPU fuzzy.h demonstration"
	@echo "============================================================"
	./$(DEMO_TARGET)


run-sugeno: $(SUGENO_TARGET)
	@echo ""
	@echo "============================================================"
	@echo "Running complex Sugeno controller demonstration"
	@echo "============================================================"
	cd $(SUGENO_OUTPUT) && ../$(SUGENO_TARGET)


run-gpu: $(GPU_TARGET)
	@echo ""
	@echo "============================================================"
	@echo "Running complete OpenCL fuzzy.h demonstration"
	@echo "============================================================"
	./$(GPU_TARGET)


run-fuzzy-neuron: $(FUZZY_NEURON_TARGET) $(FUZZY_NEURON_PLUGIN)
	@echo ""
	@echo "============================================================"
	@echo "Running interactive fuzzy-neuron CLI"
	@echo "============================================================"
	./$(FUZZY_NEURON_TARGET)


train-fuzzy-neuron: $(FUZZY_NEURON_TARGET) $(FUZZY_NEURON_PLUGIN)
	@echo ""
	@echo "============================================================"
	@echo "Training fuzzy-neuron model"
	@echo "============================================================"
	printf '1\n5\n' | ./$(FUZZY_NEURON_TARGET)


test-fuzzy-neuron: $(FUZZY_NEURON_TARGET) $(FUZZY_NEURON_PLUGIN)
	@echo ""
	@echo "============================================================"
	@echo "Testing fuzzy-neuron model"
	@echo "============================================================"
	printf '2\n$(FUZZY_NEURON_TEMPERATURE) $(FUZZY_NEURON_LOAD) $(FUZZY_NEURON_VIBRATION)\n5\n' | ./$(FUZZY_NEURON_TARGET)


test-fuzzy-neuron-csv: $(FUZZY_NEURON_TARGET) $(FUZZY_NEURON_PLUGIN)
	@echo ""
	@echo "============================================================"
	@echo "Testing fuzzy-neuron model against CSV"
	@echo "============================================================"
	printf '3\n$(FUZZY_NEURON_TEST_DATASET)\n5\n' | ./$(FUZZY_NEURON_TARGET)


compare-fuzzy-neuron: $(FUZZY_NEURON_TARGET) $(FUZZY_NEURON_PLUGIN)
	@echo ""
	@echo "============================================================"
	@echo "Comparing fuzzy-neuron model"
	@echo "============================================================"
	printf '4\n5\n' | ./$(FUZZY_NEURON_TARGET)


plots-fuzzy-neuron: train-fuzzy-neuron
	@echo ""
	@echo "Fuzzy-neuron plots generated under $(FUZZY_NEURON_OUTPUT)"


time-fuzzy-neuron-train: $(FUZZY_NEURON_TARGET) $(FUZZY_NEURON_PLUGIN)
	@echo ""
	@echo "============================================================"
	@echo "Timing fuzzy-neuron training"
	@echo "============================================================"
	time sh -c "printf '1\n$(FUZZY_NEURON_EPOCHS)\n$(FUZZY_NEURON_BATCH_SIZE)\n$(FUZZY_NEURON_LEARNING_RATE)\n$(FUZZY_NEURON_REPORT_INTERVAL)\n5\n' | ./$(FUZZY_NEURON_TARGET)"


time-fuzzy-neuron-test: $(FUZZY_NEURON_TARGET) $(FUZZY_NEURON_PLUGIN)
	@echo ""
	@echo "============================================================"
	@echo "Timing fuzzy-neuron inference"
	@echo "============================================================"
	time sh -c "printf '2\n$(FUZZY_NEURON_TEMPERATURE) $(FUZZY_NEURON_LOAD) $(FUZZY_NEURON_VIBRATION)\n5\n' | ./$(FUZZY_NEURON_TARGET)"


time-braking: $(BRAKING_TARGET)
	@echo ""
	@echo "============================================================"
	@echo "Timing CPU braking demonstration"
	@echo "============================================================"
	time ./$(BRAKING_TARGET)


time-braking-gpu: $(BRAKING_GPU_TARGET)
	@echo ""
	@echo "============================================================"
	@echo "Timing OpenCL GPU braking demonstration"
	@echo "============================================================"
	time ./$(BRAKING_GPU_TARGET)


time-demo: $(DEMO_TARGET)
	@echo ""
	@echo "============================================================"
	@echo "Timing complete CPU fuzzy.h demonstration"
	@echo "============================================================"
	time ./$(DEMO_TARGET)


time-gpu: $(GPU_TARGET)
	@echo ""
	@echo "============================================================"
	@echo "Timing complete OpenCL fuzzy.h demonstration"
	@echo "============================================================"
	time ./$(GPU_TARGET)


run-sim-8051: $(MAMDANI_8051_TARGET)
	@echo ""
	@echo "============================================================"
	@echo "Running desktop Mamdani 8051 simulation harness"
	@echo "============================================================"
	cd $(MAMDANI_8051_OUTPUT) && ../../$(MAMDANI_8051_TARGET)


# ============================================================
# Embedded SDCC builds
# ============================================================

embedded-mamdani build-8051: $(MAMDANI_EMBEDDED_SOURCE) fuzzy.h | $(MAMDANI_EMBEDDED_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Building Mamdani AT89S52 firmware with SDCC"
	@echo "============================================================"
	@rm -f $(MAMDANI_EMBEDDED_OUTPUT)/$(MAMDANI_EMBEDDED_BASENAME).*
	cd $(MAMDANI_EMBEDDED_OUTPUT) && $(SDCC) -mmcs51 --model-small --opt-code-size --stack-auto --debug --iram-size 256 -I../.. -o $(MAMDANI_EMBEDDED_BASENAME).ihx ../../$(MAMDANI_EMBEDDED_SOURCE)
	cd $(MAMDANI_EMBEDDED_OUTPUT) && $(PACKIHX) $(MAMDANI_EMBEDDED_BASENAME).ihx > $(MAMDANI_EMBEDDED_BASENAME).hex
	@echo ""
	@echo "Generated Mamdani firmware:"
	@echo "  $(MAMDANI_EMBEDDED_OUTPUT)/$(MAMDANI_EMBEDDED_BASENAME).ihx"
	@echo "  $(MAMDANI_EMBEDDED_OUTPUT)/$(MAMDANI_EMBEDDED_BASENAME).hex"


embedded-sugeno build-sugeno-8051: $(SUGENO_SOURCE) fuzzy.h | $(SUGENO_EMBEDDED_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Building Sugeno AT89S52 firmware with SDCC"
	@echo "============================================================"
	@rm -f $(SUGENO_EMBEDDED_OUTPUT)/$(SUGENO_EMBEDDED_BASENAME).*
	cd $(SUGENO_EMBEDDED_OUTPUT) && $(SDCC) -mmcs51 --model-small --opt-code-size --debug --stack-auto --iram-size 256 --stack-loc 0x80 -I../.. -o $(SUGENO_EMBEDDED_BASENAME).ihx ../../$(SUGENO_SOURCE)
	cd $(SUGENO_EMBEDDED_OUTPUT) && $(PACKIHX) $(SUGENO_EMBEDDED_BASENAME).ihx > $(SUGENO_EMBEDDED_BASENAME).hex
	@echo ""
	@echo "Generated Sugeno firmware:"
	@echo "  $(SUGENO_EMBEDDED_OUTPUT)/$(SUGENO_EMBEDDED_BASENAME).ihx"
	@echo "  $(SUGENO_EMBEDDED_OUTPUT)/$(SUGENO_EMBEDDED_BASENAME).hex"


# ============================================================
# Embedded execution and testing
# ============================================================

simulate-8051: embedded-mamdani
	@if [ -z "$(SIMULATOR_COMMAND)" ]; then \
		echo "Error: no 8051 simulator was found."; \
		exit 1; \
	fi
	@echo ""
	@echo "============================================================"
	@echo "Starting Mamdani 8051 simulator"
	@echo "============================================================"
	$(SIMULATOR_COMMAND) -t 52 -X 11.0592M $(MAMDANI_EMBEDDED_OUTPUT)/$(MAMDANI_EMBEDDED_BASENAME).ihx


simulate-sugeno: embedded-sugeno
	@if [ -z "$(SIMULATOR_COMMAND)" ]; then \
		echo "Error: no 8051 simulator was found."; \
		exit 1; \
	fi
	@echo ""
	@echo "============================================================"
	@echo "Starting Sugeno 8051 simulator"
	@echo "============================================================"
	$(SIMULATOR_COMMAND) -t 52 -X 11.0592M $(SUGENO_EMBEDDED_OUTPUT)/$(SUGENO_EMBEDDED_BASENAME).ihx


debug-8051: embedded-mamdani
	@echo ""
	@echo "============================================================"
	@echo "Starting Mamdani 8051 source-level debugger"
	@echo "============================================================"
	mkdir -p $(MAMDANI_EMBEDDED_OUTPUT)/tools
	@if command -v s51 >/dev/null 2>&1; then \
		:; \
	elif command -v ucsim_51 >/dev/null 2>&1; then \
		ln -sf $$(command -v ucsim_51) $(MAMDANI_EMBEDDED_OUTPUT)/tools/s51; \
	else \
		echo "Error: no 8051 simulator was found."; \
		exit 1; \
	fi
	cp $(MAMDANI_EMBEDDED_SOURCE) $(MAMDANI_EMBEDDED_OUTPUT)/$(MAMDANI_EMBEDDED_BASENAME).c
	cp fuzzy.h $(MAMDANI_EMBEDDED_OUTPUT)/fuzzy.h
	cd $(MAMDANI_EMBEDDED_OUTPUT) && PATH="$$(pwd)/tools:$$PATH" $(SDCDB) -cpu 8052 $(MAMDANI_EMBEDDED_BASENAME)


# ============================================================
# SVG conversion
# ============================================================

define convert_svg
	@if [ ! -d "$(1)" ]; then \
		echo "No directory found: $(1)"; \
		exit 0; \
	fi; \
	found=0; \
	for input_file in $(1)/*.svg; do \
		[ -e "$$input_file" ] || continue; \
		found=1; \
		output_file="$${input_file%.svg}.$(2)"; \
		echo "[$(shell echo $(2) | tr a-z A-Z)] $$input_file -> $$output_file"; \
		if [ "$(2)" = "pdf" ]; then \
			$(SVG_CONVERTER) --format=pdf --output="$$output_file" "$$input_file"; \
		else \
			$(SVG_CONVERTER) --output="$$output_file" "$$input_file"; \
		fi; \
	done; \
	if [ "$$found" -eq 0 ]; then \
		echo "No SVG files found in $(1)"; \
	fi
endef


png: \
    png-strength \
    png-greenhouse \
    png-braking \
    png-braking-gpu \
    png-demo \
    png-sugeno \
    png-gpu \
    png-sim-8051 \
    png-fuzzy-neuron

pdf: \
    pdf-strength \
    pdf-greenhouse \
    pdf-braking \
    pdf-braking-gpu \
    pdf-demo \
    pdf-sugeno \
    pdf-gpu \
    pdf-sim-8051 \
    pdf-fuzzy-neuron


png-strength:
	$(call convert_svg,$(STRENGTH_OUTPUT),png)

png-greenhouse:
	$(call convert_svg,$(GREENHOUSE_OUTPUT),png)

png-braking:
	$(call convert_svg,$(BRAKING_OUTPUT),png)

png-braking-gpu:
	$(call convert_svg,$(BRAKING_GPU_OUTPUT),png)

png-demo:
	$(call convert_svg,$(DEMO_OUTPUT),png)

png-sugeno:
	$(call convert_svg,$(SUGENO_OUTPUT),png)

png-gpu:
	$(call convert_svg,$(GPU_OUTPUT),png)

png-sim-8051:
	$(call convert_svg,$(MAMDANI_8051_OUTPUT),png)

png-fuzzy-neuron:
	$(call convert_svg,$(FUZZY_NEURON_OUTPUT),png)


pdf-strength:
	$(call convert_svg,$(STRENGTH_OUTPUT),pdf)

pdf-greenhouse:
	$(call convert_svg,$(GREENHOUSE_OUTPUT),pdf)

pdf-braking:
	$(call convert_svg,$(BRAKING_OUTPUT),pdf)

pdf-braking-gpu:
	$(call convert_svg,$(BRAKING_GPU_OUTPUT),pdf)

pdf-demo:
	$(call convert_svg,$(DEMO_OUTPUT),pdf)

pdf-sugeno:
	$(call convert_svg,$(SUGENO_OUTPUT),pdf)

pdf-gpu:
	$(call convert_svg,$(GPU_OUTPUT),pdf)

pdf-sim-8051:
	$(call convert_svg,$(MAMDANI_8051_OUTPUT),pdf)

pdf-fuzzy-neuron:
	$(call convert_svg,$(FUZZY_NEURON_OUTPUT),pdf)


# ============================================================
# Cleanup
# ============================================================

clean: clean-desktop clean-embedded clean-fuzzy-neuron clean-esp32


clean-desktop:
	@echo ""
	@echo "============================================================"
	@echo "Cleaning desktop outputs"
	@echo "============================================================"
	rm -f $(STRENGTH_TARGET) \
	      $(GREENHOUSE_TARGET) \
	      $(BRAKING_TARGET) \
	      $(BRAKING_GPU_TARGET) \
	      $(DEMO_TARGET) \
	      $(SUGENO_TARGET) \
	      $(GPU_TARGET) \
	      $(MAMDANI_8051_TARGET) \
	      $(FUZZY_NEURON_TARGET) \
	      $(FUZZY_NEURON_PLUGIN)
	find $(STRENGTH_OUTPUT) $(GREENHOUSE_OUTPUT) $(BRAKING_OUTPUT) \
	     $(DEMO_OUTPUT) $(SUGENO_OUTPUT) $(GPU_OUTPUT) \
	     $(MAMDANI_8051_OUTPUT) $(FUZZY_NEURON_OUTPUT) \
	     -maxdepth 1 -type f \( -name '*.svg' -o -name '*.png' \
	     -o -name '*.pdf' -o -name '*.csv' \) -delete 2>/dev/null || true
	@echo "Desktop outputs removed."


clean-fuzzy-neuron:
	@echo ""
	@echo "============================================================"
	@echo "Cleaning fuzzy-neuron outputs"
	@echo "============================================================"
	rm -f $(FUZZY_NEURON_TARGET)
	rm -f $(FUZZY_NEURON_PLUGIN)
	rm -rf $(FUZZY_NEURON_OUTPUT)
	@echo "Fuzzy-neuron outputs removed."


clean-embedded: clean-embedded-mamdani clean-embedded-sugeno


clean-embedded-mamdani:
	@echo ""
	@echo "============================================================"
	@echo "Cleaning Mamdani embedded outputs"
	@echo "============================================================"
	rm -rf $(MAMDANI_EMBEDDED_OUTPUT)/* 2>/dev/null || true
	@echo "Mamdani embedded outputs removed."


clean-embedded-sugeno:
	@echo ""
	@echo "============================================================"
	@echo "Cleaning Sugeno embedded outputs"
	@echo "============================================================"
	rm -rf $(SUGENO_EMBEDDED_OUTPUT)/* 2>/dev/null || true
	@echo "Sugeno embedded outputs removed."


clean-esp32:
	@echo ""
	@echo "============================================================"
	@echo "Cleaning ESP32 outputs"
	@echo "============================================================"
	rm -rf $(ESP32_BUILD)
	@echo "ESP32 outputs removed."


# ============================================================
# Dependency checks
# ============================================================

check-dependencies:
	@echo ""
	@echo "============================================================"
	@echo "Checking dependencies"
	@echo "============================================================"
	@for cmd in gcc make bash sdcc packihx; do \
		if command -v $$cmd >/dev/null 2>&1; then \
			echo "[OK]       $$cmd"; \
		else \
			echo "[MISSING]  $$cmd"; \
		fi; \
	done

	@if printf '#include <CL/cl.h>\n' | $(CC) -E -x c - >/dev/null 2>&1; then \
		echo "[OK]       OpenCL headers"; \
	else \
		echo "[MISSING]  OpenCL headers"; \
	fi

	@if ldconfig -p 2>/dev/null | grep -q 'libOpenCL\.so'; then \
		echo "[OK]       OpenCL library"; \
	else \
		echo "[MISSING]  OpenCL library"; \
	fi

	@if printf '#include <dlfcn.h>\nint main(void){return 0;}\n' | \
	    $(CC) -x c - -ldl -o /tmp/fuzzy-dl-check >/dev/null 2>&1; then \
		echo "[OK]       dlopen/dlsym library"; \
		rm -f /tmp/fuzzy-dl-check; \
	else \
		echo "[MISSING]  dlopen/dlsym library"; \
	fi

	@echo ""
	@for cmd in ccache mold rsvg-convert sdcdb clinfo; do \
		if command -v $$cmd >/dev/null 2>&1; then \
			echo "[OK]       $$cmd"; \
		else \
			echo "[OPTIONAL] $$cmd"; \
		fi; \
	done

	@echo ""
	@echo "ESP32:"
	@$(MAKE) --no-print-directory check-esp32


# ============================================================
# Dependency installation
# ============================================================

install-dependencies:
	@echo ""
	@echo "============================================================"
	@echo "Installing project dependencies"
	@echo "============================================================"
	@if ! command -v apt-get >/dev/null 2>&1; then \
		echo "Error: automatic installation currently supports apt-based systems."; \
		exit 1; \
	fi
	sudo apt-get update
	sudo apt-get install -y build-essential gcc make ccache mold sdcc \
	    librsvg2-bin ocl-icd-opencl-dev opencl-headers clinfo

	@if ! command -v s51 >/dev/null 2>&1; then \
		if apt-cache show sdcc-ucsim >/dev/null 2>&1; then \
			sudo apt-get install -y sdcc-ucsim; \
		elif apt-cache show ucsim >/dev/null 2>&1; then \
			sudo apt-get install -y ucsim; \
		else \
			echo "Error: neither sdcc-ucsim nor ucsim is available."; \
			exit 1; \
		fi; \
	fi


# ============================================================
# Help
# ============================================================

help:
	@echo "fuzzy.h monolithic build system"
	@echo ""
	@echo "============================================================"
	@echo "Basic builds"
	@echo "============================================================"
	@echo "  make"
	@echo "      Build all desktop and embedded targets."
	@echo ""
	@echo "  make desktop"
	@echo "      Build all desktop targets, including fuzzy-neuron."
	@echo ""
	@echo "  make embedded"
	@echo "      Build Mamdani and Sugeno 8051 firmware."
	@echo ""
	@echo "============================================================"
	@echo "Fuzzy-neuron"
	@echo "============================================================"
	@echo "  make fuzzy-neuron"
	@echo "      Build the fuzzy-neuron CLI executable."
	@echo ""
	@echo "  make fuzzy_model_rules.so"
	@echo "      Build the fuzzy-neuron model plugin."
	@echo ""
	@echo "  make fuzzy-neuron fuzzy_model_rules.so"
	@echo "      Build both the CLI and model plugin without building 8051."
	@echo ""
	@echo "  make run-fuzzy-neuron"
	@echo "      Build and run the interactive fuzzy-neuron CLI."
	@echo ""
	@echo "  make train-fuzzy-neuron"
	@echo "      Build and run automated fuzzy-neuron training."
	@echo ""
	@echo "  make test-fuzzy-neuron"
	@echo "      Test one input vector using the configured values."
	@echo ""
	@echo "  make test-fuzzy-neuron-csv"
	@echo "      Test the trained model against a CSV dataset."
	@echo ""
	@echo "  make compare-fuzzy-neuron"
	@echo "      Compare fuzzy-neuron predictions with the original system."
	@echo ""
	@echo "  make plots-fuzzy-neuron"
	@echo "      Train and generate fuzzy-neuron output plots."
	@echo ""
	@echo "  make time-fuzzy-neuron-train"
	@echo "      Time fuzzy-neuron model training."
	@echo ""
	@echo "  make time-fuzzy-neuron-test"
	@echo "      Time fuzzy-neuron inference."
	@echo ""
	@echo "  make clean-fuzzy-neuron"
	@echo "      Remove the CLI, model plugin, and fuzzy-neuron outputs."
	@echo ""
	@echo "Fuzzy-neuron configuration overrides:"
	@echo ""
	@echo "  make time-fuzzy-neuron-train \\"
	@echo "      FUZZY_NEURON_EPOCHS=10000 \\"
	@echo "      FUZZY_NEURON_BATCH_SIZE=4096 \\"
	@echo "      FUZZY_NEURON_LEARNING_RATE=0.005 \\"
	@echo "      FUZZY_NEURON_REPORT_INTERVAL=25"
	@echo ""
	@echo "  make test-fuzzy-neuron \\"
	@echo "      FUZZY_NEURON_TEMPERATURE=50 \\"
	@echo "      FUZZY_NEURON_LOAD=50 \\"
	@echo "      FUZZY_NEURON_VIBRATION=5"
	@echo ""
	@echo "  make test-fuzzy-neuron-csv \\"
	@echo "      FUZZY_NEURON_TEST_DATASET=fuzzy-neuron-test.csv"
	@echo ""
	@echo "Fuzzy-neuron files:"
	@echo "  Source:        $(FUZZY_NEURON_SOURCE)"
	@echo "  Kernel:        $(FUZZY_NEURON_KERNEL)"
	@echo "  CLI:           $(FUZZY_NEURON_TARGET)"
	@echo "  Plugin:        $(FUZZY_NEURON_PLUGIN)"
	@echo "  Output:        $(FUZZY_NEURON_OUTPUT)"
	@echo "  Model:         $(FUZZY_NEURON_MODEL)"
	@echo "  Test output:   $(FUZZY_NEURON_TEST_OUTPUT)"
	@echo "  Original data: $(FUZZY_NEURON_ORIGINAL_OUTPUT)"
	@echo "  Dataset:       $(FUZZY_NEURON_DATASET)"
	@echo ""
	@echo "============================================================"
	@echo "Desktop examples"
	@echo "============================================================"
	@echo "  make run-strength"
	@echo "      Build and run the paint-strength example."
	@echo ""
	@echo "  make run-greenhouse"
	@echo "      Build and run the greenhouse example."
	@echo ""
	@echo "  make run-braking"
	@echo "      Build and run the CPU braking demonstration."
	@echo ""
	@echo "  make run-braking-gpu"
	@echo "      Build and run the OpenCL braking demonstration."
	@echo ""
	@echo "  make run-demo"
	@echo "      Build and run the complete CPU demonstration."
	@echo ""
	@echo "  make run-sugeno"
	@echo "      Build and run the Sugeno controller demonstration."
	@echo ""
	@echo "  make run-gpu"
	@echo "      Build and run the complete OpenCL demonstration."
	@echo ""
	@echo "  make run-sim-8051"
	@echo "      Run the desktop Mamdani 8051 simulation harness."
	@echo ""
	@echo "============================================================"
	@echo "Timing"
	@echo "============================================================"
	@echo "  make time-braking"
	@echo "      Time the CPU braking demonstration."
	@echo ""
	@echo "  make time-braking-gpu"
	@echo "      Time the OpenCL braking demonstration."
	@echo ""
	@echo "  make time-demo"
	@echo "      Time the complete CPU demonstration."
	@echo ""
	@echo "  make time-gpu"
	@echo "      Time the complete OpenCL demonstration."
	@echo ""
	@echo "============================================================"
	@echo "8051"
	@echo "============================================================"
	@echo "  make embedded-mamdani"
	@echo "      Build Mamdani AT89S52 firmware."
	@echo ""
	@echo "  make build-8051"
	@echo "      Alias for embedded-mamdani."
	@echo ""
	@echo "  make embedded-sugeno"
	@echo "      Build Sugeno AT89S52 firmware."
	@echo ""
	@echo "  make build-sugeno-8051"
	@echo "      Alias for embedded-sugeno."
	@echo ""
	@echo "  make simulate-8051"
	@echo "      Build and simulate Mamdani firmware."
	@echo ""
	@echo "  make simulate-sugeno"
	@echo "      Build and simulate Sugeno firmware."
	@echo ""
	@echo "  make debug-8051"
	@echo "      Start the Mamdani source-level debugger."
	@echo ""
	@echo "============================================================"
	@echo "ESP32-S3"
	@echo "============================================================"
	@echo "  make esp32"
	@echo "      Build the ESP32 ELF and binary."
	@echo ""
	@echo "  make esp32-build"
	@echo "      Build only the ESP32 ELF."
	@echo ""
	@echo "  make esp32-bin"
	@echo "      Convert the ESP32 ELF to a binary."
	@echo ""
	@echo "  make run-esp32"
	@echo "      Build and run the ESP32 firmware."
	@echo ""
	@echo "  make check-esp32"
	@echo "      Check the ESP32 compiler, objcopy, size tool, and simulator."
	@echo ""
	@echo "  make clean-esp32"
	@echo "      Remove ESP32 build outputs."
	@echo ""
	@echo "============================================================"
	@echo "Plots and document conversion"
	@echo "============================================================"
	@echo "  make png"
	@echo "      Convert all generated SVG files to PNG."
	@echo ""
	@echo "  make pdf"
	@echo "      Convert all generated SVG files to PDF."
	@echo ""
	@echo "  make png-strength"
	@echo "  make png-greenhouse"
	@echo "  make png-braking"
	@echo "  make png-braking-gpu"
	@echo "  make png-demo"
	@echo "  make png-sugeno"
	@echo "  make png-gpu"
	@echo "  make png-sim-8051"
	@echo "  make png-fuzzy-neuron"
	@echo ""
	@echo "  make pdf-strength"
	@echo "  make pdf-greenhouse"
	@echo "  make pdf-braking"
	@echo "  make pdf-braking-gpu"
	@echo "  make pdf-demo"
	@echo "  make pdf-sugeno"
	@echo "  make pdf-gpu"
	@echo "  make pdf-sim-8051"
	@echo "  make pdf-fuzzy-neuron"
	@echo ""
	@echo "============================================================"
	@echo "Dependencies"
	@echo "============================================================"
	@echo "  make check-dependencies"
	@echo "      Check desktop, OpenCL, 8051, plotting, and ESP32 tools."
	@echo ""
	@echo "  make install-dependencies"
	@echo "      Install supported dependencies on an apt-based system."
	@echo ""
	@echo "============================================================"
	@echo "Cleanup"
	@echo "============================================================"
	@echo "  make clean"
	@echo "      Remove desktop, embedded, fuzzy-neuron, and ESP32 outputs."
	@echo ""
	@echo "  make clean-desktop"
	@echo "      Remove desktop executables and generated outputs."
	@echo ""
	@echo "  make clean-embedded"
	@echo "      Remove Mamdani and Sugeno 8051 outputs."
	@echo ""
	@echo "  make clean-embedded-mamdani"
	@echo "      Remove Mamdani 8051 outputs."
	@echo ""
	@echo "  make clean-embedded-sugeno"
	@echo "      Remove Sugeno 8051 outputs."
	@echo ""
	@echo "  make clean-fuzzy-neuron"
	@echo "      Remove fuzzy-neuron executable, plugin, and outputs."
	@echo ""
	@echo "  make clean-esp32"
	@echo "      Remove ESP32 build outputs."