CC       := ccache gcc
CFLAGS   := -O3 -Wall -Wextra -Wpedantic
LDFLAGS  := -fuse-ld=mold -s
LDLIBS   := -lm

TARGET   := fuzzy
SOURCE   := strength.c

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SOURCE) fuzzy.h
	$(CC) $(CFLAGS) $(SOURCE) $(LDFLAGS) -o $(TARGET) $(LDLIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)