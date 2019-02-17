#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols, r, c;

    while (cin >> rows >> cols >> r >> c && rows + cols + r + c != 0) {
        vector< vector<char> > grid(rows, vector<char>(cols, '0'));
        vector< vector<char> > goal(rows, vector<char>(cols, '0'));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> goal[i][j];
            }
        }

        int flips = 0;

        for (int i = 0; i <= rows - r; i++) {
            for (int j = 0; j <= cols - c; j++) {
                if (grid[i][j] != goal[i][j]) {
                    flips++;

                    for (int k = i; k < i + r; k++) {
                        for (int l = j; l < j + c; l++) {
                            grid[k][l] = (grid[k][l] == '0' ? '1' : '0');
                        }
                    }
                }
            }
        }

        bool solvable = true;

        for (int i = 0; i < rows && solvable; i++) {
            for (int j = 0; j < cols && solvable; j++) {
                if (grid[i][j] != goal[i][j]) {
                    solvable = false;
                }    
            }
        }

        cout << (solvable ? flips : -1) << endl;
    }

    return 0;
}