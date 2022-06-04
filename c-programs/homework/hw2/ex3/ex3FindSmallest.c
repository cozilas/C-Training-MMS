#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main()
{
    FILE *fp = fopen("numbers.txt", "r");
    int minNum = INT_MAX;
    int numberFromList;
    if (fp == NULL)
    {
        return 1;
    }

    while (!feof(fp))
    {
        fscanf(fp, "%d", &numberFromList);
        if (numberFromList < minNum)
            minNum = numberFromList;
    }
    printf("%d\n", minNum);
    return 0;
}