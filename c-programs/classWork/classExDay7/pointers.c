#include <stdio.h>
#include <limits.h>

int main(){
    int arr[5];
    int min = INT_MAX;
    int max = INT_MIN;
    int sum = 0;
    for(int i = 0;i<5;i++){
        scanf("%d",arr + i);
    }
    for(int i = 0;i<5;i++){
        printf("%d\n",*(arr+i));
        sum += *(arr+i);
        if(*(arr+i) > max){
            max = *(arr+i);
        }
        if(*(arr+i) < min){
            min = *(arr+i);
        }

    }
    printf("sum = %d \nmax = %d\nmin = %d", sum,max,min);
    

    return 0;
}