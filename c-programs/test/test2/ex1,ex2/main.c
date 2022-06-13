#include "car.h"
int main()
{
    srand(time(NULL));
    Car cars[COUNT];
     for (int i = 0; i < COUNT; i++)
    {
        randomName(cars[i].model);
        cars[i].maxSpeed = randint(100, 300);
        cars[i].price = randReal(1000.00, 100000.00);
    }

    printCars(cars);
    int opt;
    scanf("%d", &opt);

    comparef_t cp = getComparator(opt);
    
    qsort(cars, COUNT, sizeof(cars[0]),cp);
    printCars(cars);

    return 0;
}
