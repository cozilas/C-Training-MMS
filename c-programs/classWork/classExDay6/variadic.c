#include <stdio.h>
#include <stdarg.h>
#include <float.h>


int sumNums(unsigned,...);
double maxNum(unsigned, ...);
double minNum(unsigned, ...);

void simple_printf(const char*, ...);
int sumPos(int num1, ...);
double biggest(double n, ...);

int main(){
  //  printf("%d\n", sumNums(4, 10, 20, 30, 40));
  //  printf("%d\n", sumNums(3, 5, 5, 5));
    //printf("%d\n", sumNums(2, 10, -2));
   // simple_printf("dcff", 3, 'a', 1.999, 42.5); 
 //   printf("%d\n", sumPos(1, 10, -45));
    printf("%lf",biggest(6.0,6.0,3.0,4.0,5.0,2.0,2.0));


    return 0;
}
double biggest(double n, ...){
    double biggest = DBL_MIN;
    va_list argl;
    va_start(argl, n);
    for (int i = 0; i < n; i++){        
        if(biggest< va_arg(argl,double)){
            printf("  %lf",va_arg(argl,double));
            biggest = va_arg(argl,double);
        }
    }
    va_end(argl);
    return biggest;
}
int sumNums(unsigned n, ...){
    int sum = 0;
    va_list argl;
    va_start(argl, n);
    for (int i = 0; i < n; i++){
        sum += va_arg(argl, int);
    }
    va_end(argl);
    return sum;
}



void simple_printf(const char* fmt, ...){
    va_list args;
    va_start(args, fmt);

    while (*fmt != '\0') {
        if (*fmt == 'd') {
            int i = va_arg(args, int);
            printf("%d\n", i);
        } else if (*fmt == 'c') {
            // A 'char' variable will be promoted to 'int'
            // A character literal in C is already 'int' by itself
            int c = va_arg(args, int);
            printf("%c\n", c);
        } else if (*fmt == 'f') {
            double d = va_arg(args, double);
            printf("%f\n", d);
        }
        ++fmt;
    }
    va_end(args);
}

int sumPos(int num1, ...){
    int sum = 0, n;
    if (num1 > 0){
        sum = num1;
    } else {
        return 0;
    }
    va_list args;
    va_start(args, num1);
    while ((n = va_arg(args, int)) > 0){
        sum += n;
    }
    va_end(args);
    return sum;
}