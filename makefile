CC       := ccache gcc
CFLAGS   := -O3 -Wall -Wextra -Wpedantic
LDFLAGS  := -fuse-ld=mold -s
LDLIBS   := -lm

STRENGTH_TARGET   := fuzzy
STRENGTH_SOURCE   := strength.c

GREENHOUSE_TARGET := greenhouse
GREENHOUSE_SOURCE := greenhouse.c

DEMO_TARGET       := fuzzy-demo
DEMO_SOURCE       := fuzzy.c

SVG_CONVERTER     := rsvg-convert

.PHONY: all help \
	run-strength run-greenhouse run-demo \
	png png-strength png-greenhouse png-demo \
	pdf pdf-strength pdf-greenhouse pdf-demo \
	check-converter install-converter clean

all: $(STRENGTH_TARGET) $(GREENHOUSE_TARGET) $(DEMO_TARGET)

$(STRENGTH_TARGET): $(STRENGTH_SOURCE) fuzzy.h
	$(CC) $(CFLAGS) $(STRENGTH_SOURCE) $(LDFLAGS) -o $(STRENGTH_TARGET) $(LDLIBS)

$(GREENHOUSE_TARGET): $(GREENHOUSE_SOURCE) fuzzy.h
	$(CC) $(CFLAGS) $(GREENHOUSE_SOURCE) $(LDFLAGS) -o $(GREENHOUSE_TARGET) $(LDLIBS)

$(DEMO_TARGET): $(DEMO_SOURCE) fuzzy.h
	$(CC) $(CFLAGS) $(DEMO_SOURCE) $(LDFLAGS) -o $(DEMO_TARGET) $(LDLIBS)

run-strength: $(STRENGTH_TARGET)
	mkdir -p svg
	./$(STRENGTH_TARGET)

run-greenhouse: $(GREENHOUSE_TARGET)
	mkdir -p greenhouse-svg
	./$(GREENHOUSE_TARGET)

run-demo: $(DEMO_TARGET)
	mkdir -p demo-svg
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
	for file in svg/*.svg; do \
		[ -e "$$file" ] || continue; \
		found=1; \
		output="$${file%.svg}.png"; \
		echo "[PNG] $$file -> $$output"; \
		$(SVG_CONVERTER) --output="$$output" "$$file"; \
	done; \
	if [ "$$found" -eq 0 ]; then \
		echo "No strength SVG files found. Run: make run-strength"; \
	fi

png-greenhouse: check-converter
	@set -e; \
	found=0; \
	for file in greenhouse-svg/*.svg; do \
		[ -e "$$file" ] || continue; \
		found=1; \
		output="$${file%.svg}.png"; \
		echo "[PNG] $$file -> $$output"; \
		$(SVG_CONVERTER) --output="$$output" "$$file"; \
	done; \
	if [ "$$found" -eq 0 ]; then \
		echo "No greenhouse SVG files found. Run: make run-greenhouse"; \
	fi

png-demo: check-converter
	@set -e; \
	found=0; \
	for file in demo-svg/*.svg; do \
		[ -e "$$file" ] || continue; \
		found=1; \
		output="$${file%.svg}.png"; \
		echo "[PNG] $$file -> $$output"; \
		$(SVG_CONVERTER) --output="$$output" "$$file"; \
	done; \
	if [ "$$found" -eq 0 ]; then \
		echo "No demo SVG files found. Run: make run-demo"; \
	fi

pdf: pdf-strength pdf-greenhouse pdf-demo

pdf-strength: check-converter
	@set -e; \
	for file in svg/*.svg; do \
		[ -e "$$file" ] || continue; \
		output="$${file%.svg}.pdf"; \
		echo "[PDF] $$file -> $$output"; \
		$(SVG_CONVERTER) --format=pdf --output="$$output" "$$file"; \
	done

pdf-greenhouse: check-converter
	@set -e; \
	for file in greenhouse-svg/*.svg; do \
		[ -e "$$file" ] || continue; \
		output="$${file%.svg}.pdf"; \
		echo "[PDF] $$file -> $$output"; \
		$(SVG_CONVERTER) --format=pdf --output="$$output" "$$file"; \
	done

pdf-demo: check-converter
	@set -e; \
	for file in demo-svg/*.svg; do \
		[ -e "$$file" ] || continue; \
		output="$${file%.svg}.pdf"; \
		echo "[PDF] $$file -> $$output"; \
		$(SVG_CONVERTER) --format=pdf --output="$$output" "$$file"; \
	done

clean:
	rm -f $(STRENGTH_TARGET) $(GREENHOUSE_TARGET) $(DEMO_TARGET)
	rm -f svg/*.svg svg/*.png svg/*.pdf
	rm -f greenhouse-svg/*.svg greenhouse-svg/*.png greenhouse-svg/*.pdf
	rm -f demo-svg/*.svg demo-svg/*.png demo-svg/*.pdf


help:
	@echo "fuzzy.h build commands"
	@echo ""
	@echo "  make                  Build all executables"
	@echo "  make run-strength     Run the paint-strength example"
	@echo "  make run-greenhouse   Run the greenhouse example"
	@echo "  make run-demo         Run the built-in shape demo"
	@echo ""
	@echo "  make png              Convert all generated SVG files to PNG"
	@echo "  make png-strength     Convert paint-strength SVG files to PNG"
	@echo "  make png-greenhouse   Convert greenhouse SVG files to PNG"
	@echo "  make png-demo         Convert demonstration SVG files to PNG"
	@echo ""
	@echo "  make pdf              Convert all generated SVG files to PDF"
	@echo "  make pdf-strength     Convert paint-strength SVG files to PDF"
	@echo "  make pdf-greenhouse   Convert greenhouse SVG files to PDF"
	@echo "  make pdf-demo         Convert demonstration SVG files to PDF"
	@echo ""
	@echo "  make check-converter  Check for rsvg-convert"
	@echo "  make install-converter"
	@echo "                        Install librsvg2-bin on Debian/Ubuntu"
	@echo "  make clean            Remove executables and generated plots"
	@echo ""
	@echo "SVG generation and numerical fuzzy evaluation do not require"
	@echo "the optional SVG converter."