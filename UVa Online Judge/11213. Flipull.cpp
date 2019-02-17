#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct state {
    int size;
    int goal;
    char curr_piece;
    int blocks_left;

    char grid[8][8];
    vector<int> solution;

    state(int n, int b, char c) {
        size = n;
        goal = b;
        curr_piece = c;
        blocks_left = n*n;
    }

    state(const state &s) : solution(s.solution) {
        size = s.size;
        goal = s.goal;
        curr_piece = s.curr_piece;
        blocks_left = s.blocks_left;

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                grid[i][j] = s.grid[i][j];
    }

    string config_string() {
        string conf = "";

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                conf += grid[i][j];

        conf += curr_piece;
        return conf;
    }
};

int fire(state &s, pair<string, int> step) {
    int r, c, consumed;
    int step_num = step.second;
    string step_name = step.first;
    bool hit_bottom = false;

    switch(step_name[0]) {
        case 'r':
            r = s.size - (step_name[1] - '0');
            c = s.size - 1;

            consumed = 0;
            while (s.curr_piece == 'M' || s.grid[r][c] == '.' || s.grid[r][c] == s.curr_piece) {
                if (s.curr_piece == 'M' && s.grid[r][c] != '.')
                    s.curr_piece = s.grid[r][c];

                if (s.grid[r][c] == s.curr_piece) {
                    s.grid[r][c] = '.';

                    for (int rr = r; rr > 0 && s.grid[rr-1][c] != '.'; rr--)
                        swap(s.grid[rr][c], s.grid[rr-1][c]);

                    consumed++;
                }

                if (c > 0) {
                    c--;
                }
                else if (r < s.size - 1) {
                    r++;
                }
                else {
                    hit_bottom = true;
                    break;
                }
            }
            break;

        case 'c':
            r = 0;
            c = (step_name[1] - '0') - 1;

            consumed = 0;
            while (s.curr_piece == 'M' || s.grid[r][c] == '.' || s.grid[r][c] == s.curr_piece) {
                if (s.curr_piece == 'M' && s.grid[r][c] != '.')
                    s.curr_piece = s.grid[r][c];

                if (s.grid[r][c] == s.curr_piece) {
                    s.grid[r][c] = '.';

                    for (int rr = r; rr > 0 && s.grid[rr-1][c] != '.'; rr--)
                        swap(s.grid[rr][c], s.grid[rr-1][c]);

                    consumed++;
                }

                if (r < s.size - 1)
                    r++;
                else {
                    hit_bottom = true;
                    break;
                }
            }
            break;
    }

    if (consumed > 0) {
        if (!hit_bottom) {
            swap(s.curr_piece, s.grid[r][c]);
        }
        s.blocks_left -= consumed;
        s.solution.push_back(step_num);   
    }

    return consumed;
}

int main() {
    int n, m, tc = 0;
    char init_piece;
    string game_name;

    while (cin >> n >> m >> init_piece >> game_name && n != 0) {
        state init_state(n, m, init_piece);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> init_state.grid[i][j];    
            }
        }

        string tmp_step;
        vector<pair<string, int> > steps;
        set<string> used_steps;
        
        for (int i = 0; i < 12; i++) {
            cin >> tmp_step;
            if (tmp_step[0] != 'X' && used_steps.find(tmp_step) == used_steps.end()) {
                steps.push_back(make_pair(tmp_step, i + 1));
                used_steps.insert(tmp_step);
            }
        }

        queue<state> fringe;
        set<string> used_configurations;

        fringe.push(init_state);
        used_configurations.insert(init_state.config_string());

        while (!fringe.empty()) {
            state curr = fringe.front(); fringe.pop();
            
            if (curr.blocks_left <= curr.goal) {
                cout << "Case " << ++tc << ": " << game_name << endl;
                cout << curr.solution.size() << endl;

                for (int i = 0; i < curr.solution.size(); i++) {
                    cout << (i == 0 ? "" : " ") << curr.solution[i];
                }
                cout << endl << endl;
                break;
            }

            for (int i = 0; i < steps.size(); i++) {
                state next = state(curr);
                int blocks_destroyed = fire(next, steps[i]);
                string conf = next.config_string();

                if (blocks_destroyed > 0 && used_configurations.find(conf) == used_configurations.end()) {
                    fringe.push(next);
                    used_configurations.insert(conf);
                }
            }   
        }
    }
    return 0;
}