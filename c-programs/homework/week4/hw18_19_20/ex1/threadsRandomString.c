#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

void *routine()
{
    char str[11];
    for (int i = 0; i < 10; i++)
    {
        str[i] = 'a' + rand() % 26;
    }
    str[10] = '\0';
    printf("%s\n", str);
}

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);
    srand(time(NULL));
    pthread_t threadArr[n];
    for (int i = 0; i < n; i++)
    {
        pthread_create(&threadArr[i], NULL, &routine, NULL);
        pthread_join(threadArr[i], NULL);
    }
    return 0;
}
