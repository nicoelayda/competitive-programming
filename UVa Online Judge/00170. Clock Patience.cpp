#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>

using namespace std;

struct card {
    char val, suit;

    card(string str_card) {
        this->val = str_card[0];
        this->suit = str_card[1];
    }  
};

int main() {
    const string cards = "A23456789TJQK";

    while (true) {
        vector< queue<card> > pile(13, queue<card>());
        string str_card;

        if (cin >> str_card && str_card[0] == '#')
            break;
        else
            pile[pile.size() - 1].push(card(str_card));

        for (int i = 1; i < 52; i++) {
            cin >> str_card;
            pile[pile.size() - (i % 13) - 1].push(str_card);
        }

        int pos = 12;
        int exposed = 0;
        card *last_card = 0;

        while (!pile[pos].empty()) {
            last_card = &(pile[pos].front());
            pile[pos].pop();

            pos = int(cards.find(last_card->val));
            exposed++;
        }

        cout << setfill('0') << setw(2) << exposed << ","
             << last_card->val << last_card->suit << endl;
    }

    return 0;
}