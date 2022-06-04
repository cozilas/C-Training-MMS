#include <stdio.h>
#include <math.h>
int main() {
double BMI, mass,height;

printf("input height:");
scanf("%lf",&height);
printf("input mass:");
scanf("%lf",&mass);

BMI = mass/pow(height,2);
    printf("BMI = %lf",BMI);   

    return 0;
}