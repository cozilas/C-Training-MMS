#include <stdio.h>
 int main(){
     unsigned int n1,n2,min;

     scanf("%u %u",&n1,&n2);

    if(n1 > n2){
    min = n2;
    }else min = n1;

    for(int i = min;i>0;i--){
        if(n1%i == 0 && n2%i == 0){
            printf("%d",i);
            break;
        }
    }
    return 0;

 }