#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int degree;
        cin >> degree;

        vector<int> polynomial(degree + 1);

        for (int i = 0; i <= degree; i++)
            cin >> polynomial[i];

        int d, k;
        cin >> d >> k;

        int n = 0, m = 0;
        while (m < k) {
            n += 1;
            m += n * d;
        }

        long long term = 0, pw = 1;
        for (int j = 0; j < polynomial.size(); j++) {
            term += polynomial[j] * pw;
            pw *= n;
        }

        cout << term << endl;
    }

    return 0;
}