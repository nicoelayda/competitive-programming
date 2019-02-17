#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    

    while (T-- != 0) {
        long long n;
        string q = "";

        cin >> n;

        for (int i = 9; i >= 2; i--) {
            while (n % i == 0) {
                q += '0' + i;
                n /= i;
            }
        }

        if (n >= 10) {
            cout << "-1" << endl;   
        }
        else {
            if (q.length() == 0)
                q = "1";

            sort(q.begin(), q.end());
            cout << q << endl;
        }

    }
    return 0;
}