
#include <reg51.h>

void main(void)   {
   TMOD=0X20;
   TH1=0XFA;
   SCON=0X50;
   TR1=1;
   while(1)   {
      SBUF='A';
      while(T1==0)
      TI=0;
      }
   }
