#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>

int fileSum(char *source);
int getSumDigits(int n);
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
        {  // int sumPrev;
            //read(fd2[0],&sumPrev
            close(fd[0]);
            int sump=0;
            sump = fileSum(argv[i]);
            write(fd[1],&sump,sizeof(sump));
            close(fd[1]);

            return EXIT_SUCCESS;
        }else{
            close(fd[1]);
            int sum=0;
            read(fd[0],&sum,sizeof(int));
            close(fd[0]);
            sumAll += sum;
        }
    }
   // printf("sum%d\n", sumAll);
    for (int i = 0; i < argc - 1; i++)
    {
        wait(NULL);
    }

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
int fileSum(char *source)
{

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
    return sum;
}












































