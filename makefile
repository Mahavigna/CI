CC       := ccache gcc
CFLAGS   := -O3 -Wall -Wextra -Wpedantic
LDFLAGS  := -fuse-ld=mold -s
LDLIBS   := -lm

TARGET      := fuzzy
SOURCE      := strength.c
DEMO_TARGET := fuzzy-demo
DEMO_SOURCE := fuzzy.c

.PHONY: all run demo clean

all: $(TARGET)

$(TARGET): $(SOURCE) fuzzy.h
	$(CC) $(CFLAGS) $(SOURCE) $(LDFLAGS) -o $(TARGET) $(LDLIBS)

$(DEMO_TARGET): $(DEMO_SOURCE) fuzzy.h
	$(CC) $(CFLAGS) $(DEMO_SOURCE) $(LDFLAGS) -o $(DEMO_TARGET) $(LDLIBS)

run: $(TARGET)
	mkdir -p svg
	./$(TARGET)

demo: $(DEMO_TARGET)
	mkdir -p svg
	./$(DEMO_TARGET)

clean:
	rm -f $(TARGET) $(DEMO_TARGET)
	rm -f svg/*.svg