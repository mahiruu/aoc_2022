global hello_world

section .rodata
    hello: db "Hello, World!", 10, 0
    hello_len equ $ - hello

section .text
    global _start

hello_world:
    mov rax, 1
    mov rdi, 1
    mov rsi, hello
    mov rdx, hello_len
    syscall

    mov rax, 60
    mov rdi, 0
    syscall