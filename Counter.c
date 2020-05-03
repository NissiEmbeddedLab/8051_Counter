#include<reg51.h>
sbit X = P3^5;
void main(void)
{
	X = 1;     //make T1 as input you can connect one sensor through this pin
	TMOD = 0x60;
	TH1 = 0;
	while(1) // give input to P3.4 1Hz
	{
		do
		{
			TR1 = 1; // start the timer 1 as counter. If any state change is occur it is incremented by 1
			P1 = TL1; // Register Timer 1 Lower byte content moves to PORT1
		}
		while(TF1 == 0);
		TR1 = 0;
		TF1 = 0;
	}
}