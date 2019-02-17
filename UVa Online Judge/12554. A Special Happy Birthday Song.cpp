#include <iostream>
#include <vector>

using namespace std;

const string song[16] = {
    "Happy", "birthday", "to", "you", 
    "Happy", "birthday", "to", "you", 
    "Happy", "birthday", "to", "Rujia", 
    "Happy", "birthday", "to", "you"};

int main() {
    int guests;
    cin >> guests;
    vector<string> guest_list(guests);

    int greetings = 16;
    while (greetings < guests)
        greetings += 16;

    for (int i = 0; i < guests; i++) {
        cin >> guest_list[i];
    }

    for (int i = 0; i < greetings; i++) {
        cout << guest_list[i % guests] << ": " << song[i % 16] << endl;
    }
    return 0;
}