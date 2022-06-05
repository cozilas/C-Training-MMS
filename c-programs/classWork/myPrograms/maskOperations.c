#include <stdio.h>
#include <inttypes.h>

int main()
{
    uint64_t mask = 2005ul;

    for (int i = 63; i >= 0; i--)
    {
        printf("%u", (mask & (1ul << i)) ? 1 : 0);
    }
    printf("\n");

    mask = mask << 1;

    for (int i = 63; i >= 0; i--)
    {

        // printf("%u", !!(mask & (1ul << i)));
    }
    printf("%lu", mask);
    return 0;
}