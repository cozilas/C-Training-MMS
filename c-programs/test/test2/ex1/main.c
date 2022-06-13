#include "car.h"
int main()
{
       comparef_t compfunc[] = {
          compModelASC, 
          compModelDESC,
          compMaxSpeedASC,
          compMaxSpeedDESC,
          compPriceASC,
          compPriceDESC
};
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
    do{    scanf("%d", &opt);
    }while(opt<0 || opt>6);
    
    qsort(cars, COUNT, sizeof(cars[0]), compfunc[opt]);
  printCars(cars);

    return 0;
}
