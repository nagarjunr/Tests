#include <stdio.h>
#include <conio.h>

int ChecksumForGcode(char* Gcode)//Should be compiled in 2011 version(--std=c11) 
{
    int checksum =0;     
    for(int i=0; Gcode[i] != '*' && Gcode[i] != '\0'; i++) {
        checksum = checksum ^ (int)Gcode[i];
    }
    checksum &= 0xff;
    return checksum;
}

void main()
{
	char* 
}