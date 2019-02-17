#include <iostream>
#include <map>
#include <vector>

using namespace std;

const string roman_chars = "ivxlc";
const string huns[] = {"", "c"};
const string tens[] = {"", "x", "xx", "xxx", "xl", 
                       "l", "lx", "lxx", "lxxx", "xc"};
const string ones[] = {"", "i", "ii", "iii", "iv", 
                       "v", "vi", "vii", "viii", "ix"};
                       
string to_roman(int n) {
    string roman = string();

    roman += huns[n / 100]; n %= 100;
    roman += tens[n / 10]; n %= 10;
    roman += ones[n];

    return roman;
}

int main() {
    int pages;
    vector< map<char, int> > freq(101, map<char, int>());

    for (int i = 1; i <= 100; i++) {
        string roman = to_roman(i);

        for (int j = 0; j < roman_chars.length(); j++)
            freq[i][roman_chars[j]] += freq[i - 1][roman_chars[j]];
        
        for (int j = 0; j < roman.length(); j++)
            freq[i][roman[j]]++;
    }

    while (cin >> pages && pages != 0) {
        cout << pages << ":";

        for (int i = 0; i < roman_chars.length(); i++) {   
            if (i != 0)
                cout << ",";

            cout << " " << freq[pages][roman_chars[i]]
                 << " " << roman_chars[i];
        }
        cout << endl;
    }

    return 0;
}