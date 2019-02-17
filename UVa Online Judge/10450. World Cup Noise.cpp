#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int T;
    vector<long long> fib(51);
    
    fib[0] = 1;
    fib[1] = 2;

    for (int i = 2; i <= 50; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    scanf("%d", &T);
    for (int n, tc = 1; tc <= T; tc++) {
        scanf("%d", &n);
        printf("Scenario #%d:\n", tc);
        printf("%lld\n\n", fib[n]);
    }

    return 0;
}