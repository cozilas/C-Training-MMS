#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int quadEquation(double a,double b,double c,double *x1,double *x2);
int main(int argc, char* argv[]){

    double a,b,c,s,p;
    a = strtod(argv[1],NULL);
    b = strtod(argv[2],NULL);
    c = strtod(argv[3],NULL);  

    quadEquation(a,b,c,&s,&p);
    


    return 0;
}

int quadEquation(double a,double b,double c,double *x1,double *x2){
    double discriminant = b * b -4 *a *c; 

    if(discriminant > 0){
        *x1 = (-b - sqrt(discriminant)) /(2*a);
        *x2 = (-b + sqrt(discriminant)) /(2*a);
        printf("x1 = %.2lf \nx2 = %.2lf",*x1,*x2);
    }else if (discriminant == 0){
        *x2 = *x1 = -b/(2*a);
        printf("x1 = %.2lf \nx2 = %.2lf",*x1,*x2);
    }else{
        printf("no real roots");
    }
    printf("\n");

    return 0;
}
