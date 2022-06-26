#include <stdio.h>
#include <stdint.h>
#include <stdio.h>

#define SETBIT(mask,bit)mask = mask|(1<<bit)
#define CLEARBIT(mask,bit)mask = mask&~(1<<bit)
#define TOGGLEBIT(mask,bit)mask = mask^(1<<bit)
#define CHECKBIT(mask,bit)mask = mask&(1<<bit)

void printBitmask(uint32_t n)//just change the type
{
    int size = sizeof(n) * 8 - 1;

    for (int i = size; i >= 0; i--)
    {
        printf("%d", n & (1 << i) ? 1 : 0);
    }
    printf("\n");
}

void swapBytes(uint16_t *mask16)
{
    int temp = *mask16 & (1 << 15);
    int temp2 = *mask16 & 1;

    if (temp2)
    {
        *mask16 = *mask16 | (1 << 15);
    }
    else
    {
        *mask16 = *mask16 & (0 << 15);
    }
    if (!temp)
    {
        *mask16 = *mask16 | (1 << 15);
    }
    else
    {
        *mask16 = *mask16 & (0 << 15);
    }
}


int main()
{
    int num;
    scanf("%d", &num);

    uint16_t mask16 = 5;
    swapBytes(&mask16);

    uint32_t mask32 = 0;
    printBitmask(mask32);
    setBit(&mask32, 32, 2);
    printBitmask(mask32);
    printf("\n%d", checkBit(&mask32, 3, 1));
    return 0;
}