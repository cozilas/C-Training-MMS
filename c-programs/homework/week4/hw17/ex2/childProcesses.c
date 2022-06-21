#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>

void generateRandomString(){
    char str[10];
    for(int i = 0 ;i<10;i++){
        str[i] = 'A' + (rand()%26);
    }
    printf("%s\n",str);
}

int main(int argc,char* argv[]){  
     // printf("%d",atoi(argv[1]));
    
    for (int i = 0; i < atoi(argv[1]); i++){

        pid_t pid = fork();
        if (-1 == pid){
            perror("fork");
            return EXIT_FAILURE;
        }
        if (0 == pid){
            srand(time(NULL)+i);
            generateRandomString();
            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 0; i < atoi(argv[1]); i++){
        wait(NULL);
    }
    

    return EXIT_SUCCESS;
}




