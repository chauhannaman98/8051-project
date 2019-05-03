//Both timers 0 and 1 use the same register, called TMOD (timer mode), 
//to set the various timer operation modes in 8051 C programming. There are four operating modes of timer 0 and 1. 
//To generate Time delay using timer registers:
//Load the TMOD value register indicating which timer (timer 0 or timer 1) is to be used and which timer mode (0 or is selected
//Load registers TL and TH with initial count value
//Start the timer
//Keep monitoring the timer flag (TF) until it rolls over from FFFFH to 0000.
//After the timer reaches its limit and rolls over, in order to repeat the process - TH and TL must be reloaded with the original value, 
//and TR is turned off by setting value to 0 and TF must be reloaded to 0.

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
   TL0=0xFD;       //load timer low byte
   TH0=0x4B;       //load timer high byte
   TR0=1;          //turn on Timer0
   while(TF0==1);  //wait for TF0 to roll back
   TR0=0;          //turn off Timer0
   TF0=0;          //clear TF0
}
