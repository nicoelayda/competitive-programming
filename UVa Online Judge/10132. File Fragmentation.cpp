#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();
    cin.ignore();

    while (T-- != 0) {
        string fragment;
        vector<string> fragments;
        map<string, int> data;
        int total_length = 0;

        while (getline(cin, fragment) && fragment.length() != 0) {
            fragments.push_back(fragment);
            total_length += fragment.length();
        }

        int num_data = fragments.size() / 2;
        int data_length = total_length / num_data;
        bool found = false;

        for (int i = 0; i < fragments.size() && !found; i++) {
            for (int j = 0; j < fragments.size() && !found; j++) {
                if (i == j) continue;
                
                string curr_data = fragments[i] + fragments[j];
                
                if (curr_data.length() == data_length)
                    data[curr_data]++;

                if (data[curr_data] == num_data) {
                    cout << curr_data << endl;
                    found = true;
                }
            }
        }

        if (T != 0)
            cout << endl;
    }
    return 0;
}