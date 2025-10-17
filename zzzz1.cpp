#include <iostream>

int main()
{
    int n, m, k;

    std::cin >> n >> m >> k;
    
    if (n == 1) {
        std::cout << 1;
        return 0;
    }

    int a[n + 1];

    for (int i = 1; i <= n; i++) {
        a[i] = 1;
    }

    int n1 = n - 1;
    int i = m + k > n ? (m + k) % n : m + k;

    a[i] = 0;
    while (n1 != 1) {
        while (a[i] != 1) {
            i++;
            if (i > n) {
                i = 1;
            }
        }

        int in = i, k1 = 1;

        while (k1 != k) {
            i++;

            if (a[i] == 0) {
                continue;
            }

            if (i > n) {
                i = 1;
                while (a[i] != 1) {
                    i++;
                }
            }            
            k1++;
        }

        a[i] = 0;
        n1--;
    }

    for (i = 1; i <= n; i++) {
        if (a[i] == 1) {
            std::cout << i;
            break;
        }
    }

    return 0;
}