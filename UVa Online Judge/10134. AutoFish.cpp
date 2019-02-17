#include <iostream>

using namespace std;

int main() {
    int T;
    string command;
    
    cin >> T;
    cin.ignore();
    getline(cin, command);

    while (T-- != 0) {
        int fish_caught = 0;
        int bait = 0, bait_units = 0;
        int catch_cooldown = 0, fishing_cooldown = 0;

        while (getline(cin, command) && command.length() != 0) {
            if (catch_cooldown > 0) 
                catch_cooldown--;

            if (command == "bait" && bait_units < 3) {
                if (++bait == 2) {
                    bait = 0;
                    bait_units++;
                }
            }
            else if (command == "fish" && bait_units > 0) {
                if (fishing_cooldown > 0)
                    fishing_cooldown--;

                if (catch_cooldown == 0 && fishing_cooldown == 0) {
                    fish_caught++;
                    bait_units--;
                    catch_cooldown = 7;
                    fishing_cooldown = 3;
                }
            }
        }

        cout << fish_caught << endl;

        if (T != 0)
            cout << endl;
    }

    return 0;
}