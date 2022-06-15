#include <stdio.h>
#include <ctype.h>

int main(){

    double num1,num2,answer;

    char oper;
while(scanf("%lf",&num1) != EOF){
    

    scanf("%c %lf",&oper,&num2);

    if(!(oper == '*' ||oper == '/' ||oper == '-' ||oper == '+')){
    fprintf(stderr,"incorect input");
    }else if(oper == 42)
    printf("%.2lf", (num1*num2));
    else if(oper == 43)
    printf("%.2lf", (num1+num2));
    else if(oper == 47)
    printf("%.2lf", (num1/num2));
    else
    printf("%.2lf", (num1-num2));

}
    return 0;
}