#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "rus");
    float a[1000001], prNeg = 1, sumPos = 0;
    long n;

    char input[100];
    char *endptr;

    errno = 0;

    printf("Введите размер массива (n < 1000000):\n");
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
    
    printf("Введите элементы массива:\n");
    /*for (int i = 1; i <= n; i++) {
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

        if (a[i] < 0) {
            prNeg *= a[i];
        }
    } */

    srand(time(0));
    for (int i = 1; i <= n; i++) {
        a[i] = ((float) rand() / (RAND_MAX + 1.0)) * 20 - 10;
        if (a[i] < 0) {
            prNeg *= a[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("a[%d] = %f\n", i, a[i]);
    }

    printf("\n");

    int imax = 1;
    for (int i = 2; i <= n; i++) {
        if (a[imax] < a[i]) {
            imax = i;
        }
    }

    for (int i = 1; i < imax; i++) {
        if (a[i] > 0) {
            sumPos += a[i];
        }
    }

    printf("Произведение отрицательных чисел - %f,\nсумма положительных чисел, расположенных до элемента с максимальным значением - %f", prNeg, sumPos);
    return 0;
}