#include "EEPROM.h"
#include "Timeio.h"

void EEPROMmaker()
{
    EEPROMErase(0X2000);
    EEPROMWrite(0X2000, year/100);
    EEPROMWrite(0X2002, year%100);
    EEPROMWrite(0X2004, month);
    EEPROMWrite(0X2006, day);
    EEPROMWrite(0X2008, hour);
    EEPROMWrite(0X2010, minute);
    EEPROMWrite(0X2012, second);
}

void EEPROMget()
{
    year = EEPROMRead(0X2000)*100 + EEPROMRead(0X2002);
    month = EEPROMRead(0X2004);
    day = EEPROMRead(0X2006);
    hour = EEPROMRead(0X2008);
    minute = EEPROMRead(0X2010);
    second = EEPROMRead(0X2012);
    hour1 = EEPROMRead(0x2200);
    minute1 = EEPROMRead(0x2202);
    second1 = EEPROMRead(0x2204);
}

void EEPROMclock()
{
    EEPROMErase(0X2200);
    EEPROMWrite(0x2200, hour1);
    EEPROMWrite(0x2202, minute1);
    EEPROMWrite(0x2204, second1);
}
