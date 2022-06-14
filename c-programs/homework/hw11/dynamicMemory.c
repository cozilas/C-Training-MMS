#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int randint(int min, int max);
int main()
{
    srand(time(NULL));
    int n;

    scanf("%d", &n);

    int *arr = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        arr[i] = randint(0, 1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    int m;

    scanf("%d", &m);

    int *arr2 = calloc(n + m, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        arr2[i] = arr[i];
    }
    for (int i = n; i < n + m; i++)
    {
        arr2[i] = randint(1, 2);
    }
    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", arr2[i]);
    }

    int p;
    scanf("%d", &p);

    int *arr3 = calloc(n + m + p, sizeof(int));

    for (int i = 0; i < n+m; i++)
    {
        arr3[i] = arr2[i];
    }
    for (int i = n+m; i < n + m + p; i++)
    {
        arr3[i] = randint(2, 3);
    }
        for (int i = 0; i < n+m+p; i++)
    {
        printf("%d ",arr3[i]);
    }
    
    free(arr);
    free(arr2);
    free(arr3);
}
int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}