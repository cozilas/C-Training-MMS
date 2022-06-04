#include <stdio.h>
#include <math.h>

  unsigned int class = 0;

// function to convert decimal to binary
void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for(int j = 0;j< 32 - i;j++){
        printf("0");
    }
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d",binaryNum[j]);
        printf("\n");
}

void markAsPresent(){
    int index;
 

  
    printf("enter student to mark as present: ");//mark as present
    scanf("%d", &index);

    class |= 1 << index;
    decToBinary(class);
    

}
void markAsApsent(){

    int index;

    printf("enter student to mark as upsent: ");//mark as upsent
    scanf("%d", &index);

    class &= ~(1 << index);
    decToBinary(class);
    
}

void checkApsences(){
int index = 0;

    printf("-----absences: ");


    for(int i = 31;i>=0;i--){
    if(!(class & (1<<(i)))) printf("%d ",i);
    }
 index = 0;

    printf("\n-----presents: ");


     for(int i = 31;i>=0;i--){
    if(class & (1<<(i)) )printf("%d ",i);
    }
    printf("\n");


}

void checkPresents(){
int index = 0;

    printf("-----presents: ");


     for(int i = 31;i>=0;i--){
    if(class & (1<<(i)) )printf("%d ",i);
    }
    
}

void changeStatus(){
    int index;

    printf("status edit: ");//mark as present
    scanf("%d", &index);

    class ^= 1 << index;
    decToBinary(class);
    

}
int main(){

    unsigned int attendance = 0;
    int option;
    while (1)
    {
        printf("1. Set attendance\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance info\n");
        printf("4. Change attendance\n");
        printf("5. Exit\n");
        scanf("%d", &option);
        if (option == 1)
        {
           markAsPresent();
        }
        else if (option == 2)
        {
             markAsApsent();
        }
        else if (option == 3)
        {
             checkApsences();
        }
               
               else if (option == 4)
        {
              changeStatus();
        }else if (option == 5){
            break;
        }

        // to do
    }
    return 0;

    //markAsPresent();
  //  markAsApsent();
  //  checkApsences();
  //  checkPresents();
  //  changeStatus();
    return 0;
}