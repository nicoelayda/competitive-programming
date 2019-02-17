#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int d(int n) {
    int sum = n;

    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main() {
    vector<int> digit_sum(100001, 0);

    for (int i = 1; i <= 100000; i++) {
        int digitation = d(i);

        if (digitation <= 100000) {
            if (digit_sum[digitation] == 0)
                digit_sum[digitation] = i;
            else
                digit_sum[digitation] = min(digit_sum[digitation], i);
        }
    }

    int T;
    cin >> T;

    while (T-- != 0) {
        int n;
        cin >> n;
        cout << digit_sum[n] << endl;
    }
    
    return 0;
}