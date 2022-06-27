#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

int sumAll = 0;
pthread_mutex_t lock;

void *fileSum(void *argp);

int main(int argc, char *argv[])
{
    pthread_mutex_init(&lock,NULL);

    pthread_t threadArr[argc - 1];
    for (int i = 1; i < argc; i++)
    {
        pthread_create(&threadArr[i], NULL, &fileSum, (void *)(argv[i]));
        pthread_join(threadArr[i], NULL);
    }
    printf("the sum of all files is : %d\n", sumAll);
    return EXIT_SUCCESS;
}

int getSumDigits(int n){
    int s = 0;
    while(n!=0){
        s = s +n%10;
        n = n/10;
    }
    return s;
}



void *fileSum(void *argp)
{
    char *source = argp;
    FILE *fr = fopen(source, "r");
    if (fr == NULL)
    {
        fprintf(stderr, "%s-cant be found or you dont have permissions!\n", source);
        return 0;
    }
    int num;
    int sum = 0;
    int sumDigits;
    while (fscanf(fr,"%d",&num)>0)
    {
        sumDigits = getSumDigits(num);
        sum += sumDigits;
    }
    printf("%s sum = %d\n", source, sum);
    fclose(fr);
    pthread_mutex_lock(&lock);
    sumAll += sum;
    pthread_mutex_unlock(&lock);
}