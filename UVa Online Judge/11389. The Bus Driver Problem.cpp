#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main() {
    int n, d, r;

    while (cin >> n >> d >> r) {
        if (n == 0 && d == 0 && r == 0)
            break;

        vector<int> morning(n);
        vector<int> evening(n);

        for (int i = 0; i < n; i++)
            cin >> morning[i];
        for (int i = 0; i < n; i++)
            cin >> evening[i];

        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end(), greater<int>());

        int overtime = 0;
        
        for (int i = 0; i < n; i++)
            overtime += max(0, morning[i] + evening[i] - d);

        cout << overtime * r << endl;
    }
    return 0;
}