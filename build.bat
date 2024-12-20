@echo off
set OSNAME=FirstOS

nasm -f elf32 kernel\start.asm -o start.o
gcc -m32 -c kernel\kernel.c -o kernel.o
gcc -m32 -c kernel\shell\python_runner.c -o python_runner.o
ld -m i386pe -T kernel\kernel.ld start.o kernel.o python_runner.o -o kernel.bin

if not exist iso\boot\grub mkdir iso\boot\grub
copy kernel.bin iso\boot\kernel.bin
copy grub\grub.cfg iso\boot\grub\grub.cfg

xorriso -as mkisofs -R -f -e boot/grub/grub.cfg -no-emul-boot -boot-load-size 4 -boot-info-table -o %OSNAME%.iso iso

echo Build complete. ISO created as %OSNAME%.iso

