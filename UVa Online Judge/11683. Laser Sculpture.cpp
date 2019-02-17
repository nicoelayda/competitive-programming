#include <iostream>

using namespace std;

int main() {
    int height, length;

    while (cin >> height >> length && height != 0) {
        int last = height;
        int curr;
        int cuts = 0;

        for (int i = 0; i < length; i++) {
            cin >> curr;
            if (last > curr)
                cuts += last - curr;

            last = curr;
        }

        cout << cuts << endl;
    }
    
    return 0;
}