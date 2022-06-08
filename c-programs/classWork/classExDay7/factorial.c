#include <stdio.h>

unsigned long factoriel(int n)
{
    unsigned long product = 1;
    for (int i = 1; i <= n; i++)
    {
        product *= i;
    }
    return product;
}
unsigned long factoriel_recursive(int n)
{
    return factoriel_recursive(n-1)*n;
}
int main()
{
    unsigned long res = factoriel(11);
    printf("%lu\n", res);
}