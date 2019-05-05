data segment
   arr db 09h, 72h, 10h, 80h, 98h
   len equ $-arr
data ends
code segment
assume cs:code, ds:data
start:
   mov ax, data
   mov ds, ax
   mov ch, len-1
   L1:mov cl, ch
      mov si, offset arr
   L2:mov al, [si]
      inc si
      cmp al, [si]
      jbe L3                  ;in descending, change jbe to jae
      xchg al, [si]
      mov [si-1], al
   L3:dec cl
      jnz L2
      dec ch
      jnz L1
      int 3
code ends
end start
