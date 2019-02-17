#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        string line;
        cin >> line;

        vector<int> count(26, 0);
        
        for (int i = 0; i < line.length(); i++) {
            count[line[i] - 'A']++;
        }

        int pizzas = 0;
        
        while (
            (count['M' - 'A'] -= 1) >= 0 && 
            (count['A' - 'A'] -= 3) >= 0 && 
            (count['R' - 'A'] -= 2) >= 0 && 
            (count['G' - 'A'] -= 1) >= 0 && 
            (count['I' - 'A'] -= 1) >= 0 && 
            (count['T' - 'A'] -= 1) >= 0) {

            pizzas++;
        }

        cout << pizzas << endl;
    }

    return 0;
}