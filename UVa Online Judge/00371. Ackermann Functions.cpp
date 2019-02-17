#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long l, h;

    while (cin >> l >> h) {
        if (l == 0 && h == 0) 
            break;

        long long lb = min(l, h);
        long long ub = max(l, h);

        long long max_length = 0, max_val = 0;
        for (long long i = lb; i <= ub; i++) {
            long long n = i, curr_length = 0;
            
            do {
                curr_length++;

                if (n % 2 == 0)
                    n /= 2;
                else
                    n = 3 * n + 1;

            } while (n != 1);

            if (curr_length > max_length) {
                max_length = curr_length;
                max_val = i;
            }
        }

        cout << "Between " << lb << " and " << ub << ", " << max_val << " generates the longest sequence of " << max_length << " values." << endl;
    }
    return 0;
}