SHELL := /usr/bin/env bash

BUILD_SCRIPT := scripts/build.sh

.PHONY: all desktop embedded test \
	run-strength run-greenhouse run-demo run-sim-8051 \
	build-8051 simulate-8051 debug-8051 test-8051 \
	check-dependencies install-dependencies \
	png png-strength png-greenhouse png-demo png-sim-8051 \
	pdf pdf-strength pdf-greenhouse pdf-demo pdf-sim-8051 \
	clean clean-desktop clean-embedded help

all:
	./$(BUILD_SCRIPT) all

desktop:
	./$(BUILD_SCRIPT) desktop

embedded:
	./$(BUILD_SCRIPT) embedded

test:
	./$(BUILD_SCRIPT) test

run-strength:
	./$(BUILD_SCRIPT) run-strength

run-greenhouse:
	./$(BUILD_SCRIPT) run-greenhouse

run-demo:
	./$(BUILD_SCRIPT) run-demo

run-sim-8051:
	./$(BUILD_SCRIPT) run-sim-8051

build-8051:
	./$(BUILD_SCRIPT) embedded

simulate-8051:
	./$(BUILD_SCRIPT) simulate-8051

debug-8051:
	./$(BUILD_SCRIPT) debug-8051

test-8051:
	./$(BUILD_SCRIPT) test-8051

check-dependencies:
	./$(BUILD_SCRIPT) check-dependencies

install-dependencies:
	./$(BUILD_SCRIPT) install-dependencies

png:
	./$(BUILD_SCRIPT) png

png-strength:
	./$(BUILD_SCRIPT) png-strength

png-greenhouse:
	./$(BUILD_SCRIPT) png-greenhouse

png-demo:
	./$(BUILD_SCRIPT) png-demo

png-sim-8051:
	./$(BUILD_SCRIPT) png-sim-8051

pdf:
	./$(BUILD_SCRIPT) pdf

pdf-strength:
	./$(BUILD_SCRIPT) pdf-strength

pdf-greenhouse:
	./$(BUILD_SCRIPT) pdf-greenhouse

pdf-demo:
	./$(BUILD_SCRIPT) pdf-demo

pdf-sim-8051:
	./$(BUILD_SCRIPT) pdf-sim-8051

clean:
	./$(BUILD_SCRIPT) clean

clean-desktop:
	./$(BUILD_SCRIPT) clean-desktop

clean-embedded:
	./$(BUILD_SCRIPT) clean-embedded

help:
	./$(BUILD_SCRIPT) help