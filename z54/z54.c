#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

int main()
{
    setlocale(LC_ALL, "rus");
    double x[21];

    char input[100];
    char *endptr;
    errno = 0;
/*
    printf("Введите элементы массива:\n");
    for (int i = 1; i <= 20; i++) {
        while (1) {
            printf("x[%d] = ", i);
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
            x[i] = strtod(input, &endptr);

            if (*endptr != '\0' || errno == ERANGE) {
                printf("Введено некорректное значение.\n");
                errno = 0;
            } else {
                break;
            }
        }
    } */


    srand(time(0));
    for (int i = 1; i <= 20; i++) {
        x[i] = -10 + ((double) rand() / (RAND_MAX +1.0)) * 20;
    } 

    printf("Исходный массив:\n");
    for (int i = 1; i <= 20; i++) {
        printf("x[%d] = %lf\n", i, x[i]);
    }

    printf("\n");

    for (int i = 1; i <= 20; i++) {
        if (x[i] > 0) {
            x[i] *= x[i];
        }
        if (x[i] < 0) {
            x[i] *= 5;
        }
    }

    printf("Полученный массив:\n");
    for (int i = 1; i <= 20; i++) {
        printf("x[%d] = %lf\n", i, x[i]);
    }
    return 0;
}