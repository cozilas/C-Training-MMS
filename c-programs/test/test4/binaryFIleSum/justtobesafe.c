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
        fprintf(stderr,"%s-cant be found!\n",source); 
        return 0;
    }
    int num;
    int sum = 0;
    while (fread(&num, sizeof(num), 1, fr))
    {
     sum+=num;
    }
    printf("%s sum = %d\n",source,sum);
    fclose(fr);
    return sum;
}
int main(int argc,char* argv[]){      
     int fd[2];
    if (pipe(fd) == -1)
    {
        perror("pipe");
        return EXIT_SUCCESS;
    }

    for (int i = 1; i < argc; i++){
        pid_t pid = fork();
        if (-1 == pid){
            perror("fork");
            return EXIT_FAILURE;
        }
        printf("%d\n",pid);
        if (0 == pid){//child process
            int sumChild = 0;
            if(read(fd[0],&sumChild,sizeof(sumChild)) == -1){return 3;}
          //  sumChild+=binaryFileSum(argv[i]);
            if(write(fd[1],&sumChild,sizeof(sumChild))== -1){return 4;}
            
        }else{
            int sum=0;
            write(fd[1],&sum,sizeof(sum));
         //   printf("%d",sum);
        }
    }
    for (int i = 0; i < argc-1; i++){
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