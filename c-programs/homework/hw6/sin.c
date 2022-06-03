#include <stdio.h>

double sin(double x);
int main(){
    double input;
scanf("%lf",&input);
input = sin(input);
    printf("%f",input);
}

double sin(double x) //sin calculation
{
double sum;
double fa;
double pow;
sum = 0.0;
for(int i = 0; i <= 20; i++)
{
fa = 1.0;
pow = 1.0;
for(int j = 1; j <= 2*i+1; j++)
{
fa *= j;
pow *= x;
}
sum += ((i%2?-1.0:1.0)/fa)*pow;
}
return sum;
}