#include <stdio.h>

int main()
{
    int number;

    double root = 1;
    int i = 0;

    scanf("%d", &number);
    while (1)
    {
        i = i + 1;
        root = (number / root + root) / 2;
        if (i == number + 1)
            break;
    }
    printf("%.2f", root);
}