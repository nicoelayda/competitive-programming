#include <iostream>

using namespace std;

int main() {
    int T, n, m;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> n;

        int start = 1, start_temp = 1, end = n;
        int sum = 0, max_sum = 0;

        for (int i = 2; i <= n; i++) {
            cin >> m;
            if (sum + m >= 0) {
                sum += m;
            }
            else {
                sum = 0;
                start_temp = i;
            }

            if (sum > max_sum) {
                max_sum = sum;
                
                start = start_temp;
                end = i;   
            }
            else if (sum == max_sum) {
                if (i - start_temp > end - start) {
                    start = start_temp;
                    end = i;
                }
            }
        }

        if (max_sum != 0)
            cout << "The nicest part of route " << tc << " is between stops " << start << " and " << end << endl;
        else
            cout << "Route " << tc << " has no nice parts" << endl;
    }

    return 0;
}