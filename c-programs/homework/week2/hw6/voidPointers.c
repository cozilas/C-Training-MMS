#include <stdio.h>
#include <stdlib.h>

#define TINT 1
#define TCHAR 2
#define TDOUBLE 3
#define TFLOAT 4
#define TUINT8 5
#define TUINT16 6
#define TUINT32 7
#define TUINT64 8

void printValue(const void* valuePtr, __uint8_t flag);

int main(){
    int num = 23;
    printValue(&num, TINT);

    double num2 = 3.14;
    printValue(&num2,TDOUBLE);

    char symbol = 'A';
    printValue(&symbol,TCHAR);
}
void printValue(const void* valuePtr, __uint8_t flag){
    if(flag == 1){
        printf("%d\n", *((int*)valuePtr));
    }else if (flag == 2){
        printf("%c\n", *(((char*)valuePtr)));
    }else if (flag == 3){
       printf("%lf\n", *(((double*)valuePtr)));
    }else if (flag == 4){
       printf("%f\n", *( ((float*)valuePtr)));
    }else if (flag == 5){
       printf("%u\n", *( ((u_int8_t*)valuePtr)));
    }else if (flag == 6){
       printf("%u\n", *( ((u_int16_t*)valuePtr)));
    }else if (flag == 7){
      printf("%lu\n", *(  ((u_int32_t*)valuePtr)));
    }else if (flag == 8){
      printf("%llu\n", *(  ((u_int64_t*)valuePtr)));
    }
}