#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int triangle(double a,double b,double c,double*s,double*p);
int main(){

    double a,b,c,s,p;


while(scanf("%lf %lf %lf",&a,&b,&c) != EOF){
    if(!triangle(a,b,c,&s,&p)){
        printf("s = %.2lf\np = %.2lf\n",s,p);
    }else{
        fprintf(stderr,"invalid triangle sides!\n");
    }

}
    return 0;
}

int triangle(double a,double b,double c,double*s,double*p){
    if(a<0 || b<0 || c<0){       
        return -1;
    }else{
    *p = a+b+c;
    *s = *p/2;
    
    return 0;
    }
}