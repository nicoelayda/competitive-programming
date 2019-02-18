#include <iostream>
#include <algorithm>

#include <cstring>

using namespace std;

int main() {
    const int n = 100;
    int map[n][n], cost[n][n];;

    memset(map, 0, sizeof(map[0][0]) * n * n);
    memset(cost, 0, sizeof(cost[0][0]) * n * n);

    for (int r = 0; r < n; r++) {
        for (int c = 0; c <= r; c++) {
            cin >> map[r][c];
        }
    }

    int max_cost = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c <= r; c++) {
            if (r == 0 && c == 0)
                cost[r][c] = map[r][c];
            else if (r == c)
                cost[r][c] = cost[r-1][c-1] + map[r][c];
            else if (c == 0)
                cost[r][c] = cost[r-1][c] + map[r][c];
            else
                cost[r][c] = max(cost[r-1][c-1], cost[r-1][c]) + map[r][c];
        
            if (cost[r][c] > max_cost)
                max_cost = cost[r][c];
        }
    }
    cout << max_cost << endl;

    return 0;
}