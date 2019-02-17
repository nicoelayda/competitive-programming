#include <iostream>
#include <queue>

using namespace std;

int get_value(string card) {
    switch(card[0]) {
        case 'T': case 'J': case 'Q': case 'K': case 'A':
            return 10;
        default:
            return card[0] - '0';
    }
}

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        deque<string> cards, hand;
        string card;

        for (int i = 1; i <= 52; i++) {
            cin >> card;
            cards.push_front(card);
        }

        hand.insert(hand.begin(), cards.begin(), cards.begin() + 25);
        cards.erase(cards.begin(), cards.begin() + 25);

        int x = 0, y = 0;

        for (int i = 1; i <= 3; i++) {
            x = get_value(cards.front());
            cards.pop_front();

            y += x;

            for (int j = 0; j < 10 - x; j++)
                cards.pop_front();
        }

        cards.insert(cards.begin(), hand.begin(), hand.end());

        for (int i = 1; i < y; i++)
            cards.pop_back();

        cout << "Case " << tc << ": " << cards.back() << endl;
    }


    return 0;
}