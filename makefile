CC       := ccache gcc
CFLAGS   := -O2 -Wall -Wextra -Wpedantic
LDFLAGS  := -fuse-ld=mold -lm -lm -lpthread

TARGET   := fuzzy
SOURCE   := strength.c #greenhouse.c

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) $(LDFLAGS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)