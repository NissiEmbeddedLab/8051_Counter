/* 	Author 		: 	L.Boaz
		Email id 	: 	laxsam89@gmail.com
		phone 		:		+91 95972 91816
		hackster	:		https://www.hackster.io/boaz */

#include<reg51.h>
sbit X = P3^5;					// In the circuit you can add one signal generator or switch
void main(void)
{
	X = 1;    					 	// make T1 as input you can connect one sensor through this pin
	TMOD = 0x60;
	TH1 = 0;
	while(1) 						
	{
		do
		{
			TR1 = 1; 					// start the timer 1 as counter. If any state change is occur it is incremented by 1
			P1 = TL1; 				// Register Timer 1 Lower byte content moves to PORT1
		}
		while(TF1 == 0);		// Run until Timer 1 overflow flag is set as one
		TR1 = 0;						// Once the Timer 1 overflow flag is set it goes to turn OFF the timer1 and clear the Timer Overflow flag
		TF1 = 0;
	}
}