#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, t, m;
    cin >> n >> t >> m;

    map<char, int> last_blood;
    map<char, int> last_team;
    map<int, map<char, bool> > solved;

    while (m-- != 0) {
        int sub_time, team_id;
        char problem_id;
        string verdict;

        cin >> sub_time >> team_id >> problem_id >> verdict;

        if (verdict == "Yes" && !solved[team_id][problem_id] && sub_time >= last_blood[problem_id]) {
            last_blood[problem_id] = sub_time;
            last_team[problem_id] = team_id;
            solved[team_id][problem_id] = true;
        }
    }

    for (char ch = 'A'; ch < 'A' + n; ch++) {
        if (last_team[ch] == 0)
            cout << ch << " - -" << endl;
        else
            cout << ch << " " << last_blood[ch] << " " << last_team[ch] << endl;
    }

    return 0;
}