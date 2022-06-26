#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>

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
int binaryFileSum(char *source)
{

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
    return sum;
}
int main(int argc, char *argv[])
{
    fflush(stdout);
    int fd[2];  // p->c
    int fd2[2]; // c->p
    if (pipe(fd) == -1)
    {
        perror("pipe");
        return EXIT_SUCCESS;
    }
    // int sump = 0;
int sumAll = 0;
    for (int i = 1; i < argc; i++)
    {
        pid_t pid = fork();

        if (pid == 0)
        {
            close(fd[0]);
            int sump=0;
            sump = binaryFileSum(argv[i]);
            write(fd[1],&sump,sizeof(sump));
            close(fd[1]);

            // printf("%d\n",sump);
            return EXIT_SUCCESS;
        }else{
            close(fd[1]);
            int sum=0;
            read(fd[0],&sum,sizeof(int));
            printf("%d\n",sum);
            close(fd[0]);
            sumAll += sum;
        }
    }
    printf("%d\n", sumAll);
    for (int i = 0; i < argc - 1; i++)
    {
        wait(NULL);
    }

    return EXIT_SUCCESS;
}
/* int main(int argc, char **argv)
{
    binaryFileMaker("dfg");
    binaryFileMaker("dfg2");
    binaryFileMaker("dfg3");

    binaryFileSum(argv[1]);

} */