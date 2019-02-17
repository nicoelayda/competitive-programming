#include <iostream>

using namespace std;

const int row_offset[4] = {0, 0, 1, -1};
const int col_offset[4] = {1, -1, 0, 0};

int n, cases;

bool valid_coord(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

int main() {
    cin >> cases;

    for (int c = 1; c <= cases; c++) {
        cin >> n;
        char grid[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '.') {
                    grid[i][j] = 'A';
                    
                    bool has_adjacent = true;
                    while (has_adjacent) {
                        has_adjacent = false;
                        for (int k = 0; k < 4; k++) {
                            int new_i = i + row_offset[k];
                            int new_j = j + col_offset[k];
                            if (valid_coord(new_i, new_j) && grid[new_i][new_j] == grid[i][j]) {
                                has_adjacent = true;
                                grid[i][j]++;
                                break;
                            }
                        }
                    }
                }
            }
        }

        cout << "Case " << c << ":" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }


    return 0;
}