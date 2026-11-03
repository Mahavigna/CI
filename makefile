# ============================================================
# Desktop compiler configuration
# ============================================================

CC ?= gcc
CFLAGS := -O3 -Wall -Wextra -Wpedantic -std=c11
LDFLAGS :=
LDLIBS := -lm

GPU_CFLAGS := \
    -DFUZZY_OPENCL \
    -Wno-overlength-strings \
    -Wno-unused-function

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
    pdf \
    pdf-strength \
    pdf-greenhouse \
    pdf-braking \
    pdf-braking-gpu \
    pdf-demo \
    pdf-sugeno \
    pdf-gpu \
    pdf-sim-8051 \
    clean \
    clean-desktop \
    clean-embedded \
    clean-embedded-mamdani \
    clean-embedded-sugeno \
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
    $(MAMDANI_8051_TARGET)

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
$(SUGENO_EMBEDDED_OUTPUT):
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
	$(CC_CMD) \
	    $(CFLAGS) \
	    $(GPU_CFLAGS) \
	    $< \
	    $(LDFLAGS) \
	    -o $@ \
	    $(GPU_LDLIBS) \
	    $(LDLIBS)
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
	$(CC_CMD) \
	    $(CFLAGS) \
	    $(GPU_CFLAGS) \
	    $< \
	    $(LDFLAGS) \
	    -o $@ \
	    $(GPU_LDLIBS) \
	    $(LDLIBS)
	@echo "[OK] Built $@"


$(MAMDANI_8051_TARGET): $(MAMDANI_8051_SOURCE) fuzzy.h | $(MAMDANI_8051_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Building $@ from $<..."
	@echo "Desktop simulation mode: -DSIMULATION"
	@echo "============================================================"
	$(CC_CMD) $(CFLAGS) -DSIMULATION $< $(LDFLAGS) -o $@ $(LDLIBS)
	@echo "[OK] Built $@"


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

embedded-mamdani build-8051: \
    $(MAMDANI_EMBEDDED_SOURCE) fuzzy.h | $(MAMDANI_EMBEDDED_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Building Mamdani AT89S52 firmware with SDCC"
	@echo "============================================================"
	@rm -f $(MAMDANI_EMBEDDED_OUTPUT)/$(MAMDANI_EMBEDDED_BASENAME).*
	cd $(MAMDANI_EMBEDDED_OUTPUT) && \
	    $(SDCC) \
	    -mmcs51 \
	    --model-small \
	    --opt-code-size \
		--stack-auto \
	    --debug \
	    --iram-size 256 \
	    -I../.. \
	    -o $(MAMDANI_EMBEDDED_BASENAME).ihx \
	    ../../$(MAMDANI_EMBEDDED_SOURCE)
	cd $(MAMDANI_EMBEDDED_OUTPUT) && \
	    $(PACKIHX) \
	    $(MAMDANI_EMBEDDED_BASENAME).ihx \
	    > $(MAMDANI_EMBEDDED_BASENAME).hex
	@echo ""
	@echo "Generated Mamdani firmware:"
	@echo "  $(MAMDANI_EMBEDDED_OUTPUT)/$(MAMDANI_EMBEDDED_BASENAME).ihx"
	@echo "  $(MAMDANI_EMBEDDED_OUTPUT)/$(MAMDANI_EMBEDDED_BASENAME).hex"


embedded-sugeno build-sugeno-8051: \
    $(SUGENO_SOURCE) fuzzy.h | $(SUGENO_EMBEDDED_OUTPUT)
	@echo ""
	@echo "============================================================"
	@echo "Building Sugeno AT89S52 firmware with SDCC"
	@echo "============================================================"
	@rm -f $(SUGENO_EMBEDDED_OUTPUT)/$(SUGENO_EMBEDDED_BASENAME).*
	cd $(SUGENO_EMBEDDED_OUTPUT) && \
	    $(SDCC) \
	    -mmcs51 \
	    --model-small \
	    --opt-code-size \
	    --debug \
	    --stack-auto \
	    --iram-size 256 \
	    --stack-loc 0x80 \
	    -I../.. \
	    -o $(SUGENO_EMBEDDED_BASENAME).ihx \
	    ../../$(SUGENO_SOURCE)
	cd $(SUGENO_EMBEDDED_OUTPUT) && \
	    $(PACKIHX) \
	    $(SUGENO_EMBEDDED_BASENAME).ihx \
	    > $(SUGENO_EMBEDDED_BASENAME).hex
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
	$(SIMULATOR_COMMAND) \
	    -t 52 \
	    -X 11.0592M \
	    $(MAMDANI_EMBEDDED_OUTPUT)/$(MAMDANI_EMBEDDED_BASENAME).ihx


simulate-sugeno: embedded-sugeno
	@if [ -z "$(SIMULATOR_COMMAND)" ]; then \
	    echo "Error: no 8051 simulator was found."; \
	    exit 1; \
	fi
	@echo ""
	@echo "============================================================"
	@echo "Starting Sugeno 8051 simulator"
	@echo "============================================================"
	$(SIMULATOR_COMMAND) \
	    -t 52 \
	    -X 11.0592M \
	    $(SUGENO_EMBEDDED_OUTPUT)/$(SUGENO_EMBEDDED_BASENAME).ihx


debug-8051: embedded-mamdani
	@echo ""
	@echo "============================================================"
	@echo "Starting Mamdani 8051 source-level debugger"
	@echo "============================================================"
	mkdir -p $(MAMDANI_EMBEDDED_OUTPUT)/tools
	@if command -v s51 >/dev/null 2>&1; then \
	    :; \
	elif command -v ucsim_51 >/dev/null 2>&1; then \
	    ln -sf \
	        $$(command -v ucsim_51) \
	        $(MAMDANI_EMBEDDED_OUTPUT)/tools/s51; \
	else \
	    echo "Error: no 8051 simulator was found."; \
	    exit 1; \
	fi
	cp \
	    $(MAMDANI_EMBEDDED_SOURCE) \
	    $(MAMDANI_EMBEDDED_OUTPUT)/$(MAMDANI_EMBEDDED_BASENAME).c
	cp fuzzy.h $(MAMDANI_EMBEDDED_OUTPUT)/fuzzy.h
	cd $(MAMDANI_EMBEDDED_OUTPUT) && \
	    PATH="$$(pwd)/tools:$$PATH" \
	    $(SDCDB) \
	    -cpu 8052 \
	    $(MAMDANI_EMBEDDED_BASENAME)


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
	        $(SVG_CONVERTER) \
	            --format=pdf \
	            --output="$$output_file" \
	            "$$input_file"; \
	    else \
	        $(SVG_CONVERTER) \
	            --output="$$output_file" \
	            "$$input_file"; \
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
    png-sim-8051

pdf: \
    pdf-strength \
    pdf-greenhouse \
    pdf-braking \
    pdf-braking-gpu \
    pdf-demo \
    pdf-sugeno \
    pdf-gpu \
    pdf-sim-8051


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


# ============================================================
# Cleanup
# ============================================================

clean: clean-desktop clean-embedded


clean-desktop:
	@echo ""
	@echo "============================================================"
	@echo "Cleaning desktop outputs"
	@echo "============================================================"
	rm -f \
	    $(STRENGTH_TARGET) \
	    $(GREENHOUSE_TARGET) \
	    $(BRAKING_TARGET) \
	    $(BRAKING_GPU_TARGET) \
	    $(DEMO_TARGET) \
	    $(SUGENO_TARGET) \
	    $(GPU_TARGET) \
	    $(MAMDANI_8051_TARGET)
	rm -f \
	    $(SIM_8051_ROOT)/test-8051-host \
	    $(SIM_8051_ROOT)/test_8051_host.i
	find \
	    $(STRENGTH_OUTPUT) \
	    $(GREENHOUSE_OUTPUT) \
	    $(BRAKING_OUTPUT) \
	    $(BRAKING_GPU_OUTPUT) \
	    $(DEMO_OUTPUT) \
	    $(SUGENO_OUTPUT) \
	    $(GPU_OUTPUT) \
	    $(MAMDANI_8051_OUTPUT) \
	    -maxdepth 1 \
	    -type f \
	    \( \
	        -name '*.svg' -o \
	        -name '*.png' -o \
	        -name '*.pdf' -o \
	        -name '*.csv' \
	    \) \
	    -delete 2>/dev/null || true
	@echo "Desktop outputs removed."


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
	@if printf '#include <CL/cl.h>\n' | \
	    $(CC) -E -x c - >/dev/null 2>&1; then \
	    echo "[OK]       OpenCL headers"; \
	else \
	    echo "[MISSING]  OpenCL headers"; \
	fi
	@if ldconfig -p 2>/dev/null | grep -q 'libOpenCL\.so'; then \
	    echo "[OK]       OpenCL library"; \
	else \
	    echo "[MISSING]  OpenCL library"; \
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
	sudo apt-get install -y \
	    build-essential \
	    gcc \
	    make \
	    ccache \
	    mold \
	    sdcc \
	    librsvg2-bin \
	    ocl-icd-opencl-dev \
	    opencl-headers \
	    clinfo
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
	@echo "  make                     Build desktop programs and both firmware images."
	@echo "  make desktop             Build all desktop programs."
	@echo "  make embedded            Build Mamdani and Sugeno 8051 firmware."
	@echo ""
	@echo "Desktop examples:"
	@echo "  make run-strength"
	@echo "  make run-greenhouse"
	@echo "  make run-braking"
	@echo "  make run-braking-gpu"
	@echo "  make run-demo"
	@echo "  make run-sugeno"
	@echo "  make run-gpu"
	@echo "  make run-sim-8051"
	@echo ""
	@echo "Braking commands:"
	@echo "  make braking-app         Build the CPU braking demonstration."
	@echo "  make braking-gpu         Build the OpenCL GPU braking demonstration."
	@echo "  make run-braking         Build and run the CPU braking demonstration."
	@echo "  make run-braking-gpu     Build and run the GPU braking demonstration."
	@echo "  make time-braking        Build and time the CPU braking demonstration."
	@echo "  make time-braking-gpu    Build and time the GPU braking demonstration."
	@echo "  make png-braking         Convert CPU braking SVG outputs to PNG."
	@echo "  make png-braking-gpu     Convert GPU braking SVG outputs to PNG."
	@echo "  make pdf-braking         Convert CPU braking SVG outputs to PDF."
	@echo "  make pdf-braking-gpu     Convert GPU braking SVG outputs to PDF."
	@echo ""
	@echo "GPU commands:"
	@echo "  make demo-all-gpu        Build the complete OpenCL GPU demonstration."
	@echo "  make run-gpu             Build and run the complete OpenCL GPU demonstration."
	@echo "  make time-gpu            Build and time the complete OpenCL GPU demonstration."
	@echo "  make png-gpu             Convert GPU SVG outputs to PNG."
	@echo "  make pdf-gpu             Convert GPU SVG outputs to PDF."
	@echo ""
	@echo "Benchmark commands:"
	@echo "  make time-braking        Build and time the CPU braking demonstration."
	@echo "  make time-braking-gpu    Build and time the GPU braking demonstration."
	@echo "  make time-demo           Build and time the CPU demonstration."
	@echo "  make time-gpu            Build and time the GPU demonstration."
	@echo ""
	@echo "GPU demonstration includes:"
	@echo "  OpenCL COG sweep."
	@echo "  OpenCL sampled-membership interpolation sweep."
	@echo "  Five-dimensional Cartesian input generation."
	@echo "  CSV and interactive SVG generation."
	@echo ""
	@echo "GPU braking demonstration includes:"
	@echo "  GPU and CPU output comparison."
	@echo "  Multiple hedge values including extreme dilation and concentration."
	@echo "  OpenCL fuzzy-controller execution."
	@echo "  CSV and interactive SVG generation."
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
	@echo "  make pdf-strength"
	@echo "  make pdf-greenhouse"
	@echo "  make pdf-braking"
	@echo "  make pdf-braking-gpu"
	@echo "  make pdf-demo"
	@echo "  make pdf-sugeno"
	@echo "  make pdf-gpu"
	@echo "  make pdf-sim-8051"
	@echo ""
	@echo "Cleanup:"
	@echo "  make clean"
	@echo "  make clean-desktop"
	@echo "  make clean-embedded"
	@echo "  make clean-embedded-mamdani"
	@echo "  make clean-embedded-sugeno"