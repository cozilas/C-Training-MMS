#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
int cmpfun(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
/* void decimalToBinary(char *source, char *destination)
{
    printf("%s %s", source, destination);

    FILE *fr = fopen(source, "r");
    FILE *fw = fopen(destination, "wb");

    if (fr == NULL)
    {
        fprintf(stderr, "cant read");
        return;
    }
    int num;
    while (fscanf(fr, "%d", &num) != EOF)
    {
        fwrite(&num, sizeof(num), 1, fw);
    }
    fclose(fw);
    fclose(fr);
    printf("\nwriting successful tb\n");
} */
void binaryFileMaker(const char *name)
{
    FILE *fw = fopen(name, "wb");
    int num;
    for (int i = 0; i < 20; i++)
    {
        num = 0 + rand() % 20;
        fwrite(&num, sizeof(num), 1, fw);
    }
    fclose(fw);
}
void binaryToDecimal(char *source)
{

    FILE *fr = fopen(source, "rb");

    if (fr == NULL)
    {
        fprintf(stderr, "cant read");
        return;
    }
    int num;
    int bufferIndex = 0;
    int buffer[100000];
    while (fread(&num, sizeof(num), 1, fr))
    {

        //  fprintf(fw, "%d\n", num);
        //  printf("%x ", num);
        buffer[bufferIndex++] = num;
    }
    putchar('\n');
    qsort(buffer, bufferIndex, sizeof(int), cmpfun);
    for (int i = 0; i < bufferIndex; i++)
    {
        printf("%x ", buffer[i]);
    }
    fclose(fr);

    FILE *fw = fopen(source, "wb");
    for (int i = 0; i < bufferIndex; i++)
    {
        fprintf(fw, "%x\n", buffer[i]);
        printf("%x ", buffer[i]);
    }
    fclose(fw);
    printf("\nwriting successful\n");
}
int main(int argc, char **argv)
{
    binaryFileMaker("dfg");
    binaryFileMaker("dfg2");
    binaryFileMaker("dfg3");
    pthread_t threadArr[argc];
    for (int i = 0; i < argc - 1; i++)
    {
        pthread_create(&threadArr[i], NULL, &binaryToDecimal, argv[i + 1]);
        pthread_join(threadArr[i], NULL);
    }
}