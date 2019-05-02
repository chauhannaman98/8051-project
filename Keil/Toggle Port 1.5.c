#include <reg51.h>

void TOM1Delay(void);
sbit mybit=P1^5;

void main(void)   {
   while(1)   {
      mybit=~mybit();
      TOM1Delay();
   }
}

void TOM1Delay(void)   {
   TMOD=0x01;
   TLO=0xFD;
   TLO=0x4B;
   TRO=1;
   while(TFO==1);
   TRO=0;
   TFO=0;
}
