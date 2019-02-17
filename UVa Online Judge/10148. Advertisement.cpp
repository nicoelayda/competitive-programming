#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct jogger {
    int a, b;

    jogger(int a, int b) {
        this->a = min(a, b);
        this->b = max(a, b);
    }

    bool operator< (const jogger &other) const {
        if (this->a == other.a)
            return this->b < other.b;
        return this->a > other.a;
    }
};

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int k, n;
        cin >> k >> n;

        set<jogger> joggers;

        while (n-- != 0) {
            int a, b;
            cin >> a >> b;
            joggers.insert(jogger(a, b));
        }

        set<int> ads;
        map<int, bool> has_ad;

        set<jogger>::iterator it_set;
        for (it_set = joggers.begin(); it_set != joggers.end(); it_set++) {
            int need = k;

            for (int i = it_set->a; i <= it_set->b && need > 0; i++) {
                if (has_ad[i])
                    need--;
            }

            for (int i = it_set->a; i <= it_set->b && need > 0; i++) {
                if (!has_ad[i]) {
                    ads.insert(i);
                    has_ad[i] = true;
                    need--;
                }
            }
        }

        cout << ads.size() << endl;
        set<int>::iterator it_ads;
        for (it_ads = ads.begin(); it_ads != ads.end(); it_ads++) {
            cout << *it_ads << endl;
        }

        if (T != 0)
            cout << endl;
    }
    return 0;
}