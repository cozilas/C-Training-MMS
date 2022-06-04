#include <stdio.h>
 int main(){
     char sym = 0, prevSym = 0;
    
    while(sym != 'A'){
        prevSym = sym;
        scanf("%c", &sym);
        if(sym != ' ' || prevSym != ' '){
             printf("%c",sym);

        }
    }


    return 0;

 }