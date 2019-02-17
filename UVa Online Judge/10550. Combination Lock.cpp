#include <iostream>
#include <algorithm>

using namespace std;

const int DEG = 360 / 40;

int distance_ccw(int from, int to) {
    if (from < to)
        return (to - from) * DEG;
    else
        return (40 + to - from) * DEG;
}

int distance_cw(int from, int to) {
    if (from < to)
        return (40 + from - to) * DEG;
    else
        return (from - to) * DEG;
}

int main () {
    int p[4];

    while (cin >> p[0] >> p[1] >> p[2] >> p[3]) {
        if (p[0] == 0 && p[1] == 0 && p[2] == 0 && p[3] == 0)
            break;

        int degrees = 360 * 3;

        degrees += distance_cw(p[0], p[1]);
        degrees += distance_ccw(p[1], p[2]);
        degrees += distance_cw(p[2], p[3]);

        cout << degrees << endl;
    }

    return 0;
}