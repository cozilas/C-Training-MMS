#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(){

    FILE *fr = fopen("readFrom.txt", "r");
    char ch;
    char line[150];
    int length;
/*     do{
    ch = fgetc(fr);
    printf("%c",ch);
    }while (ch!=EOF); */
    while ((fgets(line , sizeof(line),fr))!=NULL)
    {
        length = strlen(line);
        printf("%d\n",length);
        for(int i = length/2;i<length;i++){
            printf("%c",line[i]);
        }
    }
    

}