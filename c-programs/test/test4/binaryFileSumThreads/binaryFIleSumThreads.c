#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
void binaryFileMaker(const char *name)
{
    FILE *fw = fopen(name, "wb");
    int num;
    for (int i = 0; i < 4; i++)
    {
        num = 0 + rand() % 20;
        fwrite(&num, sizeof(num), 1, fw);
    }
    fclose(fw);
}
int sumAll = 0;
pthread_mutex_t lock;

void *binaryFileSum(void *argp)
{
    char *source = argp;
    FILE *fr = fopen(source, "rb");
    if (fr == NULL)
    {
        fprintf(stderr, "%s-cant be found!\n", source);
        return 0;
    }
    int num;
    int sum = 0;
    while (fread(&num, sizeof(num), 1, fr))
    {
        sum += num;
    }
    printf("%s sum = %d\n", source, sum);
    fclose(fr);
    pthread_mutex_lock(&lock);
    sumAll += sum;
    pthread_mutex_unlock(&lock);
}

int main(int argc, char *argv[])
{
    pthread_mutex_init(&lock,NULL);

    pthread_t threadArr[argc - 1];
    for (int i = 1; i < argc; i++)
    {
        pthread_create(&threadArr[i], NULL, &binaryFileSum, (void *)(argv[i]));
        pthread_join(threadArr[i], NULL);
    }
    printf("the sum of all files is : %d\n", sumAll);

    return EXIT_SUCCESS;
}
/* int main(int argc, char **argv)
{
    binaryFileMaker("dfg");
    binaryFileMaker("dfg2");
    binaryFileMaker("dfg3");



} */