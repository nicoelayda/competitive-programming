#include <iostream>
#include <algorithm>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

const string suits[4] = {
    "Clubs", "Diamonds", "Hearts", "Spades"
};

const string values[13] = {
    "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"
};

int str_to_int(string str) {
    stringstream ss(str);
    int n;
    ss >> n;
    return n;
}

vector< pair<string, int> > new_deck() {
    vector< pair<string, int> > deck;
    int card_count = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck.push_back(make_pair(values[j] + " of " + suits[i], ++card_count));
        }
    }

    return deck;
}

bool comparator(pair<string, int> card1, pair<string, int> card2) {
    return card1.second < card2.second;
}

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        vector< vector<int> > shuffles;
        vector< pair<string, int> > deck = new_deck();

        int num_shuffles;
        cin >> num_shuffles;

        while (num_shuffles-- != 0) {
            vector<int> shuffle(52);

            for (int i = 0; i < 52; i++)
                cin >> shuffle[i];

            shuffles.push_back(shuffle);
        }

        cin.ignore();
        string line;

        while (getline(cin, line) && line.length() != 0) {
            int shuffle_used = str_to_int(line);

            for (int i = 0; i < 52; i++) {
                deck[shuffles[shuffle_used - 1][i] - 1].second = i + 1;
            }

            sort(deck.begin(), deck.end(), comparator);
        }

        for (int i = 0; i < deck.size(); i++) {
            cout << deck[i].first << endl;
        }

        if (T != 0)
            cout << endl;
    }


    return 0;
}