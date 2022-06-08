#include <stdio.h>
#include <string.h>

int compareStrings(char s1[], char s2[])
{
    int compI;
    int diff = 0;
    if (strlen(s1) < strlen(s2))
    {
        compI = strlen(s1);
    }
    else
        compI = strlen(s2);

    for (int i = 0; i < compI; i++)
    {
        printf("%c %c\n", s1[i], s2[i]);
        if (s1[i] > s2[i])
        {
            return s1[i] - s2[i];
        }
        if (s1[i] < s2[i])
        {
            return (s2[i] - s1[i]) * -1;
        }

    }
    if(strlen(s1) == strlen(s2))return 0;

    if (strlen(s1) > strlen(s2))
    {
        return strlen(s1);
    }
    else return strlen(s1);
}

int main()
{
    char s1[] = "aaaaaa";
    char s2[] = "aaaaa";

    // compareStrings(s1,s2);
    printf("%d", compareStrings(s1, s2));
    //   /  printf("s1 = %s \ns2 = %s\n",s1,s2);
}