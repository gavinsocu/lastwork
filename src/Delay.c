#include "REG52.H"

void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}

void waittf(){
	while (TF1 == 0);
	TF1 = 0;
}

