#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        vector<int> dataset(n, 0);

        for (int i = 0; i < n; i++)
            cin >> dataset[i];

        int swaps = 0;
        for (int i = 0; i < n-1; i++) {
            int curr_swaps = 0;
            for (int j = 0; j < n - i - 1; j++) {
                if (dataset[j] > dataset[j + 1]) {
                    swap(dataset[j], dataset[j + 1]);
                    curr_swaps++;
                    swaps++;
                }
            }
            
            if (curr_swaps == 0)
                break;
        }

        cout << "Minimum exchange operations : " << swaps << endl;
    }
    return 0;
}