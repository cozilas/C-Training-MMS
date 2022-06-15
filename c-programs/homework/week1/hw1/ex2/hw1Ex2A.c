#include <stdio.h>
#include <math.h>
int main() {
double volume,radius,height;

printf("input radius:");
scanf("%lf",&radius);
printf("input height:");
scanf("%lf",&height);

volume = 3.14*pow(radius,2)*height;
printf("volume = %lf",volume);
    return 0;
}