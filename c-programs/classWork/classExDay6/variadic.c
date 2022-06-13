
#include <stdio.h>
#include <stdarg.h>
int AddNumbers(int n,...);
int main(){

    printf("%d\n", AddNumbers(2, 10, 5));
    return 0;
}

int AddNumbers(int n, ...)
{
    int Sum = 0;

    va_list ptr;
    va_start(ptr, n);
 
    for (int i = 0; i < n; i++){
 
        Sum += va_arg(ptr, int);
    }
    va_end(ptr);
 
    return Sum;
}