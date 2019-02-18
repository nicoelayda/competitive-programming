#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 80;

int main() {
    int matrix[SIZE][SIZE];
    int lookup[SIZE][SIZE] = {};
    char dump;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j != 0) cin >> dump;
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == 0 && j == 0) {
                lookup[i][j] = matrix[i][j];
            }
            else if (i == 0) {
                lookup[i][j] = matrix[i][j] + lookup[i][j - 1];
            }
            else if (j == 0) {
                lookup[i][j] = matrix[i][j] + lookup[i - 1][j];
            }
            else {
                lookup[i][j] = matrix[i][j] + min(lookup[i - 1][j], lookup[i][j - 1]);
            }
        }
    }

    cout << lookup[SIZE - 1][SIZE - 1] << endl;


    return 0;
}