#include<REG52.H>
#include "EEPROMmaker.h"

sbit beep = P1^0;

void Clock(short a1,short a2,short a3,short b1,short b2,short b3)
{
    if (
        a1 == b1
        &&
        a2 == b2
        &&
        a3 == b3
    )
    {
        beep = 0;
    }
}