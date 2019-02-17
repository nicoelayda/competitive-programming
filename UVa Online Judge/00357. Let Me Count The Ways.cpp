#include <cstdio>
#include <cstring>

using namespace std;

int values[5] = {1, 5, 10, 25, 50};
unsigned long long lookup[30001];

int main() {
    memset(lookup, 0, sizeof(lookup));
    lookup[0] = 1;

    for (int i = 0; i < 5; i++) {
        for (int j = values[i]; j <= 30000; j++) {
            lookup[j] += lookup[j - values[i]];
        }
    }

    int n;
    while (scanf("%d", &n) == 1) {
        if (lookup[n] == 1)
            printf("There is only 1 way to produce %d cents change.\n", n);
        else
            printf("There are %llu ways to produce %d cents change.\n", lookup[n], n);
    }
    return 0;
}