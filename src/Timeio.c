#include<STRING.H>
#include<STDLIB.H>
#include "EEPROMmaker.h"

short year = 2022, month = 10, day = 10, hour = 10, minute = 22, second = 39;
short hour1=0, minute1=0,second1=60;

void timeio(char *str)
{
    int i = 0;
    int j = 0;
    char makestr[7];  
    char* value;
    while (str[i] != ',')
    {
        makestr[i] = str[i];
        i++;
    }
    makestr[i] = '\0';
    value = str + i + 1;
    if (strcmp(makestr, "year") == 0)
    {
        year = atoi(value);
    }
    else if (strcmp(makestr, "month") == 0)
    {
        month = atoi(value);
    }
    else if (strcmp(makestr, "day") == 0)
    {
        day = atoi(value);
    }
    else if (strcmp(makestr, "hour") == 0)
    {
        hour = atoi(value);
    }
    else if (strcmp(makestr, "minute") == 0)
    {
        minute = atoi(value);
    }
    else if (strcmp(makestr, "second") == 0)
    {
        second = atoi(value);
    }
    else if (strcmp(makestr,"c") == 0)
    {
        // value[2] = '\0';
        // value[5] = '\0';
        // value[8] = '\0'; 
        // year == atoi(value)&&
        // month == atoi(value + 5)&&
        // day == atoi(value + 8)&&
        hour1 = atoi(value);
        minute1 = atoi(value + 3);
        second1 = atoi(value + 6);
        EEPROMclock();
    }
}