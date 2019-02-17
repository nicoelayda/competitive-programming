#include <cstdio>

using namespace std;

int main() {
    int r, n, t = 0;
    while (scanf("%d %d", &r, &n) == 2 && r != 0 && n != 0) {
        int required = r <= n ? 0 : r / n;

        if (required > 0 && r % n == 0)
            required -= 1;

        if (required <= 26)
            printf("Case %d: %d\n", ++t, required);
        else
            printf("Case %d: impossible\n", ++t);
    }
    return 0;
}