#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

bool in_circle(int x, int y, pair<pair<int, int>, int> &circle) {
    return pow(x - circle.first.first, 2) + 
           pow(y - circle.first.second, 2) <= pow(circle.second, 2);
}

int main() {
    int T, tc = 0;
    cin >> T;

    while (T-- != 0) {
        int n, m;
        int x, y, r;
        cin >> n >> m;

        vector<pair< pair<int, int>, int> > circles;

        while (n-- != 0) {
            cin >> x >> y >> r;
            circles.push_back(make_pair(make_pair(x, y), r));
        }

        cout << "Case " << ++tc << ":" << endl;

        while (m-- != 0) {
            cin >> x >> y;
            bool found = false;

            for (int i = 0; i < circles.size() && !found; i++) {
                if (in_circle(x, y, circles[i]))
                    found = true;
            }

            cout << (found ? "Yes" : "No") << endl;
        }
    }

    return 0;
}