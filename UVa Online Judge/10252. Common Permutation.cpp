#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string a, b;

    while (getline(cin, a) && getline(cin, b)) {
        int ai = 0, bi = 0;
        string subsequence = "";

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        while (ai != a.length() && bi != b.length()) {
            if (a[ai] < b[bi])
                ai++;

            else if (a[ai] > b[bi])
                bi++;
            
            if (a[ai] == b[bi]) {
                subsequence += a[ai];
                ai++;
                bi++;
            }
        }

        cout << subsequence << endl;
    }
    return 0;
}