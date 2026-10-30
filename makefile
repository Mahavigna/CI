# ============================================================
# Desktop compiler configuration
# ============================================================
CC ?= gcc
CFLAGS := -O3 -Wall -Wextra -Wpedantic -std=c11
LDFLAGS :=
LDLIBS := -lm

# Optional desktop acceleration tools
ifneq (,$(shell command -v ccache 2>/dev/null))
    CC_CMD := ccache $(CC)
else
    CC_CMD := $(CC)
endif

ifneq (,$(shell command -v mold 2>/dev/null))
    LDFLAGS += -fuse-ld=mold
endif

# ============================================================
# Targets and Directories
# ============================================================

STRENGTH_TARGET := strength-app
STRENGTH_SOURCE := strength.c
STRENGTH_OUTPUT := strength

GREENHOUSE_TARGET := greenhouse-app
GREENHOUSE_SOURCE := greenhouse.c
GREENHOUSE_OUTPUT := greenhouse

DEMO_TARGET := fuzzy-demo
DEMO_SOURCE := demo_all.c
DEMO_OUTPUT := demo-all

SUGENO_TARGET := sugeno-app
SUGENO_SOURCE := sugeno_demo.c
SUGENO_OUTPUT := sugeno

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

.PHONY: all desktop embedded test \
    run-strength run-greenhouse run-demo run-sugeno run-sim-8051 \
    embedded-mamdani embedded-sugeno \
    build-8051 build-sugeno-8051 \
    simulate-8051 simulate-sugeno \
    debug-8051 test-8051 \
    check-dependencies install-dependencies \
    png png-strength png-greenhouse png-demo png-sugeno png-sim-8051 \
    pdf pdf-strength pdf-greenhouse pdf-demo pdf-sugeno pdf-sim-8051 \
    clean clean-desktop clean-embedded clean-embedded-mamdani \
    clean-embedded-sugeno help

all: desktop embedded

desktop: \
    $(STRENGTH_TARGET) \
    $(GREENHOUSE_TARGET) \
    $(DEMO_TARGET) \
    $(SUGENO_TARGET) \
    $(MAMDANI_8051_TARGET)

embedded: embedded-mamdani embedded-sugeno



# Directory creation
$(STRENGTH_OUTPUT) \
$(GREENHOUSE_OUTPUT) \
$(DEMO_OUTPUT) \
$(SUGENO_OUTPUT) \
$(MAMDANI_8051_OUTPUT) \
$(MAMDANI_EMBEDDED_OUTPUT) \
$(SUGENO_EMBEDDED_OUTPUT):
	mkdir -p $@
# ============================================================
# Desktop Build
# ============================================================
$(STRENGTH_TARGET): $(STRENGTH_SOURCE) fuzzy.h | $(STRENGTH_OUTPUT)
	@echo "\n============================================================"
	@echo "Building $@ from $<..."
	@echo "============================================================"
	$(CC_CMD) $(CFLAGS) $< $(LDFLAGS) -o $@ $(LDLIBS)
	@echo "[OK] Built $@"

$(GREENHOUSE_TARGET): $(GREENHOUSE_SOURCE) fuzzy.h | $(GREENHOUSE_OUTPUT)
	@echo "\n============================================================"
	@echo "Building $@ from $<..."
	@echo "============================================================"
	$(CC_CMD) $(CFLAGS) $< $(LDFLAGS) -o $@ $(LDLIBS)
	@echo "[OK] Built $@"

$(DEMO_TARGET): $(DEMO_SOURCE) fuzzy.h | $(DEMO_OUTPUT)
	@echo "\n============================================================"
	@echo "Building $@ from $<..."
	@echo "============================================================"
	$(CC_CMD) $(CFLAGS) $< $(LDFLAGS) -o $@ $(LDLIBS)
	@echo "[OK] Built $@"

$(SUGENO_TARGET): $(SUGENO_SOURCE) fuzzy.h | $(SUGENO_OUTPUT)
	@echo "\n============================================================"
	@echo "Building $@ from $<..."
	@echo "Desktop simulation mode: -DSIMULATION"
	@echo "============================================================"
	$(CC_CMD) $(CFLAGS) -DSIMULATION $< $(LDFLAGS) -o $@ $(LDLIBS)
	@echo "[OK] Built $@"

$(MAMDANI_8051_TARGET): $(MAMDANI_8051_SOURCE) fuzzy.h | $(MAMDANI_8051_OUTPUT)
	@echo "\n============================================================"
	@echo "Building $@ from $<..."
	@echo "Desktop simulation mode: -DSIMULATION"
	@echo "============================================================"
	$(CC_CMD) $(CFLAGS) -DSIMULATION $< $(LDFLAGS) -o $@ $(LDLIBS)
	@echo "[OK] Built $@"

# ============================================================
# Desktop Execution
# ============================================================
run-strength: $(STRENGTH_TARGET) | $(STRENGTH_OUTPUT)
	@echo "\n============================================================"
	@echo "Running paint-strength example"
	@echo "============================================================"
	./$(STRENGTH_TARGET)

run-greenhouse: $(GREENHOUSE_TARGET)
	@echo "\n============================================================"
	@echo "Running greenhouse example"
	@echo "============================================================"
	./$(GREENHOUSE_TARGET)

run-demo: $(DEMO_TARGET)
	@echo "\n============================================================"
	@echo "Running complete fuzzy.h demonstration"
	@echo "============================================================"
	./$(DEMO_TARGET)

run-sim-8051: $(MAMDANI_8051_TARGET)
	@echo "\n============================================================"
	@echo "Running desktop Mamdani 8051 simulation harness"
	@echo "============================================================"
	cd $(MAMDANI_8051_OUTPUT) && ../../$(MAMDANI_8051_TARGET)


run-sugeno: $(SUGENO_TARGET)
	@echo "\n============================================================"
	@echo "Running complex Sugeno controller demonstration"
	@echo "============================================================"
	cd $(SUGENO_OUTPUT) && ../$(SUGENO_TARGET)

# ============================================================
# Embedded SDCC Builds
# ============================================================

embedded-mamdani build-8051: \
    $(MAMDANI_EMBEDDED_SOURCE) fuzzy.h | $(MAMDANI_EMBEDDED_OUTPUT)
	@echo "\n============================================================"
	@echo "Building Mamdani AT89S52 firmware with SDCC"
	@echo "============================================================"
	@rm -f $(MAMDANI_EMBEDDED_OUTPUT)/$(MAMDANI_EMBEDDED_BASENAME).*
	cd $(MAMDANI_EMBEDDED_OUTPUT) && \
		$(SDCC) \
		-mmcs51 \
		--model-small \
		--opt-code-size \
		--debug \
		--stack-auto \
		--iram-size 256 \
		--stack-loc 0x80 \
		-I../.. \
		-o $(MAMDANI_EMBEDDED_BASENAME).ihx \
		../../$(MAMDANI_EMBEDDED_SOURCE)
	cd $(MAMDANI_EMBEDDED_OUTPUT) && \
		$(PACKIHX) \
		$(MAMDANI_EMBEDDED_BASENAME).ihx \
		> $(MAMDANI_EMBEDDED_BASENAME).hex
	@echo "\nGenerated Mamdani firmware:"
	@echo "  $(MAMDANI_EMBEDDED_OUTPUT)/$(MAMDANI_EMBEDDED_BASENAME).ihx"
	@echo "  $(MAMDANI_EMBEDDED_OUTPUT)/$(MAMDANI_EMBEDDED_BASENAME).hex"


embedded-sugeno build-sugeno-8051: \
    $(SUGENO_SOURCE) fuzzy.h | $(SUGENO_EMBEDDED_OUTPUT)
	@echo "\n============================================================"
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
	@echo "\nGenerated Sugeno firmware:"
	@echo "  $(SUGENO_EMBEDDED_OUTPUT)/$(SUGENO_EMBEDDED_BASENAME).ihx"
	@echo "  $(SUGENO_EMBEDDED_OUTPUT)/$(SUGENO_EMBEDDED_BASENAME).hex"

# ============================================================
# Embedded Execution and Testing
# ============================================================
simulate-8051: embedded-mamdani
	@if [ -z "$(SIMULATOR_COMMAND)" ]; then \
		echo "Error: no 8051 simulator was found."; \
		exit 1; \
	fi
	@echo "\n============================================================"
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
	@echo "\n============================================================"
	@echo "Starting Sugeno 8051 simulator"
	@echo "============================================================"
	$(SIMULATOR_COMMAND) \
		-t 52 \
		-X 11.0592M \
		$(SUGENO_EMBEDDED_OUTPUT)/$(SUGENO_EMBEDDED_BASENAME).ihx

debug-8051: embedded-mamdani
	@echo "\n============================================================"
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
# SVG Conversion
# ============================================================
define convert_svg
	@if [ ! -d "$(1)" ]; then echo "No directory found: $(1)"; exit 0; fi; \
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
	if [ "$$found" -eq 0 ]; then echo "No SVG files found in $(1)"; fi
endef

png: png-strength png-greenhouse png-demo png-sugeno png-sim-8051
pdf: pdf-strength pdf-greenhouse pdf-demo pdf-sugeno pdf-sim-8051

png-strength:
	$(call convert_svg,$(STRENGTH_OUTPUT),png)
png-greenhouse:
	$(call convert_svg,$(GREENHOUSE_OUTPUT),png)
png-demo:
	$(call convert_svg,$(DEMO_OUTPUT),png)
png-sim-8051:
	$(call convert_svg,$(SIM_8051_OUTPUT),png)

pdf-strength:
	$(call convert_svg,$(STRENGTH_OUTPUT),pdf)
pdf-greenhouse:
	$(call convert_svg,$(GREENHOUSE_OUTPUT),pdf)
pdf-demo:
	$(call convert_svg,$(DEMO_OUTPUT),pdf)
pdf-sim-8051:
	$(call convert_svg,$(SIM_8051_OUTPUT),pdf)

# ============================================================
# Cleanup
# ============================================================

clean: clean-desktop clean-embedded

clean-desktop:
	@echo "\n============================================================"
	@echo "Cleaning desktop outputs"
	@echo "============================================================"
	rm -f \
		$(STRENGTH_TARGET) \
		$(GREENHOUSE_TARGET) \
		$(DEMO_TARGET) \
		$(SUGENO_TARGET) \
		$(MAMDANI_8051_TARGET)
	rm -f \
		$(SIM_8051_ROOT)/test-8051-host \
		$(SIM_8051_ROOT)/test_8051_host.i
	find \
		$(STRENGTH_OUTPUT) \
		$(GREENHOUSE_OUTPUT) \
		$(DEMO_OUTPUT) \
		$(SUGENO_OUTPUT) \
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
	@echo "\n============================================================"
	@echo "Cleaning Mamdani embedded outputs"
	@echo "============================================================"
	rm -rf $(MAMDANI_EMBEDDED_OUTPUT)/* 2>/dev/null || true
	@echo "Mamdani embedded outputs removed."


clean-embedded-sugeno:
	@echo "\n============================================================"
	@echo "Cleaning Sugeno embedded outputs"
	@echo "============================================================"
	rm -rf $(SUGENO_EMBEDDED_OUTPUT)/* 2>/dev/null || true
	@echo "Sugeno embedded outputs removed."

# ============================================================
# Dependencies
# ============================================================
check-dependencies:
	@echo "\n============================================================"
	@echo "Checking dependencies"
	@echo "============================================================"
	@for cmd in gcc make bash sdcc packihx; do \
		if command -v $$cmd >/dev/null 2>&1; then echo "[OK]       $$cmd"; else echo "[MISSING]  $$cmd"; fi; \
	done
	@echo ""
	@for cmd in ccache mold rsvg-convert sdcdb; do \
		if command -v $$cmd >/dev/null 2>&1; then echo "[OK]       $$cmd"; else echo "[OPTIONAL] $$cmd"; fi; \
	done

install-dependencies:
	@echo "\n============================================================"
	@echo "Installing project dependencies"
	@echo "============================================================"
	@if ! command -v apt-get >/dev/null 2>&1; then echo "Error: automatic installation currently supports apt-based systems."; exit 1; fi
	sudo apt-get update
	sudo apt-get install -y build-essential gcc make ccache mold sdcc librsvg2-bin
	@if ! command -v s51 >/dev/null 2>&1; then \
		if apt-cache show sdcc-ucsim >/dev/null 2>&1; then sudo apt-get install -y sdcc-ucsim; \
		elif apt-cache show ucsim >/dev/null 2>&1; then sudo apt-get install -y ucsim; \
		else echo "Error: neither sdcc-ucsim nor ucsim is available."; exit 1; fi; \
	fi

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
	@echo "  make run-demo"
	@echo "  make run-sugeno"
	@echo "  make run-sim-8051"
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
	@echo "Testing:"
	@echo "  make test"
	@echo "  make test-8051"
	@echo ""
	@echo "Dependency commands:"
	@echo "  make check-dependencies"
	@echo "  make install-dependencies"
	@echo ""
	@echo "Image conversion:"
	@echo "  make png"
	@echo "  make pdf"
	@echo "  make png-sugeno"
	@echo "  make pdf-sugeno"
	@echo ""
	@echo "Cleanup:"
	@echo "  make clean"
	@echo "  make clean-desktop"
	@echo "  make clean-embedded"
	@echo "  make clean-embedded-mamdani"
	@echo "  make clean-embedded-sugeno"