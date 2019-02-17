#include <iostream>
#include <vector>

using namespace std;

vector<int> lookup_table[1000001];

int main() {
    int n, m, k, v;

    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            int elem;
            cin >> elem;
            lookup_table[elem].push_back(i+1); 
        }

        for (int i = 0; i < m; i++) {
            cin >> k >> v;
            if (k >= lookup_table[v].size())
                cout << 0 << endl;
            else
                cout << lookup_table[v][k-1] << endl;
        }
    }
    return 0;
}