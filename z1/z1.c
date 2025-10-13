#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main()
{
    setlocale(LC_ALL, "rus");
    char *endptr;
    char input[100];

    errno = 0;

    printf("Введите размер массива (n < 1000000):\n");
    long n;

    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        n = strtol(input, &endptr, 10);
        
        if (*endptr != '\0' || errno == ERANGE) {
            printf("Введено некорректное значение.\n");
            errno = 0;
            continue;
        }

        if (n <= 0 || n > 1000000) {
            printf("Размер массива должен быть числом натуральным и не больше 1000000.\n");
        } else {
            break;
        }
    }
    
    printf("\n");

    double a[1000001], sum = 0, pr = 1; // так как язык программирования С не умеет работать с динамическим объявлением массива, то мы объявляем массив с каким-то большм размером
    printf("Введите элементы массива:\n");
    for (int i = 1; i <= n; i++) {
        while (1) {
            printf("a[%d] = ", i);
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
            a[i] = strtof(input, &endptr);

            if (*endptr != '\0' || errno == ERANGE) {
                printf("Введено некорректное значение.\n");
                errno = 0;
            } else {
                break;
            }
        }
        sum += a[i]; // сразу при вводе переменных, с той целью чтобы не тратить лишнее время,
        pr *= a[i]; // мы сразу в цикле посчитаем значение суммы и произведения всех эл-тов массива
    }

    printf("\n");

    int imin = 1, imax = 1;
    for (int i = 2; i <= n; i++) {
        if (a[imin] > a[i]) {
            imin = i;
        }
        if (a[imax] < a[i]) {
            imax = i;
        }
    }

    printf("Максимальный элемент - %lf, минимальный элемент - %lf\n", a[imax], a[imin]);
    printf("\n");
    
    printf("Массив до того, как мы поменяли максимальный и минимальный элементы местами:\n");
    for (int i = 1; i <= n; i++) {
        printf("a[%d] = %lf\n", i, a[i]);
    }

    printf("\n");

    double temp = a[imin]; // чтобы сохранить значение наименьшего элемента массива, мы создаём временную переменную, которая и будет хранить это значение
    a[imin] = a[imax]; // присваиваем элементу, где стояло минимальное значение максимальное значение
    a[imax] = temp; // присваиваем элементу, где стояло максимальное значение минимальное значение в переменной temp, т.о. поменяв местами максимальное и минимальное значение

    printf("Массив после того, как мы поменяли максимальный и минимальный элементы местами:\n");
    for (int i = 1; i <= n; i++) {
        printf("a[%d] = %lf\n", i, a[i]);
    }

    printf("\n");
    printf("Сумма элементов массива: %lf\nПроизвдение элементов массива: %lf", sum, pr);
    return 0;
}