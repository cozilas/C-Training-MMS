
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randint(int, int);
double randReal(double, double);

void makeName(char *name)
{
    *name = randint('A', 'Z');
    int r = randint(5, 10);
    for (int i = 1; i < r; i++)
    {
        name[i] = randint('a', 'z');
    }
    name[r] = ' ';
    r++;
    name[r] = randint('A', 'Z');
    r++;
    int j = r;
    r += randint(5, 10);

    for (int i = j; i < r; i++)
    {
        name[i] = randint('a', 'z');

    }
}
struct name{
    double hello;
    
};

int main()
{
    srand(time(NULL));
    char name[24];
    makeName(name);
    printf("%s\n", name);


    return 0;
}

int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}