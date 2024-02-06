#include <REG52.H>


sbit led1=P2^4;
sbit led2=P2^5;
sbit led3=P2^6;
sbit led4=P2^7;


void makeled(char count)
{
	led1 = 1; led2 = 1; led3 = 1; led4 = 1;
	count = count%4;
	if(count == 0)
	{
		led1 = 0;
	}
	else if(count == 1)
	{
		led2 = 0;
	}
	else if(count == 2)
	{
		led3 = 0;
	}
	else
	{
		led4 = 0;
	}
}
