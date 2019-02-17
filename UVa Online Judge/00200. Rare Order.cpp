#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool contains_element(vector<char> vec, char ch) {
    return find(vec.begin(), vec.end(), ch) != vec.end();
}

int main() {
    string word;
    vector<string> words;
    vector<char> order;
    int max_length = 0;

    while (cin >> word && word != "#") {
        words.push_back(word);
        max_length = max(max_length, (int) word.length());
    }


    for (int j = 0; j < max_length; j++) {
        for (int i = 0; i < words.size(); i++) {
            if (j < words[i].size() && !contains_element(order, words[i][j])) {
                order.push_back(words[i][j]);
            }
        }
    }
    
    for (int i = 0; i < order.size(); i++)
        cout << order[i];
    cout << endl;
    return 0;
}