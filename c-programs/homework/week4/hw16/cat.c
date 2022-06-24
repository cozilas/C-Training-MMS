#include<stdio.h>

void main(int argc , char *argv[])
{
                FILE *file;
               char line[100];
             
               file = fopen(argv[1],"r");
       
                printf("output of cat command\n");

               while(fscanf(file,"%[^\n]\n",line)!=EOF)
               {

                              printf("%s\n", line);
               }
               fclose(file);
}