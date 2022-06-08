#include <stdio.h>
#include <stddef.h>
#include <limits.h>
int sumArray(const int *arr, size_t n);
void evaulateArray(int* arr,size_t n,int(*f)(int*,int));

int main()
{
    int arr[] = {1,1,-1,-1,1};
    int sum;
    sum = sumArray(arr, 5);
    if(sumArray(arr, 5)){
        printf("sumArray = %d\n",sum);
        int(*f)(int*,int) = &sumArray;
        evaulateArray(arr,5,f);
    }

    return 0;
}

int sumArray(const int *arr, size_t n)
{
    int sum = 0;
    for(int i = 0;i<n;i++){
        if(0<arr[i]){            
            sum+= arr[i];
              //printf("%d",sum);
        }
    }

    return sum;
}
void evaulateArray(int* arr,size_t n,int(*f)(int*,int)){

    printf("f = %d", f(arr,5));

}