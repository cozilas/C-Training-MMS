#include <stdio.h>
#include <math.h>

unsigned int class = 0;

void changeStatus();
void checkPresents();
void checkApsences();
void markAsApsent();
void markAsPresent();
void printBits(unsigned int n);

int main()
{
    unsigned int attendance = 0;
    int option;

    unsigned int n = 14;

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
        }
        else if (option == 5)
        {
            break;
        }
    }

    return 0;
}

void printBits(unsigned int n)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%u", n & (1 << i) ? 1 : 0);
    }
    printf("\n");
}

void markAsPresent()
{
    int index;

    printf("enter student to mark as present: ");
    scanf("%d", &index);

    class |= 1 << index;
    printBits(class);
}

void markAsApsent()
{

    int index;

    printf("enter student to mark as upsent: ");
    scanf("%d", &index);

    class &= ~(1 << index);
    printBits(class);
}

void checkApsences()
{
    int index = 0;

    printf("-----absences: ");

    for (int i = 31; i >= 0; i--)
    {
        if (!(class & (1 << (i))))
            printf("%d ", i);
    }
    index = 0;

    printf("\n-----presents: ");

    for (int i = 31; i >= 0; i--)
    {
        if (class & (1 << (i)))
            printf("%d ", i);
    }
    printf("\n");
}

void checkPresents()
{
    int index = 0;

    printf("-----presents: ");

    for (int i = 31; i >= 0; i--)
    {
        if (class & (1 << (i)))
            printf("%d ", i);
    }
}

void changeStatus()
{
    int index;

    printf("status edit: ");
    scanf("%d", &index);

    class ^= 1 << index;
    printBits(class);
}