#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1 << 26;

struct node {
    int label;
    int distance;

    node(int label, int distance) {
        this->label = label;
        this->distance = distance;
    }

    bool operator< (const node &other) const {
        if (this->distance == other.distance)
            return this->label < other.label;
        
        return this->distance < other.distance;
    }
};

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int n, m;
        int source, dest;

        cin >> n >> m;
        cin >> source >> dest;

        vector<int> adj_list[n];
        vector< vector<int> > cost_matrix(n, vector<int>(n, INF));

        for (int i = 0; i < m; i++) {
            int u, v, cost;
            cin >> u >> v >> cost;

            adj_list[u].push_back(v);
            cost_matrix[u][v] = min(cost_matrix[u][v], cost);
            
            adj_list[v].push_back(u);
            cost_matrix[v][u] = min(cost_matrix[v][u], cost);
        }

        vector<int> dist(n, INF);
        dist[source] = 0;

        priority_queue<node> heap;
        heap.push(node(source, dist[source]));

        while (!heap.empty()) {
            node curr = heap.top(); heap.pop();

            int u = curr.label;

            if (curr.distance != dist[u]) 
                continue;

            for (int i = 0; i < adj_list[u].size(); i++) {
                int v = adj_list[u][i];
                int cost = cost_matrix[u][v];

                if (dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;
                    heap.push(node(v, dist[v]));
                }
            }
        }

        cout << "Case #" << tc << ": ";
        if (dist[dest] == INF)
            cout << "unreachable" << endl;
        else
            cout << dist[dest] << endl;

    }

    return 0;
}