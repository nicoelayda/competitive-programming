#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int V, E;
    int tc = 0;

    while (cin >> V && V != 0) {
        int s, t;
        cin >> s >> t >> E;

        s--, t--;

        vector<int> adj_list[V];
        vector< vector<int> > capacity(V, vector<int>(V, 0));

        for (int i = 0; i < E; i++) {
            int u, v, cap;
            cin >> u >> v >> cap;

            u--, v--;

            if (capacity[u][v] == 0) {
                adj_list[u].push_back(v);
                adj_list[v].push_back(u);
            }

            capacity[u][v] += cap;
            capacity[v][u] += cap;
        }

        vector< vector<int> > flow(V, vector<int>(V, 0));

        int max_flow = 0;
        bool exhausted = false;

        while (!exhausted) {
            vector<int> pred(V, -1);
            vector<int> cap(V, 0);

            pred[s] = s;
            cap[s] = numeric_limits<int>::max();

            queue<int> fringe;
            fringe.push(s);

            bool connected = false;

            while (!fringe.empty() && !connected) {
                int u = fringe.front(); fringe.pop();

                for (int i = 0; i < adj_list[u].size(); i++) {
                    int v = adj_list[u][i];

                    if (capacity[u][v] - flow[u][v] > 0 && pred[v] == -1) {
                        pred[v] = u;
                        cap[v] = min(cap[u], capacity[u][v] - flow[u][v]);

                        if (v == t) {
                            while (pred[v] != v) {
                                u = pred[v];
                                flow[u][v] += cap[t];
                                flow[v][u] -= cap[t];
                                v = u;
                            }

                            connected = true;
                            break;
                        }
                        else {
                            fringe.push(v);
                        }
                    }
                }
            }

            if (connected)
                max_flow += cap[t];
            else
                exhausted = true;
        }

        cout << "Network " << ++tc << endl;
        cout << "The bandwidth is " << max_flow << "." << endl << endl;
    }

    return 0;
}