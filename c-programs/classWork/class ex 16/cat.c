#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,char* argv[]){

    if(!strcmp(argv[1],"cat")){
        printf("%s",argv[1]);
    }
    int fr = open(argv[1],0_RDONLY);

    return 0;
}