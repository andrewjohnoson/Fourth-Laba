#include <stdio.h>

int main()
{
    char input[100];

    long n = 0;

    while (1) {
        fgets(input, sizeof(input), stdin);
        int t = 1;
        for (int i = 0; input[i] != '\n'; i++) {
            if (input[i] <= '/' || input[i] >= ':') {
                printf("У вас ошибка. Повторите ввод\n");
                t = 0;
                break;
            } else {
                n = n * 10 + (input[i] - '0');
            }
        }

        
        if (t == 1) {
            break;
        }
    }

    printf("Ввод правильный %ld", n);
    return 0;
}