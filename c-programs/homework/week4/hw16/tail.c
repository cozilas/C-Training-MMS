#include<stdio.h>
#include<string.h>

// creating stack of lines
struct stack
{
          char strings[100];
};


 void main(int argc , char *argv[])
{

             // stucture initialisation    
              struct stack s[100];

              FILE *file;
              char line[100];
         
              int n,count=0, i=0;

              file  = fopen(argv[1] , "r");
         
              // reading line by line and push to stack
              while(fscanf(file , "%[^\n]\n" , line)!=EOF)
              {
                             strcpy(s[i].strings , line);
                             i++;
                             n=i;
               }

               // pop line by line
               for(i=n;i>0;i--)
               {
                        // last 10 lines  
                         if(count == 10)
                               break;
                         else
                               printf("%s\n" , s[i].strings);
                         count++;
               }
}
