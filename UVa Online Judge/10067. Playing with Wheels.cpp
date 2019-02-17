#include <cstdio>
#include <queue>
#include <map>

using namespace std;

const int NUM_BUTTONS = 4;
const int NUM_OFFSETS = 2;

const int OFFSET[NUM_OFFSETS] = {-1, 1};

struct state {
    int buttons[NUM_BUTTONS];
    int cost;

    state(int a, int b, int c, int d, int cost = 0) {
        this->buttons[0] = a;
        this->buttons[1] = b;
        this->buttons[2] = c;
        this->buttons[3] = d;
        this->cost = cost;
    }

    state(const state &to_copy) {
        for (int i = 0; i < NUM_BUTTONS; i++)
            this->buttons[i] = to_copy.buttons[i];
        this->cost = to_copy.cost;
    }

    
    bool operator< (const state &other) const {
        for (int i = 0; i < NUM_BUTTONS; i++) {
            if (this->buttons[i] != other.buttons[i]) {
                return this->buttons[i] < other.buttons[i];
            }
        }

        return false;
    }

    bool operator== (const state &other) const {
        bool equal = true;

        for (int i = 0; i < NUM_BUTTONS; i++) {
            if (this->buttons[i] != other.buttons[i]) {
                equal = false;
                break;
            }
        }

        return equal;
    }
};

int main() {
    int T;
    scanf("%d", &T);

    while (T-- != 0) {
        int a, b, c, d;
        queue<state> fringe;
        map<state, bool> visited;

        scanf("%d %d %d %d", &a, &b, &c, &d);
        state init(a, b, c, d, 0);

        scanf("%d %d %d %d", &a, &b, &c, &d);
        state goal(a, b, c, d);

        int num_forbidden;
        scanf("%d", &num_forbidden);

        while (num_forbidden-- != 0) {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            visited[state(a, b, c, d)] = true;
        }

        fringe.push(init);
        visited[init] = true;

        bool solved = false;

        if (init == goal) {
            printf("%d\n", init.cost);
            solved = true;
        }

        while (!fringe.empty() && !solved) {
            state curr = fringe.front(); fringe.pop();

            for (int i = 0; i < NUM_BUTTONS && !solved; i++) {
                for (int j = 0; j < NUM_OFFSETS && !solved; j++) {
                    state next(curr);
                    next.buttons[i] = (((next.buttons[i] + OFFSET[j]) % 10) + 10) % 10;
                    next.cost += 1;

                    if (!visited[next]) {
                        if (next == goal) {
                            printf("%d\n", next.cost);
                            solved = true;
                        }

                        visited[next] = true;
                        fringe.push(next);
                    }
                }
            }
        }

        if (!solved)
            printf("-1\n");
    }

    return 0;
}