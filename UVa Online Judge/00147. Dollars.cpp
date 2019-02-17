#include <algorithm>
#include <cstdio>

using namespace std;

int values[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
unsigned long long lookup[30001];

int main() {
    fill(lookup, lookup + sizeof(lookup)/sizeof(unsigned long long), 0);
    lookup[0] = 1;
    
    for (int i = 0; i < 11; i++) {
        for (int j = values[i]; j <= 30000; j++) {
            lookup[j] += lookup[j - values[i]];
        }
    }
    
    int dollars, cents;
    while (scanf("%d.%d", &dollars, &cents) == 2) {
        int i = dollars * 100 + cents;
        double n = i / 100.0;
        if (n == 0) break;

        printf("%6.2f%17llu\n", n, lookup[i]);
    }

    return 0;
}