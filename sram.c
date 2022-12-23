#include "sram.h"
#include "types.h"

#define PMP_SERIAL_OUT (*((volatile uchar*) 0x88c0))
#define rPRINT         (*((volatile ulong*) 0x88e0))

void PMP_print_f(char* str)
{
    int count;
    int i;

    count = 128;
    i = 0;

    while ((str[i]!='\0') && (count--))
    {
        PMP_SERIAL_OUT = str[i];
        i++;
    }

    rPRINT = 0xffffffff;
    
}


