#include <stdio.h>
#include <math.h>
int main() {
long double volume,radius,height,length,area;

printf("input radius:");
scanf("%Lf",&radius);
printf("input height:");
scanf("%Lf",&height);
printf("input length:");
scanf("%Lf",&length);

area=acos((radius-height)/radius)*pow(radius,2)-(radius-height)*sqrt(2*radius*height-pow(height,2));

volume = area * length;

printf("volume = %Lf",volume);
    return 0;
}