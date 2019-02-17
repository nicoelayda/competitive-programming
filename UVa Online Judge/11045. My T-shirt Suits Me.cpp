#include <iostream>
#include <algorithm>
#include <limits>
#include <map>
#include <queue>
#include <vector>

using namespace std;

// For map indexing
const string sizes[] = {"XXL", "XL", "L", "M", "S", "XS"};

int main() {
    int T;
    cin >> T;

    // Initialize map index
    map<string, int> size_index;

    for (int i = 0; i < 6; i++)
        size_index[sizes[i]] = i + 1;

    while (T-- != 0) {
        int n, m;
        cin >> n >> m;

        int V = m + 8;

        int source = 0;
        int sink = V - 1;

        // Construct graph
        vector< vector<int> > adj_list(V, vector<int>());
        vector< vector<int> > capacity(V, vector<int>(V, 0));

        for (int i = 1; i <= 6; i++) {
            adj_list[source].push_back(i);
            adj_list[i].push_back(source);
            capacity[source][i] = n / 6;
        }

        for (int i = 7; i < sink; i++) {
            adj_list[i].push_back(sink);
            adj_list[sink].push_back(i);
            capacity[i][sink] = 1;

            string size1, size2;
            cin >> size1 >> size2;

            adj_list[size_index[size1]].push_back(i);
            adj_list[i].push_back(size_index[size1]);
            capacity[size_index[size1]][i] = 1;

            adj_list[size_index[size2]].push_back(i);
            adj_list[i].push_back(size_index[size2]);
            capacity[size_index[size2]][i] = 1;
        }

        // Edmonds-Karp
        vector< vector<int> > flow(V, vector<int>(V, 0));

        int max_flow = 0;
        bool exhausted = false;
        
        while (!exhausted) {
            vector<int> pred(V, -1);
            vector<int> cap(V, 0);

            pred[source] = source;
            cap[source] = numeric_limits<int>::max();

            queue<int> fringe;
            fringe.push(source);

            bool connected = false;

            // BFS
            while (!fringe.empty() && !connected) {
                int u = fringe.front(); fringe.pop();

                for (int i = 0; i < adj_list[u].size(); i++) {
                    int v = adj_list[u][i];

                    if (capacity[u][v] - flow[u][v] > 0 && pred[v] == -1) {
                        pred[v] = u;
                        cap[v] = min(cap[u], capacity[u][v] - flow[u][v]);

                        if (v == sink) {
                            // Backtrack augmenting path
                            while (pred[v] != v) {
                                u = pred[v];
                                flow[u][v] += cap[sink];
                                flow[v][u] -= cap[sink];
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
                max_flow += cap[sink];
            else
                exhausted = true;
        }
        
        cout << (max_flow == m ? "YES" : "NO") << endl;
    }

    return 0;
}