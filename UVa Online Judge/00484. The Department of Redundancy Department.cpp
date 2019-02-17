#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> integers;
    map<int, int> frequency;

    while (cin >> n) {
        if (frequency.find(n) == frequency.end()) {
            integers.push_back(n);
            frequency[n] = 1;
        }
        else
            frequency[n]++;
    }

    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << " " << frequency[integers[i]] << endl;
    }
    
    return 0;
}