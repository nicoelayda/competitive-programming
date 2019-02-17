#include <iostream>
#include <algorithm>

using namespace std;

string order = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

bool compare(char c1, char c2) {
    string::iterator c1_index = find(order.begin(), order.end(), c1);
    string::iterator c2_index = find(order.begin(), order.end(), c2);

    return c1_index < c2_index;
}

int main() {
    int n;
    string word;
    cin >> n;

    while (n-- != 0) {
        cin >> word;
        sort(word.begin(), word.end(), compare);
        
        do {
            cout << word << endl;
        } while (next_permutation(word.begin(), word.end(), compare));
    }

    return 0;
}