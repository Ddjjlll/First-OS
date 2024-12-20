[BITS 32]
global start
extern kernel_main

start:
    cli
    mov esp, stack_space
    call kernel_main
    hlt

section .bss
resb 8192
stack_space:

