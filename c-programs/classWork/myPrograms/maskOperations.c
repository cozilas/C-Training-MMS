#include <stdio.h>
#include <inttypes.h>
void print16b(uint16_t mask){
    for(int i = 15;i>=0;i--){
        printf("%d",!!(mask&(1<<i)));
    }
    printf("\n");
}

void mirrorMask(uint16_t* mask){    
    printf("%d\n",*mask);
    print16b(*mask);
    uint16_t mask2 = *mask;
    for(int i = 7;i>=0;i--){
    if(!!(*mask&(1<<i))){
        *mask = *mask|(1<<(i+8));
    }else *mask = *mask&(~(1<<(i+8)));
    }
    print16b(*mask);
}

int main()
{
    uint16_t mask = 3654;

    mirrorMask(&mask);

    return 0;
}


