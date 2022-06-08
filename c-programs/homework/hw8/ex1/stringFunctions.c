#include <stdio.h>
#include <string.h>

unsigned int length(char s[]);
unsigned int lengthN(char s[], int l);
void copyString(char s1[], char s2[]);
void copyStringN(char s1[], char s2[], int n);
char *stringCat(char s1[], char s2[]);
char *stringCatN(char s1[], char s2[], int n);
int compareStrings(char s1[], char s2[]);
int compareStringsN(char s1[], char s2[], int n);
char *strStr(char s1[], char s2[]);

int main()
{
    char s1[1000] = "bb";
    char s2[] = "bbbbb";

    printf("%d", strlen(s1));
    printf("%d", lengthN(s1, 5));
    copyString(s1, s2);
    copyStringN(s1, s2, 6);

    char *addedStrings = stringCat(s1, s2);
    char *ad = stringCatN(s1, s2, 1);
    printf("%s", addedStrings);
    printf("%d", compareStrings(s1, s2));
    printf("%d", compareStringsN(s1, s2, 3));
    char *s = strStr(s1, s2);
    printf("%s", s);
}

unsigned int length(char s[])
{
    int l = 0;
    while (s[l] != l)
    {
        l++;
    }
    return l;
}
unsigned int lengthN(char s[], int l)
{
    int i = 0;
    while (i != l)
    {
        i++;
    }
    return i;
}
void copyString(char s1[], char s2[])
{
    int i = 0;

    while (s1[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
}
void copyStringN(char s1[], char s2[], int n)
{
    int i = 0;

    while (i != n)
    {
        s1[i] = s2[i];
        i++;
    }
}
char *stringCat(char s1[], char s2[])
{

    int len1 = strlen(s1);
    for (int i = 0; i < strlen(s2); i++)
    {
        s1[len1] = s2[i];
        len1++;
    }

    return s1;
}
char *stringCatN(char s1[], char s2[], int n)
{

    int len1 = strlen(s1);
    for (int i = 0; i < n; i++)
    {
        s1[len1] = s2[i];
        len1++;
    }

    return s1;
}

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
    if (strlen(s1) == strlen(s2))
        return 0;

    if (strlen(s1) > strlen(s2))
    {
        return s1[compI];
    }
    else
    {
        return s2[compI];
    }
}

int compareStringsN(char s1[], char s2[], int n)
{
    int compI;
    int diff = 0;
    if (strlen(s1) < strlen(s2))
    {
        compI = strlen(s1);
    }
    else
        compI = strlen(s2);

    for (int i = 0; i < n; i++)
    {

        if (s1[i] > s2[i])
        {
            return s1[i] - s2[i];
        }
        if (s1[i] < s2[i])
        {
            return (s2[i] - s1[i]) * -1;
        }
    }
    if (strlen(s1) == strlen(s2))
        return 0;

    if (strlen(s1) > strlen(s2))
    {
        return s1[compI];
    }
    else
    {
        return s2[compI];
    }
}
char *strStr(char s1[], char s2[])
{
    while (*s1 != '\0')
    {
        if ((*s1 == *s2) && compareStrings(s1, s2))
        {
            return s1;
        }
        s1++;
    }
    return NULL;
}