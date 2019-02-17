#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main() {
    string line;
    map<string, string> dictionary;
    
    while (getline(cin, line) && line.length() != 0) {
        stringstream entry_stream(line);
        string key, value;
        entry_stream >> value >> key;
        dictionary[key] = value;
    }

    while (getline(cin, line)) {
        if (dictionary.find(line) != dictionary.end())
            cout << dictionary[line] << endl;
        else
            cout << "eh" << endl;
    }

    return 0;
}