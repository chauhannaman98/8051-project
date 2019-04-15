data segment
   a db 11h, 12h, 13h, 14h, 15h, 16h
   b db 06 dup(?)
data ends
code segment
assume cs:code, ds:data
start:
   mov ax, data
   mov ds, ax
   mov es, ax
   lea si, a
   lea di, b
   cld
   mov cx, 06
   REP mov sb
   int 3
code ends
end start
