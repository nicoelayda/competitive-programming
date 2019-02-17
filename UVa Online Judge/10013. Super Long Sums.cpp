#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int T;
    vector<int> sum(1000002, 0);

    scanf("%d", &T);

    while (T-- != 0) {
        int digits;
        int n1, n2;
        bool first_nonzero = false;

        scanf("%d", &digits);
        
        for (int i = 0; i < digits; i++) {
            scanf("%d %d", &n1, &n2);
            sum[i] = n1 + n2;
        }

        for (int i = digits - 1; i >= 0; i--) {
            if (sum[i] >= 10 && i != 0) {
                sum[i] %= 10;
                sum[i - 1] += 1;
            }
        }
        
        for (int i = 0; i < digits; i++) {
            if (first_nonzero || sum[i] != 0) {
                printf("%d", sum[i]);
                first_nonzero = true;
            }
        }
        
        printf("\n");

        if (T != 0)
            printf("\n");
    }

    return 0;
}