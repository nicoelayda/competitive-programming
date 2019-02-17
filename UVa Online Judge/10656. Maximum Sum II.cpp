#include <iostream>

using namespace std;

int main() {
    int n;

    while (cin >> n && n != 0) {
        int num;
        bool first = true;
        while (n-- != 0) {
            cin >> num;
            if (num != 0) {
                if (first) 
                    first = false;
                else
                    cout << " ";

                cout << num;
            }
        }

        if (first)
            cout << "0";

        cout << endl;
    }

    return 0;
}