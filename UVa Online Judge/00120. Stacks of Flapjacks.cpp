#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string line;

    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> pancakes;
        int pancake;

        while (iss >> pancake)
            pancakes.push_back(pancake);

        cout << line << endl;

        for (int i = pancakes.size() - 1; i >= 0; i--) {
            int max_diameter = 0;
            int max_index = -1;

            for (int j = 0; j <= i; j++) {
                if (pancakes[j] > max_diameter) {
                    max_diameter = pancakes[j];
                    max_index = j;
                }
            }

            if (max_index != i) {
                if (max_index != 0) {
                    cout << pancakes.size() - max_index << " ";
                    for (int j = 0; j * 2 < max_index; j++) {
                        swap(pancakes[j], pancakes[max_index - j]);
                    }
                }

                cout << pancakes.size() - i << " ";
                for (int j = 0; j * 2 < i; j++) {
                    swap(pancakes[j], pancakes[i - j]);
                }
            }
        }

        cout << 0 << endl;
    }

    return 0;
}