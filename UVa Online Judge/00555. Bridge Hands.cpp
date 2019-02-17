#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const string dealers = "SWNE";
const string suits = "CDSH";
const string values = "23456789TJQKA";

bool comparator(pair<char, char> card1, pair<char, char> card2) {
    if (suits.find(card1.first) == suits.find(card2.first))
        return values.find(card1.second) < values.find(card2.second);

    return suits.find(card1.first) < suits.find(card2.first);
}

int main() {
    char dealer;

    while (cin >> dealer && dealer != '#') {
        vector< vector< pair<char, char> > > hands(4, vector< pair<char, char> >());

        for (int i = 0, p = (dealers.find(dealer) + 1) % 4; i < 52; i++, p = (p + 1) % 4) {
            pair<char, char> card;
            cin >> card.first;
            cin >> card.second;

            hands[p].push_back(card);
        }

        for (int i = 0; i < 4; i++) {
            sort(hands[i].begin(), hands[i].end(), comparator);

            cout << dealers[i] << ":";
            for (int c = 0; c < 13; c++) {
                cout << " " << hands[i][c].first << hands[i][c].second;
            }
            cout << endl;
        }
    }
    return 0;
}