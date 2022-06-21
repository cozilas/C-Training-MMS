#include <stdio.h>
#include <string.h>
void Reverse(char* str);
int sizeOfArr(char * str);

int main()
{
    char str[] = "This is a test"; 
    Reverse(str);



    return 0;
}

void Reverse(char* str){
    unsigned size = sizeOfArr(str);
    char temp[size];
    for(int i = 0;*str != '\0';i++){
      temp[size-1 - i] = *(str);
      str++;
   }
    temp[size+1] = '\0';
    printf("%s",temp);

}
int sizeOfArr(char * str){
    int i= 0;
    while(*str!='\0'){
        i++;
        str++;
    }
    return i;
}