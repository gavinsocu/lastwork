#include "Delay.h"
#include <REG52.H>

sbit seg1 = P2^3;		//数码管时间进入标志号
sbit seg2 = P2^2;		//数码管时间进入标志号
sbit seg3 = P2^1;
sbit seg4 = P2^0;
//数码管段码表
unsigned char code NixieTable[]={0x03,0x9F,0x25,0x0D,0x99,0x49,0x41,0x1F,0x01,0x09};


//数码管显示子函数
void Nixie(unsigned char Location,Number)
{
	switch(Location)		//位码输出
	{
		case 1:seg1 = 0,seg2 = 1,seg3 = 1,seg4 = 1;break;
		case 2:seg1 = 1,seg2 = 0,seg3 = 1,seg4 = 1;break;
		case 3:seg1 = 1,seg2 = 1,seg3 = 0,seg4 = 1;break;
		case 4:seg1 = 1,seg2 = 1,seg3 = 1,seg4 = 0;break;
	}
	P0=NixieTable[Number];	//段码输出
	Delay(1);				//显示一段时�?
	P0=~0x0;				//段码�?0，消�?
}
