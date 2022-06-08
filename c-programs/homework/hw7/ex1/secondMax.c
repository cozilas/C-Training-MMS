#include <stdio.h>
#include <stddef.h>
#include <limits.h>
int secondMax(const int *arr, size_t n, int *sm);

int main()
{
    int sm;

    int arr[] = {1,1,1,1,1};

    if(!secondMax(arr, 0, &sm)){
        printf("%d is the second biggest",sm);
    }

    return 0;
}

int secondMax(const int *arr, size_t n, int *sm)
{
    *sm = INT_MIN;
    int fm = *arr;
    if(n == 0){
        fprintf(stderr,"empty array!");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (fm < arr[i])
        {
            *sm = fm;
            fm = arr[i];
        }
        if(i == n-1 && *sm == INT_MIN){
            fprintf(stderr,"all elements are the same");
            return 1;
        }        
    }
    for(int i = 0;i<n;i++){
        if(fm>arr[i]){
            *sm = fm;
            fm = arr[i];
        }
    }
    return 0;
}