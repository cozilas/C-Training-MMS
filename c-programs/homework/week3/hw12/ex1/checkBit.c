#include <stdio.h>
unsigned char checkBit(unsigned int bitmask);

int main()
{
    unsigned int bitmask;

    scanf("%x", &bitmask);

    checkBit(bitmask);
    printf("0x0%x", checkBit(bitmask));

    return 0;
}

unsigned char checkBit(unsigned int bitmask)
{
    for (int i = 31; i >= 0; i--)
    {
        if (bitmask & (1 << i))
            return 1;
    }
    return 0;
}