#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

   void printBoolsDuos(int a,int b){

      printf("%d^%d   = %d\n",a,b,(a ^ b));
    }
 void printBoolsTrios(int a,int b,int c){
      printf("%d^%d^%d = %d\n",a,b,c,(a ^ b ^ c));
    }

int main(){
    FILE* fp = fopen("numbers.txt","r");
    int a,b;
    int numberFromList;
    int length = 0;
    char curr;
    char bools[3];
    
    printf("enter first bool\n");
    scanf("%d",&a);
    printf("enter second bool\n");
    scanf("%d",&b);

    printf("%d^%d   = %d\n\n",a,b,(a ^ b));
    

    if(fp == NULL){
        return 1;
    }

    printf("read from numbers.txt :\n");
    while(!feof(fp)){    

      curr = getc(fp);
      fscanf(fp,"%d",&numberFromList);
      bools[length] = numberFromList;
      length++;
      if(curr =='\n'){
      if(length == 2){
      printBoolsDuos(bools[0],bools[1]);
      length = 0;
      }else {
        printBoolsTrios(bools[0],bools[1],bools[2]);
        length = 0;
      }
      
      }
     
    }

    
    return 0;
}