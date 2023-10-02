section .data
        msg db "hello World"
section .text
        global_start
_start:
        mov rax, 1
        mov rdi, 1
        mov rsi, msg
        mov rdx, 300
        syscall
        mov rax, 60
        mov rdi, 0
        syscall

