#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

const int V = 20;
const int INF = 1 << 28;

int main() {
    int n, tc = 0;

    while (scanf("%d", &n) == 1) {
        vector< vector<int> > dist(V, vector<int>(V, INF));

        for (int i = 0; i < V; i++)
            dist[i][i] = 0;

        for (int v, u = 0; u < 19; u++) {
            if (u != 0)
                scanf("%d", &n);

            for (int i = 0; i < n; i++) {
                scanf("%d", &v);
                dist[u][v-1] = 1;
                dist[v-1][u] = 1;
            }
        }

        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int N;
        scanf("%d", &N);

        printf("Test Set #%d\n", ++tc);

        for (int i = 0; i < N; i++) {
            int source, dest;
            scanf("%d %d", &source, &dest);

            printf("%2d to %2d: %d\n", 
                    source, dest, dist[source-1][dest-1]);
        }

        printf("\n");
    }

    return 0;
}