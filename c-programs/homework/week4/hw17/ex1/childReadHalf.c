#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{

    pid_t pid = fork();
    if (-1 == pid)
    {
        perror("fork");
        return EXIT_FAILURE;
    }
    if (0 == pid)
    {
        int sum = 0;
        for (int i = 0; i <= (argc - 1) / 2; i++)
        {
            sum += atoi(argv[i]);
        }
        printf("process 1 sum:%d/n",sum);
        exit(EXIT_SUCCESS);
    }
    else
    {
        int sum = 0;
        for (int i = ((argc-1) / 2)+1; i < argc ; i++)
        {
            sum += atoi(argv[i]);
        }
        printf("process 2 sum:%d",sum);
        exit(EXIT_SUCCESS);
    }

    for (int i = 0; i <argc-1; i++)
    {
        wait(NULL);
    }

    return EXIT_SUCCESS;
}
