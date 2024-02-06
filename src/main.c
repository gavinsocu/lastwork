#include <REG52.H>
#include <stdio.h>
#include "Delay.h"
#include "Led.h"
#include "Nixie.h"
#include "init.h"
#include "hander.h"
#include "Timeio.h"
#include "Clock.h"
#include "EEPROMmaker.h"


sbit beep = P1^0;
sbit RXD2 = P3^0;	
sbit TXD2 = P3^1;

static char flag1 = 1;
bit runOtherFunctions = 1;


char code mclass[] = {31,28,31,30,31,30,31,31,30,31,30,31};
char* code weekclass[] = {"Mon","Tues","Wed","Thur","Fri","Sat","Sun"};

char* Timer()
{
	char i = 0;
	static char str[28];
	char* temp = str;
	char* temp1 = str + 11;
	second++;
	makeled(second);
	if(second == 60)
	{
		second = 0;
		minute++;
		if(minute == 60)
		{
			minute = 0;
			hour++;
			if(hour == 24)
			{
				hour = 0;
				day++;
				if(day > mclass[month-1])
				{
					day = 0;
					month++;
					if(month == 12)
					{
						month = 1;
						year++;
					}
				}
			}
		}
	}
	sprintf(temp,"%d-%02d-%02d ",year,month,day);
	sprintf(temp1,"%02d:%02d:%02d %s \n",hour,minute,second,weekclass[day%7-1]);
	return str;
}

void makeHander() interrupt 0
{

	flag1 = !flag1;
	beep = 1;
}


void makeTimer() interrupt 1
{
	static int flag = 0;
	TH0 = 0XFC;
	TL0 = 0X18;
	flag++;
	if(flag >= 1000 && runOtherFunctions)
	{
        updatehander(Timer());
        Clock(hour,minute,second,hour1,minute1,second1); 
        EEPROMmaker();
        flag = 0;
	}		

}

void makeUart() interrupt 3
{
	if (TR1 == 1){
		TH1 = 0x30;    //波特率4800bps  
		TL1 = 0x30;    //定时器
		TF1 = 0;	   //清除TF1标志
	}

}


void main()
{
	TXD2 = 0;
	inituart();
	initinter();
	inittimer();
	EEPROMget();
	while(1)
	{	
	if(RXD2 == 0)
	{
		int maxnum = 410;
		unsigned char i = 0;
		runOtherFunctions = 0;
		EA = 0;
		while (maxnum--)
		{
			if (RXD2 == 0)
			{
				getdata();
				maxnum = 410;
			}
			
		}
		timeio(buffer);
		runOtherFunctions = 1;
		EA = 1;
		for(i = 0; i < 12; i++)
		{
			if (buffer[i] != 0)
			{
			buffer[i] = 0;
			}
			else
			{
				break;
			}
		}
		getnum = 0;
	}
	if(flag1)
	{
		Nixie(4,second%10);
		Nixie(3,second/10);
		Nixie(2,minute%10);
		Nixie(1,minute/10);
	}
	else
	{
		Nixie(4,day%10);
		Nixie(3,day/10);
		Nixie(2,month%10);
		Nixie(1,month/10);
	}
	}
	
}
