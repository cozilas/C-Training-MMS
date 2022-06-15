#include <stdio.h>
#include <stddef.h>
#include <limits.h>
int sumArray(const int *arr, size_t n);

int main()
{
    int arr[] = {1,1,-1,-1,1};

    if(!sumArray(arr, 5)){
        printf("%d = sum of all positives numbers in array",sumArray(arr, 5));
    }

    return 0;
}

int sumArray(const int *arr, size_t n)
{
    int sum = 0;
    for(int i = 0;i<n;i++){
        if(0<arr[i]){            
            sum+= arr[i];
        }
    }
    return sum;
}