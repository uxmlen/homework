bits 32
global _start
section .text
; if (eax == 5)
;   x;
    cmp eax, 5
    jnz L1          ; use opposite the condition
    ; x ... if statement is true
L1:
    ; continue a flow

; if (eax == 5) 
; x;
; else
; y;

    cmp eax, 5
    jnz L1
    ; x
    jmp L2
    jmp
.L1: 
    ; y
L2:
    ; continue a flow

; conjugation 
; if (eax == 5 && ebx > ecx)
;   x;
    cmp eax, 5
    jnz L1
    cmp ebx, ecx    ; don't compute 
    jna L1          ; unsigned ebx
    ; x if true
.L2:
    ; continue a flow

; disjugation
; if (eax == 5 || ebx > ecx)
;   x;
    cmp eax, 5
    jz L1
    cmp eax, ecx
    jnz L2
.L1:
    ; x
.L2:
    ; continue the flow

; cycle

; do-while
.L1:
    ; x
    cmp eax, 5
    jb L1

; while non-effective
.L1:
    cmp eax, 5
    jnb L2
    ; x
    jmp L1
.L2:
    ; continue a flow

; effective while
    jmp L2
.L1
   ;x 
.L2
    cmp eax, 5
    jb L1
; effective while-2
    cmp eax, 5
    jnb L2
.L1
    ;x 
    cmp eax, 5
    jb L1
.L2

; for (eax = 0, eax < 5; ++eax)
;   x;
; init-statement;
; while (condition) {
;   statement;
;   iteration expression;
; }
; if the condition is not guaranteed to be true
    xor eax, eax ; init statement
    cmp eax, 5
    jnb L2
.L1
    ;x 
    inc eax ; iteration expression;
    cmp eax, 5 ; condition
    jb L1
.L2
; if it's clear that the condition to be true in the first iteration
    xor eax, eax
.L1
    ;x 
    inc eax
    cmp eax, 5 ; 0 .. 4
    jb L1
.L2

; optimization not always possible
    mov eax, 5 ; the cycle goes backwards
.L1
    ;x 
    dec eax
    cmp eax, 5 ; 5..1
    jnz L1
.L2
; go up not reverse order
    mov eax, -5 ; the cycle goes backwards
.L1
    ;x 
    inc eax
    cmp eax, 5 ; 1 .. 5
    jnz L1
.L2


