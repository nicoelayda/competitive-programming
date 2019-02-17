#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main() {
    double v_total, v0;

    while (cin >> v_total >> v0 && (v_total + v0) != 0) {
        double max_length = 0;
        int max_count = 0;

        double v = v_total, curr_length;
        for (int count = 1; v > v0; count++) {
            v = v_total / count;
            curr_length = 0.3 * sqrt(v - v0) * count;

            if (fabs(curr_length - max_length) <= numeric_limits<double>::epsilon()) {
                max_count = 0;
            }
            else if (curr_length > max_length) {
                max_length = curr_length;
                max_count = count;
            }
        }

        cout << max_count << endl;
    }

    return 0;
}