#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        char last;
        cin >> last;
        cin.ignore();

        int nodes = last - 'A' + 1;

        string line;
        vector< vector<bool> > adj_table(nodes, vector<bool>(nodes, false));

        while (getline(cin, line) && line.length() == 2) {
            int node1 = line[0] - 'A';
            int node2 = line[1] - 'A';

            adj_table[node1][node2] = true;
            adj_table[node2][node1] = true;
        }

        int graphs = 0;
        vector<bool> visited(nodes, false);

        for (int i = 0; i < nodes; i++) {
            if (visited[i])
                continue;

            stack<int> fringe;
            fringe.push(i);
            visited[i] = true;

            graphs += 1;

            while (!fringe.empty()) {
                int curr = fringe.top(); fringe.pop();
                for (int j = 0; j < nodes; j++) {
                    if (adj_table[curr][j] && !visited[j]) {
                        fringe.push(j);
                        visited[j] = true;
                    }
                }
            }
        }

        cout << graphs << endl;

        if (T != 0)
            cout << endl;
    }
    return 0;
}