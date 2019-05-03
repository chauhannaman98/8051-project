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
   TMOD=0x01;      //Timer Mode Control register, Timer 0 Mode 1
   TLO=0xFD;       //load timer low byte
   THO=0x4B;       //load timer high byte
   TRO=1;          //turn on Timer0
   while(TFO==1);  //wait for TF0 to roll back
   TRO=0;          //turn off Timer0
   TFO=0;          //clear TF0
}
