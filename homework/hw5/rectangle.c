#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
int rectangle(double a,double b,double*s,double*p);
int main(){

    double a,b,s,p;

while(scanf("%lf %lf",&a,&b) != EOF){
    if(a<0 || b<0){
        fprintf(stderr,"invalid rectangle sides!\n");
        continue;
    }
rectangle(a,b,&s,&p);
printf("s = %.2lf\np = %.2lf\n",s,p);


}
    return 0;
}

int rectangle(double a,double b,double*s,double*p){

    *s = a*b;
    *p = (a+b)*2;
    return 0;
}