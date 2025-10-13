#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    float a[1000000], prNeg = 1, sumPos = 0;
    int n;

    printf("Введите размер массива:\n");
    if (scanf("%d", &n) != 1 || n <= 0) {
        puts("Размер массива должен быть числом натуральным!");
        return 0;
    }

    printf("\n");
    
    printf("Введите элементы массива:\n");
    for (int i = 1; i <= n; i++) {
        printf("a[%d] = ", i);
        if (scanf("%f", &a[i]) != 1) {
            puts("Элемент массива должен быть вещественным числом!");
            return 0;
        }

        if (a[i] < 0) {
            prNeg *= a[i];
        }
    }

    int imax = 1;
    for (int i = 2; i <= n; i++) {
        if (a[imax] < a[i]) {
            imax = i;
        }
    }

    for (int i = 1; i <= imax; i++) {
        if (a[i] > 0) {
            sumPos += a[i];
        }
    }

    printf("Произведение отрицательных чисел - %f,\nсумма положительных чисел, расположенных до элемента с максимальным значением - %f", prNeg, sumPos);
    return 0;
}