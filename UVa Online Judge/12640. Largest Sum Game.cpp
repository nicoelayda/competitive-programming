#include <iostream>
#include <algorithm>
#include <limits>
#include <sstream>

using namespace std;

int main() {
    string line;

    while (getline(cin, line)) {
        istringstream iss(line);
        int n;

        int curr_max = 0;
        int global_max = 0;

        while (iss >> n) {
            curr_max = max(0, n + curr_max);
            global_max = max(global_max, curr_max);
        }

        cout << global_max << endl;
    }

    return 0;
}