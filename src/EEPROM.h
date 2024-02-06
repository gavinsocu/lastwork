#ifndef __EEPROM_H__
#define __EEPROM_H__

sfr IAP_DATA = 0xE2;
sfr IAP_ADDRH = 0xE3;
sfr IAP_ADDRL = 0xE4;
sfr IAP_CMD = 0xE5;
sfr IAP_TRIG = 0xE6;
sfr IAP_CONTR = 0xE7;

void EEPROMErase(unsigned int addr);
void EEPROMWrite(unsigned int addr,unsigned char dat);
unsigned char EEPROMRead(unsigned int addr);


#endif
