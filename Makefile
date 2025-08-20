# Makefile for MyOS

# Tools
ASM = nasm
CC = i686-elf-g++
LD = i686-elf-ld

# Flags
ASMFLAGS = -f elf32
CFLAGS = -m32 -std=c++11 -nostdlib -fno-builtin -fno-exceptions -fno-rtti -fno-leading-underscore -Wall -Wextra
LDFLAGS = -m elf_i386 -T src/linker.ld

# Source files
ASM_SOURCES = src/boot/boot.asm
C_SOURCES = $(wildcard src/kernel/*.cpp)
OBJECTS = $(ASM_SOURCES:.asm=.o) $(C_SOURCES:.cpp=.o)

# Output
KERNEL = myos.bin

# Build rules
all: $(KERNEL)

$(KERNEL): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^

%.o: %.asm
	$(ASM) $(ASMFLAGS) -o $@ $<

%.o: %.cpp
	$(CC) $(CFLAGS) -Iinclude -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(KERNEL)

.PHONY: all clean