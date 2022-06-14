#include <stdio.h>

#define Max(x,y,z)((x>y && x>z)?x:(y>z)? y : z)
#define Min(x,y,z)((x<y && x<z)?x:(y<z)? y : z)
#define SETBIT(mask,bit)mask = mask|(1<<bit)
#define CLEARBIT(mask,bit)mask = mask&~(1<<bit)
#define TOGGLEBIT(mask,bit)mask = mask^(1<<bit)
#define CHECKBIT(mask,bit)mask = mask&(1<<bit)
#define SWAP(a,b){int temp = x;x=y;y=temp;}

int main(){
    unsigned mask = 123;
    int x=4;
    int y = 2;


    SWAP(x,y);
    printf("%d %d", x,y);
    return 0;
}