#include <stdio.h>
#include <stdint.h>
#include <math.h>

void conv(int n, char *buffer);

int main()
{
    int16_t n = INT16_MAX;
    //  printf("%d",n);

    char str[10];
    conv(0, str);
}

void conv(int n, char *buffer)
{
    if(n<0){
        *(buffer) = '-';
        n = fabs(n);
    }
    int mod = 0;
 //   printf("%d %d \n", mod, n);
    int i = 5;
    while (n > 0)
    {
        mod = n % 10;
        n = n / 10;
      //  printf("%d %d\n", mod, n);
        *(buffer + i) = '0' + mod;
        i--;
    }
    for (int j = 0; j <= 5; j++)
    {
        if (!*(buffer + j))
        {
            printf(" ");
        }
        else
            printf("%c", *(buffer + j));
    }
}