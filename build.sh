#!/bin/bash

# Clean previous build
rm -rf iso/boot/kernel.bin os.iso

# Assemble the kernel entry point
nasm -f elf kernel/start.asm -o start.o

# Compile the kernel
gcc -m32 -ffreestanding -c kernel/kernel.c -o kernel.o

# Link the kernel
ld -m elf_i386 -T kernel/kernel.ld -o kernel.bin start.o kernel.o

# Prepare the ISO structure
mkdir -p iso/boot/grub
cp grub/grub.cfg iso/boot/grub
cp kernel.bin iso/boot/

# Create the ISO
grub-mkrescue -o os.iso iso

# Test with QEMU
qemu-system-i386 -cdrom os.iso
