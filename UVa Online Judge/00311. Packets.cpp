#include <iostream>

using namespace std;

int main() {
    int products[6], area[6];
    bool done = false;

    while (!done) {
        done = true;

        for (int i = 0; i < 6; i++) {
            cin >> products[i];

            if (products[i] != 0) 
                done = false;

            area[i] = (i + 1) * (i + 1);
        }

        if (done) break;

        int parcels = 0;
        
        for (int i = 5; i >= 0; i--) {
            while (products[i]-- > 0) {
                parcels++;
                int remaining_space = 36 - area[i];

                for (int j = 4 - i; j >= 0; j--) {
                    while (remaining_space - (i == 2 && j == 1 ? 5 : 0) >= area[j] && products[j] > 0) {
                        remaining_space -= area[j];
                        products[j]--;
                    }
                }
            }
        }

        cout << parcels << endl;
    }

    return 0;
}