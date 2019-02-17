#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, num;
    
    while (scanf("%d", &n) == 1 && n != 0) {
        int sum = 0, highest_streak = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            sum = max(0, sum + num);
            highest_streak = max(sum, highest_streak);
        }

        if (highest_streak > 0)
            printf("The maximum winning streak is %d.\n", highest_streak);
        else
            printf("Losing streak.\n");
    }

    return 0;
}