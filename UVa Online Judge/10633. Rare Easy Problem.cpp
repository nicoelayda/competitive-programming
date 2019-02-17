#include <cstdio>

int main() {
    unsigned long long nm;

    while (scanf("%llu", &nm) == 1 && nm != 0) {
        unsigned long long x = nm * 10;
        int prints = 0;

        for (int i = 9; i >= 0; i--) {
            if ((x - i) % 9 == 0) {
                if (prints++ != 0)
                    printf(" ");
                printf("%llu", (x - i) / 9);
            }
        }
        printf("\n");
    }
    return 0;
}