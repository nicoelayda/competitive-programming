#include <iostream>
using namespace std;

string led[10];

void init_led() {
    led[0] = "-|| ||-";
    led[1] = "  |  | ";
    led[2] = "- |-| -";
    led[3] = "- |- |-";
    led[4] = " ||- | ";
    led[5] = "-| - |-";
    led[6] = "-| -||-";
    led[7] = "- |  | ";
    led[8] = "-||-||-";
    led[9] = "-||- |-";
}

int main() {
    int size;
    string number;

    init_led();

    while (cin >> size >> number && size != 0) {
        // print top
        for (int i = 0; i < number.length(); i++) {
            if (i != 0) cout << " ";
            cout << " " << string(size, led[number[i] - '0'][0]) << " ";
        }
            
        cout << endl;
        
        // print top-left and top-right
        for (int j = 0; j < size; j++) {
            for (int i = 0; i < number.length(); i++) {
                if (i != 0) cout << " ";
                cout << led[number[i] - '0'][1] << string(size, ' ') << led[number[i] - '0'][2];
            }
            cout << endl;
        }
        
        // print mid
        for (int i = 0; i < number.length(); i++) {
            if (i != 0) cout << " ";
            cout << " " << string(size, led[number[i] - '0'][3]) << " ";
        }
        cout << endl;

        // print bottom-left and bottom-right
        for (int j = 0; j < size; j++) {
            for (int i = 0; i < number.length(); i++) {
                if (i != 0) cout << " ";
                cout << led[number[i] - '0'][4] << string(size, ' ') << led[number[i] - '0'][5];
            }
            cout << endl;
        }

        // print bottom
        for (int i = 0; i < number.length(); i++) {
            if (i != 0) cout << " ";
            cout << " " << string(size, led[number[i] - '0'][6]) << " ";
        }
        cout << endl << endl;
        
    }

    return 0;
}