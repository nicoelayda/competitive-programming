#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int num_filenames;

    while (cin >> num_filenames) {
        cin.ignore();

        vector<string> filenames(num_filenames);
        int max_length = 0;

        for (int i = 0; i < num_filenames; i++) {
            cin >> filenames[i];
            max_length = max(max_length, int(filenames[i].length()));
        }

        sort(filenames.begin(), filenames.end());

        int num_columns = 62 / (max_length + 2);
        int num_rows = int(ceil(double(num_filenames) / num_columns));

        string grid[num_rows][num_columns];

        vector<string>::iterator it = filenames.begin();
        for (int j = 0; j < num_columns && it != filenames.end(); j++) {
            for (int i = 0; i < num_rows && it != filenames.end(); i++) {
                grid[i][j] = (*it) + string(max_length + 2 - (*it).length(), ' ');
                it++;
            }
        }

        cout << string(60, '-') << endl;
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_columns; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}