#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        string matches;

        cin >> N >> matches;

        int B = 0, W = 0, T = 0, A = 0;

        for (int i = 0; i < matches.length(); i++) {
            switch(matches[i]) {
                case 'B':
                    B++; break;
                case 'W':
                    W++; break;
                case 'T':
                    T++; break;
                case 'A':
                    A++; break;
            }
        }        

        if (A == matches.length())
            cout << "Case " << tc << ": ABANDONED" << endl;
        else if (B + A == matches.length())
            cout << "Case " << tc << ": BANGLAWASH" << endl;
        else if (W + A == matches.length())
            cout << "Case " << tc << ": WHITEWASH" << endl;
        else if (B > W)
            cout << "Case " << tc << ": BANGLADESH " << B << " - " << W << endl;
        else if (W > B)
            cout << "Case " << tc << ": WWW " << W << " - " << B << endl;
        else
            cout << "Case " << tc << ": DRAW " << B << " " << T << endl;
    }

    return 0;
}