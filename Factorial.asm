data segment
   a dw 0005H
   b dd ?
data ends
code segment
assume cs:code, ds:data
start:
   mov ax, data
   mov ds, ax
   mov ax, 00
   mov ax, a
   L1:dec a
      mul a
      mov cx, a
      cmp cx, 01
      jnz L1
      mov word ptr c, ax
      mov word ptr c+2, ax
      int 3
code ends
end start
