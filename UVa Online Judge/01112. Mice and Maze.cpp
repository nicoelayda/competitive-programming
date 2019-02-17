#include <iostream>

using namespace std;

const int INF = 1 << 28;

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int n;
        int exit_vertex;
        int timer;
        int num_edges;

        cin >> n >> exit_vertex >> timer >> num_edges;

        int dist[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = INF;
            }

            dist[i][i] = 0;
        }

        for (int i = 0; i < num_edges; i++) {
            int u, v, cost;
            cin >> u >> v >> cost;

            dist[u - 1][v - 1] = cost;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int escaped = 0;

        for (int i = 0; i < n; i++) {
            if (dist[i][exit_vertex - 1] <= timer)
                escaped += 1;
        }

        cout << escaped << endl;

        if (T != 0)
            cout << endl;
    }

    return 0;
}