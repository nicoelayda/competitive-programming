#include <iostream>
#include <map>
#include <set>

using namespace std;

struct ch {
    int ascii, count;

    ch(int ascii, int count) {
        this->ascii = ascii;
        this->count = count;
    }

    bool operator< (const ch &other) const {
        if (this->count == other.count)
            return this->ascii > other.ascii;
        return this->count < other.count;
    }
};
int main() {
    string line;
    bool first = true;

    while (getline(cin, line)) {
        if (first)
            first = false;
        else
            cout << endl;
        
        map<char, int> freq;

        for (int i = 0; i < line.length(); i++)
            freq[line[i]]++;

        set<ch> order;

        map<char, int>::iterator map_it;
        for (map_it = freq.begin(); map_it != freq.end(); ++map_it)
            order.insert(ch(int(map_it->first), map_it->second));

        set<ch>::iterator set_it;
        for (set_it = order.begin(); set_it != order.end(); ++set_it)
            cout << set_it->ascii << " " << set_it->count << endl;
    }

    return 0;
}