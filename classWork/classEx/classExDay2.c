#include <stdio.h>
#include <limits.h>

int main(){

    int num,maxNum = INT_MIN;

    while(scanf("%d",&num) != -1){
        if(num > maxNum) maxNum = num;
    }
    printf("%d\n",maxNum);
    return 0;
}