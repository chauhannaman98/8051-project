data segment
   a db 11h, 12h, 13h, 14h, 15h, 16h
   b db 06 dup(?)
data ends
code segment
assume cs:code, ds:data
start:
   mov ax, data
   mov ds, ax
   mov es, ax           //load data of ax to es - extra segment register
   lea si, a            //load effective address of 'a' to source index register
   lea di, b            //load effective address of 'b' to destination index register
   cld                  //clear flag
   mov cx, 06
   REP movsb            //repeat
   int 3
code ends
end start
