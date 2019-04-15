#include <reg51.h>

void main(void)   {
   unsigned int x;
   P1=0X00;
   for( ; ; )   {
      P1=0X55;
      for(x=0;x<40000;x++);
      P1=0XAA;
      for(x=0;x<40000;x++);
      }
   }
