
#include <reg51.h>

void main(void)   {
   TMOD=0X20;       //set timer 1 in Mode 2
   TH1=0XFA;        //load baud rate 4800
   SCON=0X50;       //set 8 data bit, serial control register
   TR1=1;           //start serial transmission
   while(1)   {
      SBUF='A';     //load data to serial buffer register
      while(TI==0); //wait until transmission complete
      TI=0;         //clear transmission interrupt flag
      }
   }
