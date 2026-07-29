[bits 64]

section .text
global _start
extern main, tomato_init, tomato_end

_start:
        call tomato_init
        call main
        call tomato_end
        
; should never be reached
hang:
        jmp hang