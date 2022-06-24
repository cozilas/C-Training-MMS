#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

void threadMaker(char* msg){
     printf("thread#%d MSG = %s  \n",getpid(),msg);
}
void makeProcess(int threadCount,char* msg,pid_t pidID){
    pthread_t threadArr[threadCount];
    for(int i = 0 ;i<threadCount;i++){
    pthread_create(&threadArr[i], NULL, &threadMaker, msg);
    pthread_join(threadArr[i], NULL);
    }
    printf("process#%d MSG = %s  \n",pidID,msg);
}
int main(int argc,char* argv[]){  
    
    for (int i = 0; i < atoi(argv[1]); i++){

        pid_t pid = fork();
        if (-1 == pid){
            perror("fork");
            return EXIT_FAILURE;
        }
        if (0 == pid){
            srand(time(NULL)+i);
            makeProcess(atoi(argv[2]),argv[2],pid);
            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 0; i < atoi(argv[1]); i++){
        wait(NULL);
    }
    

    return EXIT_SUCCESS;
}



