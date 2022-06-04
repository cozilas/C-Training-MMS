#include <stdio.h>
#include <inttypes.h>

int main(){
    uint64_t mask = 2005ul;

    for(int i = 63;i>=0;i--){
        if(!!(mask &(1ul<<i)))
        printf("%u",!!(mask &(1ul<<i)));
    }
    return 0;
}