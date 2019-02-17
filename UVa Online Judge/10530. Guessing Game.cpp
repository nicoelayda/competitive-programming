#include <iostream>
#include <vector>
using namespace std;

int main() {
    bool done = false;

    while (!done) {
        int guess;
        string response;
        
        bool honest = true;
        vector<int> picked(10, 0);

        while (cin >> guess) {
            if (guess == 0) {
                done = true;
                break;
            }

            cin.ignore();
            getline(cin, response);

            if ((picked[guess - 1] == -1 && response != "too low") ||
                (picked[guess - 1] == 1 && response != "too high")) {

                honest = false;
            }

            if (response == "right on") {
                if (picked[guess - 1] != 0)
                    honest = false;

                break;
            }

            if (honest) {
                if (response == "too low") {
                    for (int i = 0; i <= guess - 1; i++) {
                        picked[i] = -1;
                    }
                }
                else if (response == "too high") {
                    for (int i = guess - 1; i < 10; i++) {
                        picked[i] = 1;
                    }
                }
            }
        }

        if (!done) {
            if (honest)
                cout << "Stan may be honest" << endl;
            else
                cout << "Stan is dishonest" << endl;
        }
        
    }
    return 0;
}