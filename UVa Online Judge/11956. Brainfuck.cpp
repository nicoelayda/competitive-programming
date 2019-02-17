#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int T;
    string command;

    cin >> T;
    cin.ignore();

    for (int tc = 1; tc <= T; tc++) {
        int memory[100];
        int pointer = 0;
        
        for (int i = 0; i < 100; i++)
            memory[i] = 0;
        
        getline(cin, command);

        for (int i = 0; i < command.length(); i++) {
            switch(command[i]) {
                case '>':
                    if (++pointer == 100)
                        pointer = 0;
                    break;
                case '<':
                    if (--pointer == -1)
                        pointer = 99;
                    break;
                case '+':
                    if (++memory[pointer] == 256)
                        memory[pointer] = 0;
                    break;
                case '-':
                    if (--memory[pointer] == -1)
                        memory[pointer] = 255;
                    break;
            }
        }

        cout << "Case " << tc << ":";
        for (int i = 0; i < 100; i++) {
            cout << " "
                 << hex
                 << uppercase
                 << setfill('0') 
                 << setw(2)
                 << memory[i];
        }
        cout << endl;
    }
    return 0;
}