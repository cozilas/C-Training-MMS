#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
int cylinder(double a,double b,double*v,double*s);
int main(){

    double a,b,s,v;

while(scanf("%lf %lf",&a,&b) != EOF){
    if(a<0 || b<0){
        fprintf(stderr,"invalid input!\n");
        continue;
    }
    if(!cylinder(a,b,&s,&v)){
    printf("s = %.2lf\np = %.2lf\n",s,v);    
    }else{
          fprintf(stderr,"errror!\n");
    }


}
    return 0;
}

int cylinder(double a,double b,double*v,double*s){

    *v = 3.14f *pow(a,2)* b;
    *s = 2*3.14f*a *b +2*3.14f*pow(a,2);
    return 0;
}