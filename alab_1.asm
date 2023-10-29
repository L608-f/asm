global unint
global unch
global snch
global res
global va
global vb
global vc


section .bss

    res resb 4
    divd resb 4
    divr resb 4
    va resb 2
    vb resb 2

section .text
;(b+a)/(a-1) , если a > b
;23 , a = b
;b*b/8 , если a < b

snch:
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    mov al, [vc]
    mov ah, [vb]
    imul ah
    cwd
    mov bx, ax
    mov ax, [va]
    add bx, ax
    sub bx, 1
    mov [divd], bx
    mov ax, [va]
    mov cl, 3
    idiv cl
    cbw
    mov bx, ax
    mov ax, 1
    add bx, ax
    mov [divr], bx
    jz divz
    mov ax, [divd]
    cwd
    idiv bx
    mov [res], ax
    ret

unch:
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    mov al, [vc]
    mov ah, [vb]
    mul ah
    mov bx, ax
    mov al, [va]
    xor ah, ah
    add bx, ax
    sub bx, 1
    mov [divd], bx
    mov al, [va]
    xor ah, ah
    mov cl, 3
    div cl
    xor ah, ah
    mov bx, ax
    add bx, 1
    mov [divr], bx
    jz divz
    mov ax, [divd]
    cwd
    idiv bx
    mov [res], ax
    ret

unint:
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    mov ax, [vb]
    xor edx, edx
    mov bx, [vc]
    mul ebx
    mov bx, [va]
    add eax, ebx
    dec eax
    mov [divr], eax
    xor eax, eax
    mov ax, [va]
    mov bx, 3
    ;xor edx, edx
    div bx
    inc eax
    mov [divd], eax
    test eax, eax
    jz divz
    mov ecx, eax
    mov eax, [divr]
    cdq
    idiv ecx
    mov [res], eax
    ret

divz:
    mov dword [res], 0
    ret