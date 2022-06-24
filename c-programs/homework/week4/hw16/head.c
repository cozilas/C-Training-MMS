#include<stdio.h>

void main(int argc , char *argv[])
{
   
               FILE  *file;

               char *line[100];
               int count = 0;
               file  =  fopen(argv[1],"r");

                while(fscanf(file , "%[^\n]\n" , line)!=EOF)
              {

                         if(count  == 10)
                         {
                                 break;
                         }
                         else
                         {
                                 printf("%s\n" ,  line);
                          }
                          count++;
             }

             fclose(file);
}
