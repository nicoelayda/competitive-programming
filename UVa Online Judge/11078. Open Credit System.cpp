#include <algorithm>
#include <limits>
#include <cstdio>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T-- != 0) {
        int n;
        scanf("%d", &n);
        
        int junior, senior;
        int max_diff = numeric_limits<int>::min();

        scanf("%d", &senior);

        for (int i = 1; i < n; i++) {
            scanf("%d", &junior);
            max_diff = max(max_diff, senior - junior);
            senior = max(junior, senior);
        }

        printf("%d\n", max_diff);
    }

    return 0;
}