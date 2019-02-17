#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T-- != 0) {
        string track;
        getline(cin, track);

        int pieces = 1;
        int m = 0, f = 0;

        for (int i = 0; i < track.length(); i++) {
            switch (track[i]) {
                case ' ': pieces++; break;
                case 'M': m++; break;
                case 'F': f++; break;
            }
        }

        cout << (pieces > 1 && m == f ? "LOOP" : "NO LOOP") << endl;
    }

    return 0;
}