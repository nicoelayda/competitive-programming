#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int median(vector<int> vec) {
    int len = vec.size();
    sort(vec.begin(), vec.end());

    if (len % 2 == 0)
        return (vec[len / 2 - 1] + vec[len / 2]) / 2;
    else
        return vec[len / 2];
}

int main() {
    int T, r;
    cin >> T;

    while (T-- != 0) {
        int s;
        cin >> r;
        vector<int> data(r, 0);

        for (int i = 0; i < r; i++) {
            cin >> data[i];
        }

        sort(data.begin(), data.end());

        int sum = 0, med = median(data);
        for (int i = 0; i < data.size(); i++) {
            sum += abs(data[i] - med);
        }
        
        cout << sum << endl;
    }

    return 0;
}