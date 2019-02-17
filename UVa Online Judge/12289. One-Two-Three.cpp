#include <iostream>

using namespace std;

const char one[3] = {'o', 'n', 'e'};
const char two[3] = {'t', 'w', 'o'};

int main() {
    int n;
    string word;
    cin >> n;

    while (n-- != 0) {
        cin >> word;

        if (word.length() == 5)
            cout << 3 << endl;
        else {
            int p_one = 0, p_two = 0;
            for (int i = 0; i < 3; i++) {
                if (one[i] == word[i])
                    p_one++;

                if (two[i] == word[i])
                    p_two++;
            }

            if (p_one >= 2)
                cout << 1 << endl;
            else if (p_two >= 2)
                cout << 2 << endl;
        }
    }
    return 0;
}