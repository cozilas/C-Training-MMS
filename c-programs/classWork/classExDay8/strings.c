#include <stdio.h>
#include <string.h>

void copyString(char s1[],char s2[]){
int i =0;
printf("%lu",sizeof(s1));
    while(s1[i]!= '\0'){
        s1[i] = s2[i];
        i++;
    }
}

int main(){
    char s1[] = "hello world";
    char s2[] = "christos";

    copyString(s1,s2);
    printf("s1 = %s \ns2 = %s\n",s1,s2);
}