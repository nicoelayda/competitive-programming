#include <iostream>

using namespace std;

int lookup[13];

int main() {
    for (int k = 1; k <= 13; k++) {
        int n = 2 * k;
        int m = k + 1;
        bool solved = false;
        
        while (!solved) {
            int pos = 0;
            int remaining = n;

            while (remaining > k) {
                pos = (pos + m - 1) % remaining;
                
                if (pos >= k)
                    remaining--;
                else
                    break;
            }

            if (remaining == k)
                solved = true;
            else
                m++;

        }

        lookup[k - 1] = m;
    }


    int k;
    while (cin >> k && k != 0) {
        cout << lookup[k - 1] << endl;
    }

    return 0;
}