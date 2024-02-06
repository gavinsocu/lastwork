#include<REG52.H>
#include<EEPROM.H>

static void EEPROMinit()
{
    IAP_TRIG = 0X46;
    IAP_TRIG = 0XB9;
}

static void EEPROMisable()
{
    IAP_CONTR = 0X00;
    IAP_CMD = 0X00;
    IAP_TRIG = 0X00;
}

void EEPROMErase(unsigned int addr)
{
    IAP_CONTR = 0X81;
    IAP_CMD = 0X03;

    IAP_ADDRH = addr>>8;
    IAP_ADDRL = addr;
    
    EEPROMinit();
    EEPROMisable();
}

void EEPROMWrite(unsigned int addr,unsigned char dat)
{
    IAP_CONTR = 0X81;
    IAP_CMD = 0X02;

    IAP_ADDRH = addr>>8;
    IAP_ADDRL = addr;
    IAP_DATA = dat;
    
    EEPROMinit();
    EEPROMisable();
}

unsigned char EEPROMRead(unsigned int addr)
{
    unsigned char dat;
    IAP_CONTR = 0X81;
    IAP_CMD = 0X01;

    IAP_ADDRH = addr>>8;
    IAP_ADDRL = addr;
    
    EEPROMinit();
    dat = IAP_DATA;
    EEPROMisable();
    return dat;
}