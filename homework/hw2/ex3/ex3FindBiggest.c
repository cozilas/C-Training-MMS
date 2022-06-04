#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main()
{
    FILE *fp = fopen("numbers.txt", "r");
    int maxNum = INT_MIN;
    int numberFromList;
    if (fp == NULL)
    {
        return 1;
    }

    while (!feof(fp))
    {
        fscanf(fp, "%d", &numberFromList);
        if (numberFromList > maxNum)
            maxNum = numberFromList;
    }
    printf("%d\n", maxNum);

    return 0;
}