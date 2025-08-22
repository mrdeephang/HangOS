## HangOS

## Folder Structure

hangos/
├── src/
│ ├── boot/
│ │ └── boot.asm
│ ├── kernel/
│ │ ├── kernel.cpp
│ │ ├── gdt.cpp
│ │ ├── idt.cpp
│ │ └── screen.cpp
│ └── linker.ld
├── include/
│ └── kernel/
│ ├── gdt.h
│ ├── idt.h
│ └── screen.h
├── Makefile
└── .vscode/
├── c_cpp_properties.json
├── tasks.json
└── launch.json

## Building and Running
Install the necessary cross-compiler tools:
sudo apt-get install build-essential nasm qemu-system-x86
Build the OS:
make
Run with QEMU:
qemu-system-i386 -kernel myos.bin# HangOS
