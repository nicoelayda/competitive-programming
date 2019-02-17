#include <iostream>
#include <vector>

using namespace std;

int main() {
    int b, n;

    while (cin >> b >> n) {
        if (b == 0 && n == 0) 
            break;
        
        vector<int> reserves(b, 0);

        for (int i = 0; i < b; i++)
            cin >> reserves[i];

        while (n-- != 0) {
            int d, c, v;
            cin >> d >> c >> v;

            reserves[d - 1] -= v;
            reserves[c - 1] += v;
        }

        bool safe = true;
        for (int i = 0; i < b; i++) {
            if (reserves[i] < 0) {
                safe = false;
                break;
            }
        }

        cout << (safe ? "S" : "N") << endl;
    }
}