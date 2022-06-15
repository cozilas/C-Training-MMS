#include <stdio.h>

int sum(int n){
    return n + 1;
}

void map(const int* array,int(*func)(int)){
    for(int i = 0;i<7;i++){
        printf("%d",func(array[i]));
    }
}
int main(){
int arr[] = {1,2,3,4,5,6,7};
int(*fn)(int);
fn = &sum;
map(arr,fn);
}