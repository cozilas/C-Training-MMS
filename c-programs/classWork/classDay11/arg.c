#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// suma
int main(int argc, char** argv){
    double sum = 0;
    if (!strcmp(argv[1], "-s")){
        for (int i = 2; i < argc; i++){
            double num;
            sscanf(argv[i], "%lf", &num);
            sum += num;
        }
        printf("Sum = %.2lf\n", sum);
    } else if (!strcmp(argv[1], "-M")){
        double max;
        sscanf(argv[2], "%lf", &max);
        for (int i = 3; i < argc; i++){
            double num;
            sscanf(argv[i], "%lf", &num);
            max = (num > max) ? num : max;
        }
        printf("Max = %.2lf\n", max);
    } else if (!strcmp(argv[1], "-m")){
        double min;
        sscanf(argv[2], "%lf", &min);
        for (int i = 3; i < argc; i++){
            double num;
            sscanf(argv[i], "%lf", &num);
            min = (num < min) ? num : min;
        }
        printf("min = %.2lf\n", min);
    }else if (!strcmp(argv[1], "-a")){
        double avr = 0;
        sscanf(argv[2], "%lf", &avr);
        for (int i = 3; i < argc; i++){
            double num;
            sscanf(argv[i], "%lf", &num);
           avr += num;
        }
        avr/= (argc-2);
        printf("average = %.2lf\n", avr);
    }
    return 0;
}