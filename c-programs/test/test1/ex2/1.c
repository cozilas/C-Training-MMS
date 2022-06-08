#include <stdio.h>
#include <inttypes.h>

void printBits(unsigned long long int n);
void bitCount(uint64_t mask64, uint32_t mask32, uint16_t mask16, uint8_t mask8);
unsigned flipOddBits(uint64_t *mask);
void printBits16Bit(uint16_t n);
unsigned mirrorBIts(uint16_t *mask);

int main()
{
    uint64_t mask64 = 0ul;
    uint32_t mask32 = 2005;
    uint16_t mask16 = 2005;
    uint8_t mask8 = 20;

    uint64_t mask64s = 0ul;
    uint16_t mask16s = 3333;
    printf("mirror bits =\n");
    mirrorBIts(&mask16s);
    printf("\ncount 1 bits =\n");
    bitCount(mask64, mask32, mask16, mask8);
    printf("\nflip every second bit =\n");
    flipOddBits(&mask64s);
    
    
    return 0;
}

void printBits(unsigned long long int n)
{
    for (int i = 63; i >= 0; i--)
    {
        printf("%llu", n & (1ull << i) ? 1ull : 0ull);
        // n = 1ull<<1;
    }
    printf("\n");
}

void bitCount(uint64_t mask64, uint32_t mask32, uint16_t mask16, uint8_t mask8)
{
    int counter = 0;
    for (int i = 63; i >= 0; i--)
    {
        if (!!(mask64 & (1ul << i)))
            counter++;
    }
    printf("%d\n", counter);
    counter = 0;

    for (int i = 31; i >= 0; i--)
    {
        if (!!(mask32 & (1u << i)))
            counter++;
    }
    printf("%d\n", counter);
    counter = 0;

    for (int i = 15; i >= 0; i--)
    {
        if (!!(mask16 & (1u << i)))
            counter++;
    }
    printf("%d\n", counter);
    counter = 0;

    for (int i = 7; i >= 0; i--)
    {
        if (!!(mask8 & (1u << i)))
            counter++;
    }
    printf("%d\n", counter);
    counter = 0;
}
unsigned flipOddBits(uint64_t *mask)
{
    for (int i = 63; i >= 0; i-=2)
    {
          *mask ^= (1ull << i);
    }
    printBits(*mask);
}

void printBits16Bit(uint16_t n)
{
    for (int i = 15; i >= 0; i--)
    {
        printf("%u", n & (1 << i) ? 1 : 0);
    }
    printf(" = %u",n);
    printf("\n");
}

unsigned mirrorBIts(uint16_t *mask)
{
    uint16_t p1;
    printBits16Bit(*mask);
    
 for (int i = 15; i >= 0; i--)
    {
        if(*mask&(1<<i)){
         p1 = p1 |(1<<(15-i));
        }
    }
    printBits16Bit(p1);
}