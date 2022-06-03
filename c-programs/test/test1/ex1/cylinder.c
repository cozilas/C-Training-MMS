#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int cylinder(double a,double b,double*v,double*s);
int main(){

    double a,b,s,v;

while(scanf("%lf %lf",&a,&b) != EOF){
   
    if(cylinder(a,b,&s,&v)){
        fprintf(stderr,"invalid input!\n");    
    }else{          
        printf("s = %.2lf\np = %.2lf\n",s,v);    
    }
}
    return 0;
}

int cylinder(double a,double b,double*v,double*s){

 if(a<0 || b<0){
        return 1;
    }else{
        *v = M_PI *pow(a,2)* b;
        *s = 2*M_PI*a *b +2*M_PI*pow(a,2);
    return 0;
    }
    
}
