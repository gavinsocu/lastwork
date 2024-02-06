#include <REG52.H>

void inituart()
{
	TMOD = 0x21;
	TL1 = 0X30;
	TH1 = TL1;
	ET1 = 1;
	TR1 = 1;
	TF1 = 0;
}

void initinter()
{
	ET0 = 1;
	IT0 = 1;
	EX0 = 1;

	
	ES = 0;
	EA = 1;
}

void inittimer()
{
	TH0 = 0xFC;
	TL0 = 0x18;
	TR0 = 1;
}
