#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int w, y1, y2;
        cin >> w;

        bool sealable = true;
        int diff = -1000;

        for (int i = 0; i < w; i++) {
            cin >> y1 >> y2;
            
            if (diff == -1000)
                diff = y1 - y2;

            if (y1 - y2 != diff)
                sealable = false;
        }

        cout << (sealable ? "yes" : "no") << endl;

        if (T != 0)
            cout << endl;
    }

    return 0;
}