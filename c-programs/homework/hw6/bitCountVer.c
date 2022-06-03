#include <stdio.h>
#include <stdarg.h>
#include <float.h>
#include <ctype.h>

unsigned bitsNCount(unsigned count, unsigned bitscount, ...);
int bitsCount(int num, int bitscount);

int main()
{
    printf("%d\n", bitsNCount(4, 2, 0x0a, 0xff, 0, 1));
    printf("%d\n", bitsNCount(3, 8, 0xff, 0x13f1, 0xaaaa));
    printf("%d\n", bitsNCount(5, 10, 0x0a, 0xa0ff, 0, 10,0b1010111110111));
}

unsigned bitsNCount(unsigned count, unsigned bitscount, ...)
{

    int counter = 0;
    va_list argl;
    va_start(argl, count);
    for (int i = 0; i < count; i++)
    {

        if (bitsCount(va_arg(argl, int), bitscount))
        {
            counter++;
        }
    }
    va_end(argl);
    return counter;
}
int bitsCount(int num, int bitscount)
{
    int counter = 0;
    for (int n = 31; n >= 0; n--)
    {
        if (num & (1 << n))
        {
            counter++;
        }
    }
  //  printf("%d %d\n", bitscount, counter);
    if (bitscount == counter)
        return 1;
    else
        return 0;
}