data segement
   a dw 0004H
   b dw 0002H
   c dw ?
data ends
code segment
assume cs:code, ds:data
start:
   mov ax, data
   mov ds, ax
   mov ax, a
   mov bx, b
   add ax, bx
   mov cx, ax
   int 3
code ends
end start
