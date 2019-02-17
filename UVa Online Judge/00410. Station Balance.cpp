#include <cstdio>
#include <algorithm>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int tc = 0;
    int C, S;

    while (scanf("%d %d", &C, &S) == 2) {
        list<int> specimens;
        double average_mass = 0.0;

        for (int i = 0, specimen; i < S; i++) {
            scanf("%d", &specimen);
            specimens.push_back(specimen);
            average_mass += specimen;
        }

        average_mass /= C;
        specimens.sort();

        vector<double> chamber_mass(C, 0);

        printf("Set #%d\n", ++tc);

        for (int i = 0; i < C; i++) {
            printf(" %d:", i);

            if (!specimens.empty()) {
                if (specimens.size() >= (C - i) * 2) {
                    printf(" %d", specimens.front());
                    chamber_mass[i] += specimens.front();
                    specimens.pop_front();
                }

                printf(" %d", specimens.back());
                chamber_mass[i] += specimens.back();
                specimens.pop_back();
            }

            printf("\n");
        }

        double imbalance = 0;

        for (int i = 0; i < C; i++) {
            imbalance += abs(chamber_mass[i] - average_mass);
        }

        printf("IMBALANCE = %.5lf\n\n", imbalance);
    }

    return 0;
}