[bits 64]

section .text
global _start, stdin_fd, stdout_fd
extern main, tomato_init

_start:
        ; open stdin
        mov rax, 7
        mov rbx, stdin_path
        int 0x80
        mov [stdin_fd], eax
        ; open stdout
        mov rax, 7
        mov rbx, stdout_path
        int 0x80
        mov [stdout_fd], eax

        call tomato_init

        call main

        mov rax, 4
        int 0x80
        
; should never be reached
hang:
        jmp hang

section .rodata
stdin_path:             db "D:/input"
stdout_path:            db "D:/console"

section .data
stdin_fd:               dd 1
stdout_fd:              dd 1