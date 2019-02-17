#include <iostream>
#include <vector>

using namespace std;

int main() {
    int code_length, tc = 0;

    while (cin >> code_length && code_length != 0) {
        vector<int> code(code_length);
        vector<int> required(10, 0);

        for (int i = 0; i < code_length; i++) {
            cin >> code[i];
            required[code[i]]++;
        }

        cout << "Game " << ++tc << ":" << endl;
        bool all_zero = false;
        
        while (!all_zero) {
            vector<int> guess(code_length);
            vector<int> temp_required(required);
            vector<int> temp_guessed(10, 0);
            
            int strong = 0, weak = 0;

            all_zero = true;

            for (int i = 0; i < code_length; i++) {
                cin >> guess[i];
                if (guess[i] != 0)
                    all_zero = false;
            }

            if (!all_zero) {
                for (int i = 0; i < code_length; i++) {
                    if (code[i] == guess[i]) {
                        strong++;
                        temp_required[code[i]]--;
                    }
                    else {
                        temp_guessed[guess[i]]++;
                    }
               
                }

                for (int i = 1; i <= 9; i++) {
                    weak += min(temp_required[i], temp_guessed[i]);
                }
                
                cout << "    (" << strong << "," << weak << ")" << endl;
            }
        }
    }

    return 0;
}