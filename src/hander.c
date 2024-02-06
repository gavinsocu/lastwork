#include <REG52.H>
#include "Delay.h"
#include  "Timeio.h"
sbit RXD2 = P3^0;
sbit TXD2 = P3^1;

unsigned char buffer[12];
unsigned char getnum = 0;

void uarthander( unsigned char str) 
{	
	unsigned char i = 8;
	str = str + str;
	TR1 = 1;
	TXD2 = 1;
	waittf();
	while (i--)
	{
		TXD2 = str & 0x01;
		waittf();
		str >>= 1;
	}
	TXD2 = 0;
	waittf();
	TR1 = 0;
}


void updatehander( char* strr )
{
	while(*strr)
	{
		uarthander(*strr++);
	}
}

void getdata()
{
	unsigned char i = 8;
	unsigned char str = 0x0;
	if (RXD2 == 0)
	{
		TR1 = 1;
		waittf();
		while (i--)
		{
			str >>= 1;
			if (RXD2 == 1)
			{
				str |= 0x80;
			}
			waittf();
		}
		buffer[getnum++] = str;
		TR1 = 0;
	}
}