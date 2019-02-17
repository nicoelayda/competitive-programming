#include <cstdio>
#include <algorithm>

using namespace std;

double probability(int s, int b) {
    return b == 0 ? -1 : min(1.0, 1.0 * s / b);
}

int main() {
    int b, s, c = 0;

    while (scanf("%ld %ld", &b, &s) == 2) {
        if (b == 0 && s == 0)
            break;

        double before = probability(s, b);
        double after = probability(s-1, b-1);

        if (after == -1) 
            printf("Case %d: :-\\\n", ++c);
        else if (before < after)
            printf("Case %d: :-)\n", ++c);
        else if (before > after)
            printf("Case %d: :-(\n", ++c);
        else
            printf("Case %d: :-|\n", ++c);

    }
    return 0;
}