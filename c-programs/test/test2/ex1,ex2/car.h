#ifndef _Car_H__
#define _Car_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdint.h>

#define COUNT 10

typedef int (*comparef_t)(const void *, const void *);
int (*getComparator(int n))(const void *, const void *);


typedef struct Car
{
    char model[21];
    uint8_t maxSpeed;
    double price;
} Car;
int compModelASC(const void *, const void *);
int compModelDESC(const void *, const void *);
int compMaxSpeedASC(const void *bp1, const void *bp2);
int compMaxSpeedDESC(const void *bp1, const void *bp2);
int compPriceASC(const void *bp1, const void *bp2);
int compPriceDESC(const void *bp1, const void *bp2);

int randint(int min, int max);
double randReal(double min, double max);
char *randomName(char *name);
void printCar(const Car *);
void printCars(const Car *books);
comparef_t getfun(const int);

#endif