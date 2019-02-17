#include <cstdio>
#include <deque>
#include <map>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T-- != 0) {
        int n, s;
        scanf("%d", &n);

        map<int, bool> used;
        deque<int> snowflakes;

        int unique = 0;

        while (n-- != 0){
            scanf("%d", &s);

            while (used[s]) {
                used[snowflakes.front()] = false;
                snowflakes.pop_front();
            }
            
            snowflakes.push_back(s);
            used[s] = true;

            unique = max(unique, int(snowflakes.size()));
        }

        printf("%d\n", unique);
    }
}