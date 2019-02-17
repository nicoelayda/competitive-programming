#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int get_score(char ch) {
    switch (ch) {
        case 'X':
            return 10;
        default:
            return ch - '0';
    }
}

int main() {
    string line;

    while (getline(cin, line) && line != "Game Over") {
        stringstream ss(line);
        vector<char> rolls;

        for (string roll; ss >> roll;) {
            rolls.push_back(roll[0]);
        }


        int score = 0;

        for (int i = 0, num_frames = 0, num_rolls = 0; num_frames < 10 && i < rolls.size(); i++) {
            if (rolls[i] == '/')
                score += 10 - get_score(rolls[i - 1]);
            else
                score += get_score(rolls[i]);

            if (rolls[i] == 'X' || rolls[i] == '/') 
                score += get_score(rolls[i + 1]);

            if (rolls[i] == 'X') {
                if (rolls[i + 2] == '/')
                    score += 10 - get_score(rolls[i + 1]);
                else
                    score += get_score(rolls[i + 2]);
            }

            if (rolls[i] == 'X')
                num_rolls += 2;
            else
                num_rolls += 1;

            if  (num_rolls == 2) {
                num_rolls = 0;
                num_frames++;
            }
        }

        cout << score << endl;
    }
    return 0;
}