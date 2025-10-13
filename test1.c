#include <stdio.h>

int main()
{
    float n;
    char extra;

    while (1) {
        if (scanf("%f%c", &n, &extra) != 2 || extra != '\n' || n <= 0) {
            printf("Некорректный ввод\n");
            continue;
        } else {
            break;
        }
    }

    printf("%f", n);
    return 0;
}