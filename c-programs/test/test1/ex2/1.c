#include <stdio.h>
#include <inttypes.h>
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

    for (int i = 63; i >= 0; i -= 2)
    {
        *mask ^= 1 << i;
    }
}
unsigned mirrorBIts(uint16_t *mask)
{
    uint16_t r = 0;
    for (int i = 0; i < 16; ++i)
    {
        int bit = *mask & 0x01;
        r <<= 1;
        r += bit;
        *mask >>= 1;
    }
}

int main()
{
    uint64_t mask64 = 0ul;
    uint32_t mask32 = 2005;
    uint16_t mask16 = 2005;
    uint8_t mask8 = 20;

    uint64_t mask64s = 10ul;
    uint64_t mask16s = 10ul;
    bitCount(mask64, mask32, mask16, mask8);
    flipOddBits(&mask64s);
    mirrorBIts(mask16s);
    return 0;
}