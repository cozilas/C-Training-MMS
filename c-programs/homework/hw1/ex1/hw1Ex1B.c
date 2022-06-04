#include <stdio.h>
#include <math.h>
int main() {
double BMI, mass,height;

printf("input height:");
scanf("%lf",&height);
printf("input mass:");
scanf("%lf",&mass);

BMI = 1.3*(mass/pow(height,2.5));
    printf("BMI = %.2lf",BMI);
    return 0;
}