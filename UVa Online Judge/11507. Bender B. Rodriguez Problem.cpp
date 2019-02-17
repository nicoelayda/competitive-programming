#include <iostream>
#include <stack>

using namespace std;

string top, north, west, south, east, bot;

void reset() {
    top = "+y"; bot = "-y";
    north = "-z"; south = "+z";
    west = "-x"; east = "+x";
}

void rotate(string &s1, string &s2, string &s3, string &s4) {
    string temp = s1;
    s1 = s2;
    s2 = s3;
    s3 = s4;
    s4 = temp;
}

int main() {
    int l;
    while (cin >> l && l != 0) {
        string command;
        stack<string> commands;

        reset();

        for (int i = 1; i < l; i++) {
            cin >> command;
            if (command != "No")
                commands.push(command);
        }

        while (!commands.empty()) {
            command = commands.top(); commands.pop();

            if (command == "+y") {
                rotate(east, top, west, bot);
            }
            else if (command == "-y") {
                rotate(bot, west, top, east);
            }
            else if (command == "+z") {
                rotate(east, south, west, north);
            }
            else if (command == "-z") {
                rotate(north, west, south, east);
            }
        }

        cout << east << endl;
    }


    return 0;
}