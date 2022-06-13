
#include "car.h"

int compModelDESC(const void *bp1, const void *bp2)
{
    Car *b1 = (Car *)bp1;
    Car *b2 = (Car *)bp2;
    return strcmp(b2->model, b1->model);
}
int compModelASC(const void *bp1, const void *bp2)
{
    Car *b1 = (Car *)bp1;
    Car *b2 = (Car *)bp2;
    return strcmp(b1->model, b2->model);
}

int compMaxSpeedASC(const void *bp1, const void *bp2)
{
    Car *b1 = (Car *)bp1;
    Car *b2 = (Car *)bp2;
    return b1->maxSpeed - b2->maxSpeed;
}

int compMaxSpeedDESC(const void *bp1, const void *bp2)
{
    Car *b1 = (Car *)bp1;
    Car *b2 = (Car *)bp2;
    return b2->maxSpeed - b1->maxSpeed;
}
int compPriceASC(const void *bp1, const void *bp2)
{
    Car *b1 = (Car *)bp1;
    Car *b2 = (Car *)bp2;
    if (fabs(b1->price - b2->price) < 0.001)
    {
        return 0;
    }
    else if (b1->price > b2->price)
    {
        return 1;
    }
    return -1;
}

int compPriceDESC(const void *bp1, const void *bp2)
{
    Car *b1 = (Car *)bp1;
    Car *b2 = (Car *)bp2;
    if (fabs(b1->price - b2->price) < 0.001)
    {
        return 0;
    }
    else if (b1->price < b2->price)
    {
        return 1;
    }
    return -1;
}
int (*getComparator(int n))(const void *, const void *){
     if(n<0 || n>6)return NULL;

    if(n == 1)return compModelASC;
    else if(n == 2)return compModelDESC;
    else if(n == 3)return compMaxSpeedASC;
    else if(n == 4)return compMaxSpeedDESC;
    else if(n == 5)return compPriceASC;
    else if(n == 6)return compPriceDESC;
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

char *randomName(char *name)
{
    unsigned index = 0;
    name[index++] = randint('A', 'Z');
    int n = randint(4, 10);
    for (int i = 0; i < n; i++)
    {
        name[index++] = randint('a', 'z');
    }
    name[index] = '\0';
    return name;
}

void printCar(const Car *c)
{
    printf("model: %11s ", c->model);
    printf("max speexd: %5d ", c->maxSpeed);
    printf("Price: %4.2lf\n", c->price);
}

void printCars(const Car *cars)
{
    for (int i = 0; i < COUNT; i++)
    {
        printCar(cars + i);
    }
}