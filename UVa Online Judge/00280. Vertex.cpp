#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int V;

    while (cin >> V && V != 0) {
        int u, v;
        vector<int> adj_list[V];

        while (cin >> u && u != 0) {
            while (cin >> v && v != 0) {
                adj_list[u - 1].push_back(v - 1);
            }
        }

        int n;
        cin >> n;

        while (n-- != 0) {
            int start;
            cin >> start;
            start--;

            queue<int> fringe;
            vector<bool> visited(V, false);

            fringe.push(start);

            int unvisited = V;

            while (!fringe.empty()) {
                u = fringe.front(); fringe.pop();

                for (int i = 0; i < adj_list[u].size(); i++) {
                    v = adj_list[u][i];

                    if (!visited[v]) {
                        unvisited--;
                        visited[v] = true;
                        fringe.push(v);
                    }
                }
            }

            cout << unvisited;
            for (int i = 0; i < V; i++) {
                if (!visited[i])
                    cout << " " << (i + 1);
            }
            cout << endl;
        }
    }

    return 0;
}