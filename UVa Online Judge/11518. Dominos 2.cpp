#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int n, m, l;
        cin >> n >> m >> l;

        vector<bool> knocked_down(n, false);
        vector<vector<bool> > adj_table(n, vector<bool>(n, false));

        while (m-- != 0) {
            int x, y;
            cin >> x >> y;
            adj_table[x-1][y-1] = true;
        }

        while (l-- != 0) {
            int z;
            stack<int> fringe;

            cin >> z;
            fringe.push(z-1);
            knocked_down[z-1] = true;

            while (!fringe.empty()) {
                int curr_state = fringe.top(); fringe.pop();

                for (int i = 0; i < n; i++) {
                    if (adj_table[curr_state][i] && !knocked_down[i]) {
                        knocked_down[i] = true;
                        fringe.push(i);
                    }
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (knocked_down[i])
                count++;
        }

        cout << count << endl;
    }

    return 0;
}