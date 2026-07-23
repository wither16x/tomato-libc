[bits 64]

section .text
global _start
extern main

_start:
        call main

        mov rax, 4
        int 0x80
        
; should never be reached
hang:
        jmp hang