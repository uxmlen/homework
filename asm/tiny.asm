;tiny.asm
%assign SYS_EXIT 1
%assign SYS_WRITE 4
%assign STDOUT 1
%assign ENDLN 10
bits 32
global _start
section .data 
    msg db 'hello world', ENDLN
    len equ $-msg           ; $$ is address of the begging of the current section
                            ; $ is address of the current position
section .text
_start:
        mov eax, SYS_WRITE  ; write(int fd, const void *buf, size_t nbytes);
        mov ebx, STDOUT     ; file discriptor stdout = 1 stdio = 0 stderr = 2 
        mov ecx, msg        ; address of the msg
        mov edx, len        ; msg length
        int 0x80
        mov eax, SYS_EXIT   ; _exit(int status)
        mov ebx, 42         ; status exit
        int 0x80
