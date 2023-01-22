/********************************************************************
    Author: Kwadwo Bempah
    Date: 01/20/2023
    Effort: ~2 hours
    Purpose: To practice the use of the bitwise left shift operator
********************************************************************/

#include <stdio.h>

int main(int argc, const char* argv[])
{
    unsigned int x = 1;

    for (int bit = 0; x != 0 ;bit++)
    {
        printf("%2d: %u\n", bit, x);
        x <<= 1;
    }
    
    return 0;
}
