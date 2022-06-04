#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main(){
    FILE* fp = fopen("numbers.txt","r");
    int num = INT_MIN;
    int numberFromList;
    if(fp == NULL){
        return 1;
    }

    while(!feof(fp)){         
         fscanf(fp,"%d",&numberFromList);
         if(numberFromList>num) num = numberFromList;
        
    }
    printf("%d\n",num);
    
    return 0;
}