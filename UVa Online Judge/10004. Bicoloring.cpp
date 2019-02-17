#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, l;

    while (cin >> n && n != 0) {
        vector<vector<bool> > adj_table(n, vector<bool>(n, false));
        vector<int> colors(n, 0);

        cin >> l;

        int init = -1;

        while (l-- != 0) {
            int a, b;
            cin >> a >> b;

            if (init == -1) 
                init = a;

            adj_table[a][b] = true;
            adj_table[b][a] = true;    
        }

        queue<int> fringe;
        
        fringe.push(init);
        colors[init] = 1;

        bool bicolorable = true;

        while (!fringe.empty() && bicolorable) {
            int curr_state = fringe.front(); fringe.pop();
            int next_color = colors[curr_state] * -1;

            for (int i = 0; i < n; i++) {
                if (adj_table[curr_state][i]) {
                    if (colors[i] == colors[curr_state]) {
                        bicolorable = false;
                        break;
                    }

                    if (colors[i] == 0) {
                        colors[i] = next_color;
                        fringe.push(i);
                    }
                }
            }
        }

        cout << (bicolorable ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
    }

    return 0;
}