#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int k;
    bool first = true;

    while(scanf("%d", &k) == 1 && k != 0) {
        vector<int> picks(k);

        if (first)
            first = false;
        else
            printf("\n");

        for (int i = 0; i < k; i++)
            scanf("%d", &picks[i]);

        for (int a = 0; a < picks.size() - 5; a++) {
            for (int b = a + 1; b < picks.size() - 4; b++) {
                for (int c = b + 1; c < picks.size() - 3; c++) {
                    for (int d = c + 1; d < picks.size() - 2; d++) {
                        for (int e = d + 1; e < picks.size() - 1; e++) {
                            for (int f = e + 1; f < picks.size(); f++) {
                                printf("%d %d %d %d %d %d\n", picks[a], picks[b], picks[c], picks[d], picks[e], picks[f]);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}