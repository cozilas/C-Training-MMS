#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("pipe");
        return EXIT_SUCCESS;
    }
    pid_t pid = fork();

    if (0 == pid)
    {
        close(fd[0]);
        int x = 1;
        x = system(argv[1]);
        write(fd[1], &x, sizeof(int));
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int flagy;
        read(fd[0], &flagy, sizeof(int));
        if (flagy != 0)
        {
            system(argv[3]);
        }
        close(fd[0]);
        wait(NULL);
    }
    exit(EXIT_SUCCESS);

    return EXIT_SUCCESS;
}
