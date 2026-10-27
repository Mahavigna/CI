CC       := ccache gcc
CFLAGS   := -O3 -Wall -Wextra -Wpedantic
LDFLAGS  := -fuse-ld=mold -s
LDLIBS   := -lm

STRENGTH_TARGET   := fuzzy
STRENGTH_SOURCE   := strength.c
STRENGTH_OUTPUT   := svg

GREENHOUSE_TARGET := greenhouse-app
GREENHOUSE_SOURCE := greenhouse.c
GREENHOUSE_OUTPUT := greenhouse

DEMO_TARGET       := fuzzy-demo
DEMO_SOURCE       := demo_all.c
DEMO_OUTPUT       := demo-all

SVG_CONVERTER     := rsvg-convert


.PHONY: all help \
	run-strength run-greenhouse run-demo \
	png png-strength png-greenhouse png-demo \
	pdf pdf-strength pdf-greenhouse pdf-demo \
	check-converter install-converter clean


all: $(STRENGTH_TARGET) $(GREENHOUSE_TARGET) $(DEMO_TARGET)


$(STRENGTH_TARGET): $(STRENGTH_SOURCE) fuzzy.h
	$(CC) $(CFLAGS) $(STRENGTH_SOURCE) \
		$(LDFLAGS) -o $(STRENGTH_TARGET) $(LDLIBS)


$(GREENHOUSE_TARGET): $(GREENHOUSE_SOURCE) fuzzy.h
	$(CC) $(CFLAGS) $(GREENHOUSE_SOURCE) \
		$(LDFLAGS) -o $(GREENHOUSE_TARGET) $(LDLIBS)


$(DEMO_TARGET): $(DEMO_SOURCE) fuzzy.h
	$(CC) $(CFLAGS) $(DEMO_SOURCE) \
		$(LDFLAGS) -o $(DEMO_TARGET) $(LDLIBS)


run-strength: $(STRENGTH_TARGET)
	mkdir -p $(STRENGTH_OUTPUT)
	./$(STRENGTH_TARGET)


run-greenhouse: $(GREENHOUSE_TARGET)
	mkdir -p $(GREENHOUSE_OUTPUT)
	./$(GREENHOUSE_TARGET)


run-demo: $(DEMO_TARGET)
	mkdir -p $(DEMO_OUTPUT)
	./$(DEMO_TARGET)


check-converter:
	@command -v $(SVG_CONVERTER) >/dev/null 2>&1 || { \
		echo "Optional SVG converter not found: $(SVG_CONVERTER)"; \
		echo "Install on Debian/Ubuntu with:"; \
		echo "  sudo apt install librsvg2-bin"; \
		echo ""; \
		echo "SVG generation itself still works without this tool."; \
		exit 1; \
	}


install-converter:
	sudo apt install librsvg2-bin


png: png-strength png-greenhouse png-demo


png-strength: check-converter
	@set -e; \
	found=0; \
	for file in $(STRENGTH_OUTPUT)/*.svg; do \
		[ -e "$$file" ] || continue; \
		found=1; \
		output="$${file%.svg}.png"; \
		echo "[PNG] $$file -> $$output"; \
		$(SVG_CONVERTER) --output="$$output" "$$file"; \
	done; \
	if [ "$$found" -eq 0 ]; then \
		echo "No strength SVG files found."; \
		echo "Run: make run-strength"; \
	fi


png-greenhouse: check-converter
	@set -e; \
	found=0; \
	for file in $(GREENHOUSE_OUTPUT)/*.svg; do \
		[ -e "$$file" ] || continue; \
		found=1; \
		output="$${file%.svg}.png"; \
		echo "[PNG] $$file -> $$output"; \
		$(SVG_CONVERTER) --output="$$output" "$$file"; \
	done; \
	if [ "$$found" -eq 0 ]; then \
		echo "No greenhouse SVG files found."; \
		echo "Run: make run-greenhouse"; \
	fi


png-demo: check-converter
	@set -e; \
	found=0; \
	for file in $(DEMO_OUTPUT)/*.svg; do \
		[ -e "$$file" ] || continue; \
		found=1; \
		output="$${file%.svg}.png"; \
		echo "[PNG] $$file -> $$output"; \
		$(SVG_CONVERTER) --output="$$output" "$$file"; \
	done; \
	if [ "$$found" -eq 0 ]; then \
		echo "No complete-demo SVG files found."; \
		echo "Run: make run-demo"; \
	fi


pdf: pdf-strength pdf-greenhouse pdf-demo


pdf-strength: check-converter
	@set -e; \
	found=0; \
	for file in $(STRENGTH_OUTPUT)/*.svg; do \
		[ -e "$$file" ] || continue; \
		found=1; \
		output="$${file%.svg}.pdf"; \
		echo "[PDF] $$file -> $$output"; \
		$(SVG_CONVERTER) \
			--format=pdf \
			--output="$$output" \
			"$$file"; \
	done; \
	if [ "$$found" -eq 0 ]; then \
		echo "No strength SVG files found."; \
		echo "Run: make run-strength"; \
	fi


pdf-greenhouse: check-converter
	@set -e; \
	found=0; \
	for file in $(GREENHOUSE_OUTPUT)/*.svg; do \
		[ -e "$$file" ] || continue; \
		found=1; \
		output="$${file%.svg}.pdf"; \
		echo "[PDF] $$file -> $$output"; \
		$(SVG_CONVERTER) \
			--format=pdf \
			--output="$$output" \
			"$$file"; \
	done; \
	if [ "$$found" -eq 0 ]; then \
		echo "No greenhouse SVG files found."; \
		echo "Run: make run-greenhouse"; \
	fi


pdf-demo: check-converter
	@set -e; \
	found=0; \
	for file in $(DEMO_OUTPUT)/*.svg; do \
		[ -e "$$file" ] || continue; \
		found=1; \
		output="$${file%.svg}.pdf"; \
		echo "[PDF] $$file -> $$output"; \
		$(SVG_CONVERTER) \
			--format=pdf \
			--output="$$output" \
			"$$file"; \
	done; \
	if [ "$$found" -eq 0 ]; then \
		echo "No complete-demo SVG files found."; \
		echo "Run: make run-demo"; \
	fi


clean:
	rm -f \
		$(STRENGTH_TARGET) \
		$(GREENHOUSE_TARGET) \
		$(DEMO_TARGET)

	rm -f \
		$(STRENGTH_OUTPUT)/*.svg \
		$(STRENGTH_OUTPUT)/*.png \
		$(STRENGTH_OUTPUT)/*.pdf \
		$(STRENGTH_OUTPUT)/*.csv

	rm -f \
		$(GREENHOUSE_OUTPUT)/*.svg \
		$(GREENHOUSE_OUTPUT)/*.png \
		$(GREENHOUSE_OUTPUT)/*.pdf \
		$(GREENHOUSE_OUTPUT)/*.csv

	rm -f \
		$(DEMO_OUTPUT)/*.svg \
		$(DEMO_OUTPUT)/*.png \
		$(DEMO_OUTPUT)/*.pdf \
		$(DEMO_OUTPUT)/*.csv


help:
	@echo "fuzzy.h build commands"
	@echo ""
	@echo "Build commands:"
	@echo "  make                  Build all executables"
	@echo "  make fuzzy            Build the paint-strength example"
	@echo "  make greenhouse-app   Build the greenhouse example"
	@echo "  make fuzzy-demo       Build the complete API demonstration"
	@echo ""
	@echo "Run commands:"
	@echo "  make run-strength     Run the paint-strength example"
	@echo "  make run-greenhouse   Run the greenhouse example"
	@echo "  make run-demo         Run demo_all.c"
	@echo ""
	@echo "PNG conversion:"
	@echo "  make png              Convert all generated SVG files"
	@echo "  make png-strength     Convert paint-strength SVG files"
	@echo "  make png-greenhouse   Convert greenhouse SVG files"
	@echo "  make png-demo         Convert demo-all SVG files"
	@echo ""
	@echo "PDF conversion:"
	@echo "  make pdf              Convert all generated SVG files"
	@echo "  make pdf-strength     Convert paint-strength SVG files"
	@echo "  make pdf-greenhouse   Convert greenhouse SVG files"
	@echo "  make pdf-demo         Convert demo-all SVG files"
	@echo ""
	@echo "Utility commands:"
	@echo "  make check-converter  Check for rsvg-convert"
	@echo "  make install-converter"
	@echo "                        Install librsvg2-bin"
	@echo "  make clean            Remove executables and generated files"
	@echo ""
	@echo "Output directories:"
	@echo "  Paint strength:       $(STRENGTH_OUTPUT)/"
	@echo "  Greenhouse:           $(GREENHOUSE_OUTPUT)/"
	@echo "  Complete demo:        $(DEMO_OUTPUT)/"
	@echo ""
	@echo "SVG generation and numerical fuzzy evaluation do not require"
	@echo "the optional SVG converter."