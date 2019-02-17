#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

bool comparator(pair<int, double> p1, pair<int, double> p2) {
    return p1.second > p2.second;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- != 0) {
        int n;
        scanf("%d", &n);

        vector< pair<int, double> > jobs;

        for (int i = 1; i <= n; i++) {
            double t, f;
            scanf("%lf %lf", &t, &f);

            jobs.push_back(make_pair(i, f / t));
        }

        stable_sort(jobs.begin(), jobs.end(), comparator);

        for (int i = 0; i < jobs.size(); i++) {
            if (i != 0)
                printf(" ");
            printf("%d", jobs[i].first);
        }
        printf("\n");

        if (T != 0)
            printf("\n");
    }
    return 0;
}