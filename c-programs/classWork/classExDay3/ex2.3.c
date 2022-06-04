#include <stdio.h>
#include <math.h>
 int main(){
     int a,b,min,temp;

     scanf("%u %u",&a,&b);

    while(b!=0 && a!=0){
      if(a<b){
          temp = a;
          a = b;
            b = temp;
      }
      a = a%b;
    }
    printf("%d",b);
    return 0;

 }