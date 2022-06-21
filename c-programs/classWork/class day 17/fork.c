

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>

int digitalRoot(char num[]){
    int len = strlen(num);
    int ans = 0;
    for(int i = 0;i<len;i++){
        ans = 1 +(ans + (num[i] - '0')-1)%9;
    }
    return ans;
}

int main(int argc,char* argv[]){  
    for (int i = 0; i < argc-1; i++){
        pid_t pid = fork();
        if (-1 == pid){
            perror("fork");
            return EXIT_FAILURE;
        }
        if (0 == pid){
            printf(" %d\n",digitalRoot(argv[i+1]));
            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 0; i < argc-1; i++){
        wait(NULL);
    }
    printf("\nbye bye\n");

    return EXIT_SUCCESS;
}




