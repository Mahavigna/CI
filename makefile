# ============================================================
# Desktop compiler configuration
# ============================================================

CC ?= gcc
CFLAGS := -O3 -Wall -Wextra -Wpedantic -std=c11
LDFLAGS :=
LDLIBS := -lm

GPU_CFLAGS := -DFUZZY_OPENCL -Wno-overlength-strings -Wno-unused-function
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

FUZZY_NEURON_EPOCHS ?= 1000000
FUZZY_NEURON_BATCH_SIZE ?= 10000
FUZZY_NEURON_LEARNING_RATE ?= 0.001
FUZZY_NEURON_REPORT_INTERVAL ?= 1000

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
# Main targets
# ============================================================

.PHONY: \
    all \
    desktop \
    embedded \
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
$(FUZZY_NEURON_OUTPUT):
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
	@echo "Source: $(FUZZY_NEURON_SOURCE)"
	@echo "Output: $(FUZZY_NEURON_TARGET)"
	@echo "============================================================"
	$(CC_CMD) $(CFLAGS) $(GPU_CFLAGS) -rdynamic $(FUZZY_NEURON_SOURCE) $(LDFLAGS) -o $(FUZZY_NEURON_TARGET) $(GPU_LDLIBS) -ldl $(LDLIBS)
	@echo "[OK] Built $(FUZZY_NEURON_TARGET)"


# ============================================================
# Desktop execution
# ============================================================

run-strength: $(STRENGTH_TARGET) | $(STRENGTH_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Running paint-strength example"
	@echo "============================================================"
	./$(STRENGTH_TARGET)


run-greenhouse: $(GREENHOUSE_TARGET) | $(GREENHOUSE_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Running greenhouse example"
	@echo "============================================================"
	./$(GREENHOUSE_TARGET)


run-braking: $(BRAKING_TARGET) | $(BRAKING_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Running CPU braking demonstration"
	@echo "============================================================"
	./$(BRAKING_TARGET)


run-braking-gpu: $(BRAKING_GPU_TARGET) | $(BRAKING_GPU_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Running OpenCL GPU braking demonstration"
	@echo "GPU/CPU comparison and hedge-extreme tests enabled"
	@echo "============================================================"
	./$(BRAKING_GPU_TARGET)


run-demo: $(DEMO_TARGET) | $(DEMO_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Running complete CPU fuzzy.h demonstration"
	@echo "============================================================"
	./$(DEMO_TARGET)


run-sugeno: $(SUGENO_TARGET) | $(SUGENO_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Running complex Sugeno controller demonstration"
	@echo "============================================================"
	cd $(SUGENO_OUTPUT) && ../$(SUGENO_TARGET)


run-gpu: $(GPU_TARGET) | $(GPU_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Running complete OpenCL fuzzy.h demonstration"
	@echo "GPU interpolation sweep enabled"
	@echo "GPU COG sweep enabled"
	@echo "============================================================"
	./$(GPU_TARGET)


run-fuzzy-neuron: $(FUZZY_NEURON_TARGET) $(FUZZY_NEURON_PLUGIN) | $(FUZZY_NEURON_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Running interactive fuzzy-neuron CLI"
	@echo "============================================================"
	./$(FUZZY_NEURON_TARGET)


train-fuzzy-neuron: $(FUZZY_NEURON_TARGET) $(FUZZY_NEURON_PLUGIN) | $(FUZZY_NEURON_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Training fuzzy-neuron model"
	@echo "Plugin:  $(FUZZY_NEURON_PLUGIN)"
	@echo "Dataset: $(FUZZY_NEURON_DATASET)"
	@echo "Model:   $(FUZZY_NEURON_MODEL)"
	@echo "Kernel:  $(FUZZY_NEURON_KERNEL)"
	@echo "============================================================"
	printf '1\n5\n' | ./$(FUZZY_NEURON_TARGET)


test-fuzzy-neuron: $(FUZZY_NEURON_TARGET) $(FUZZY_NEURON_PLUGIN) | $(FUZZY_NEURON_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Testing one input with the trained fuzzy-neuron model"
	@echo "Model:       $(FUZZY_NEURON_MODEL)"
	@echo "Temperature: $(FUZZY_NEURON_TEMPERATURE)"
	@echo "Load:        $(FUZZY_NEURON_LOAD)"
	@echo "Vibration:   $(FUZZY_NEURON_VIBRATION)"
	@echo "============================================================"
	printf '2\n$(FUZZY_NEURON_TEMPERATURE) $(FUZZY_NEURON_LOAD) $(FUZZY_NEURON_VIBRATION)\n5\n' | ./$(FUZZY_NEURON_TARGET)


test-fuzzy-neuron-csv: $(FUZZY_NEURON_TARGET) $(FUZZY_NEURON_PLUGIN) | $(FUZZY_NEURON_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Testing trained fuzzy-neuron model against a new CSV dataset"
	@echo "Model:       $(FUZZY_NEURON_MODEL)"
	@echo "Test dataset: $(FUZZY_NEURON_TEST_DATASET)"
	@echo "Predictions: $(FUZZY_NEURON_TEST_OUTPUT)"
	@echo "============================================================"
	printf '3\n$(FUZZY_NEURON_TEST_DATASET)\n5\n' | ./$(FUZZY_NEURON_TARGET)


compare-fuzzy-neuron: $(FUZZY_NEURON_TARGET) $(FUZZY_NEURON_PLUGIN) | $(FUZZY_NEURON_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Comparing trained fuzzy-neuron model against original dataset"
	@echo "Model:       $(FUZZY_NEURON_MODEL)"
	@echo "Dataset:     $(FUZZY_NEURON_DATASET)"
	@echo "Predictions: $(FUZZY_NEURON_ORIGINAL_OUTPUT)"
	@echo "============================================================"
	printf '4\n5\n' | ./$(FUZZY_NEURON_TARGET)


plots-fuzzy-neuron: train-fuzzy-neuron | $(FUZZY_NEURON_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Fuzzy-neuron plots"
	@echo "============================================================"
	@echo "  $(FUZZY_NEURON_OUTPUT)/fuzzy_neuron_temperature_memberships.svg"
	@echo "  $(FUZZY_NEURON_OUTPUT)/fuzzy_neuron_load_memberships.svg"
	@echo "  $(FUZZY_NEURON_OUTPUT)/fuzzy_neuron_vibration_memberships.svg"
	@echo "  $(FUZZY_NEURON_OUTPUT)/fuzzy_neuron_learned_surface.csv"
	@echo "  $(FUZZY_NEURON_OUTPUT)/fuzzy_neuron_learned_surface.svg"


time-fuzzy-neuron-train: $(FUZZY_NEURON_TARGET) $(FUZZY_NEURON_PLUGIN) | $(FUZZY_NEURON_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Timing OpenCL GPU fuzzy-neuron training"
	@echo "Epochs:          $(FUZZY_NEURON_EPOCHS)"
	@echo "Batch size:      $(FUZZY_NEURON_BATCH_SIZE)"
	@echo "Learning rate:   $(FUZZY_NEURON_LEARNING_RATE)"
	@echo "Report interval: $(FUZZY_NEURON_REPORT_INTERVAL)"
	@echo "============================================================"
	time sh -c "printf '1\n$(FUZZY_NEURON_EPOCHS)\n$(FUZZY_NEURON_BATCH_SIZE)\n$(FUZZY_NEURON_LEARNING_RATE)\n$(FUZZY_NEURON_REPORT_INTERVAL)\n5\n' | ./$(FUZZY_NEURON_TARGET)"


time-fuzzy-neuron-test: $(FUZZY_NEURON_TARGET) $(FUZZY_NEURON_PLUGIN) | $(FUZZY_NEURON_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Timing fuzzy-neuron model loading and inference"
	@echo "============================================================"
	time sh -c "printf '2\n$(FUZZY_NEURON_TEMPERATURE) $(FUZZY_NEURON_LOAD) $(FUZZY_NEURON_VIBRATION)\n5\n' | ./$(FUZZY_NEURON_TARGET)"


time-braking: $(BRAKING_TARGET) | $(BRAKING_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Timing CPU braking demonstration"
	@echo "============================================================"
	time ./$(BRAKING_TARGET)


time-braking-gpu: $(BRAKING_GPU_TARGET) | $(BRAKING_GPU_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Timing OpenCL GPU braking demonstration"
	@echo "============================================================"
	time ./$(BRAKING_GPU_TARGET)


time-demo: $(DEMO_TARGET) | $(DEMO_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Timing complete CPU fuzzy.h demonstration"
	@echo "============================================================"
	time ./$(DEMO_TARGET)


time-gpu: $(GPU_TARGET) | $(GPU_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Timing complete OpenCL fuzzy.h demonstration"
	@echo "============================================================"
	time ./$(GPU_TARGET)


run-sim-8051: $(MAMDANI_8051_TARGET) | $(MAMDANI_8051_OUTPUT)
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

clean: clean-desktop clean-embedded clean-fuzzy-neuron


clean-desktop:
	@echo ""
	@echo "============================================================"
	@echo "Cleaning desktop outputs"
	@echo "============================================================"
	rm -f $(STRENGTH_TARGET) $(GREENHOUSE_TARGET) $(BRAKING_TARGET) $(BRAKING_GPU_TARGET) $(DEMO_TARGET) $(SUGENO_TARGET) $(GPU_TARGET) $(MAMDANI_8051_TARGET) $(FUZZY_NEURON_TARGET) $(FUZZY_NEURON_PLUGIN)
	rm -f $(SIM_8051_ROOT)/test-8051-host $(SIM_8051_ROOT)/test_8051_host.i
	find $(STRENGTH_OUTPUT) $(GREENHOUSE_OUTPUT) $(BRAKING_OUTPUT) $(BRAKING_GPU_OUTPUT) $(DEMO_OUTPUT) $(SUGENO_OUTPUT) $(GPU_OUTPUT) $(MAMDANI_8051_OUTPUT) $(FUZZY_NEURON_OUTPUT) -maxdepth 1 -type f \( -name '*.svg' -o -name '*.png' -o -name '*.pdf' -o -name '*.csv' \) -delete 2>/dev/null || true
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
	@if printf '#include <dlfcn.h>\nint main(void){return 0;}\n' | $(CC) -x c - -ldl -o /tmp/fuzzy-dl-check >/dev/null 2>&1; then \
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
	sudo apt-get install -y build-essential gcc make ccache mold sdcc librsvg2-bin ocl-icd-opencl-dev opencl-headers clinfo
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
	@echo "Basic commands:"
	@echo "  make"
	@echo "  make desktop"
	@echo "  make embedded"
	@echo ""
	@echo "Desktop examples:"
	@echo "  make run-strength"
	@echo "  make run-greenhouse"
	@echo "  make run-braking"
	@echo "  make run-braking-gpu"
	@echo "  make run-demo"
	@echo "  make run-sugeno"
	@echo "  make run-gpu"
	@echo "  make run-fuzzy-neuron"
	@echo "  make run-sim-8051"
	@echo ""
	@echo "Fuzzy-neuron commands:"
	@echo "  make fuzzy-neuron"
	@echo "      Build the interactive training, prediction, and dataset-testing CLI."
	@echo "  make fuzzy_model_rules.so"
	@echo "      Build the dynamically loaded fuzzy-rule model plugin."
	@echo "  make run-fuzzy-neuron"
	@echo "      Open the interactive fuzzy-neuron CLI menu."
	@echo "  make train-fuzzy-neuron"
	@echo "      Select menu option 1, train the model, and save outputs under fuzzy-neuron-output."
	@echo "  make test-fuzzy-neuron"
	@echo "      Select menu option 2 and test one temperature/load/vibration input."
	@echo "  make test-fuzzy-neuron-csv FUZZY_NEURON_TEST_DATASET=path.csv"
	@echo "      Select menu option 3 and test the trained model against a new CSV dataset."
	@echo "  make compare-fuzzy-neuron"
	@echo "      Select menu option 4 and test the trained model against the original dataset."
	@echo "  make plots-fuzzy-neuron"
	@echo "      Train the model and list generated plots under fuzzy-neuron-output."
	@echo "  make time-fuzzy-neuron-train"
	@echo "      Time menu option 1 training."
	@echo "  make time-fuzzy-neuron-test"
	@echo "      Time menu option 2 model loading and inference."
	@echo "  make png-fuzzy-neuron"
	@echo "      Convert fuzzy-neuron SVG files to PNG."
	@echo "  make pdf-fuzzy-neuron"
	@echo "      Convert fuzzy-neuron SVG files to PDF."
	@echo "  make clean-fuzzy-neuron"
	@echo "      Remove the fuzzy-neuron CLI, plugin, model, predictions, plots, and output directory."
	@echo ""
	@echo "Custom fuzzy-neuron test input:"
	@echo "  make test-fuzzy-neuron FUZZY_NEURON_TEMPERATURE=60 FUZZY_NEURON_LOAD=75 FUZZY_NEURON_VIBRATION=4"
	@echo ""
	@echo "Braking commands:"
	@echo "  make braking-app"
	@echo "  make braking-gpu"
	@echo "  make run-braking"
	@echo "  make run-braking-gpu"
	@echo "  make time-braking"
	@echo "  make time-braking-gpu"
	@echo "  make png-braking"
	@echo "  make png-braking-gpu"
	@echo "  make pdf-braking"
	@echo "  make pdf-braking-gpu"
	@echo ""
	@echo "GPU commands:"
	@echo "  make demo-all-gpu"
	@echo "  make run-gpu"
	@echo "  make time-gpu"
	@echo "  make png-gpu"
	@echo "  make pdf-gpu"
	@echo ""
	@echo "Mamdani 8051 commands:"
	@echo "  make embedded-mamdani"
	@echo "  make build-8051"
	@echo "  make simulate-8051"
	@echo "  make debug-8051"
	@echo ""
	@echo "Sugeno 8051 commands:"
	@echo "  make embedded-sugeno"
	@echo "  make build-sugeno-8051"
	@echo "  make simulate-sugeno"
	@echo ""
	@echo "Dependency commands:"
	@echo "  make check-dependencies"
	@echo "  make install-dependencies"
	@echo ""
	@echo "Image conversion:"
	@echo "  make png"
	@echo "  make pdf"
	@echo "  make png-strength"
	@echo "  make png-greenhouse"
	@echo "  make png-braking"
	@echo "  make png-braking-gpu"
	@echo "  make png-demo"
	@echo "  make png-sugeno"
	@echo "  make png-gpu"
	@echo "  make png-sim-8051"
	@echo "  make png-fuzzy-neuron"
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
	@echo "Cleanup:"
	@echo "  make clean"
	@echo "  make clean-desktop"
	@echo "  make clean-fuzzy-neuron"
	@echo "  make clean-embedded"
	@echo "  make clean-embedded-mamdani"
	@echo "  make clean-embedded-sugeno"