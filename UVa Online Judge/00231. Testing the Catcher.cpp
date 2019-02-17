#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, tc = 0;

    while (scanf("%d", &n) == 1 && n != -1) {
        if (tc != 0)
            printf("\n");

        vector<int> sequence;
        sequence.push_back(n);

        while (scanf("%d", &n) == 1 && n != -1) {
            sequence.push_back(n);
        }

        int size = sequence.size();
        int lis[size];
        int ans = 0;
        lis[0] = 1;
        
        for (int i = 1; i < size; i++) {
            lis[i] = 1;

            for (int j = i - 1; j >= 0; j--) {
                if (sequence[j] >= sequence[i]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }

            ans = max(ans, lis[i]);
        }
        printf("Test #%d:\n", ++tc);
        printf("  maximum possible interceptions: %d\n", ans);
    }

    return 0;
}