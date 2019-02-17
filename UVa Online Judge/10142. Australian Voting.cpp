#include <iostream>
#include <sstream>
#include <limits>
#include <vector>

using namespace std;

struct candidate {
    string name;
    int num_votes;
    bool eliminated;

    candidate(string name, int num_votes, bool eliminated) {
        this->name = name;
        this->num_votes = num_votes;
        this->eliminated = eliminated;
    }
};

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int num_candidates;
        cin >> num_candidates;
        cin.ignore();

        vector<candidate> candidates;
        vector< vector<int> > ballots;

        for (int i = 0; i < num_candidates; i++) {
            string name;
            getline(cin, name);
            candidates.push_back(candidate(name, 0, false));
        }

        string line;
        while (getline(cin, line) && line.length() != 0) {
            stringstream ss(line);
            ballots.push_back(vector<int>(num_candidates));

            for (int i = 0; i < num_candidates; i++) {
                ss >> ballots[ballots.size() - 1][i];
            }
        }

        int winning_candidate = -1;
        while (winning_candidate == -1) {
            // Reset vote count
            for (int i = 0; i < num_candidates; i++) {
                candidates[i].num_votes = 0;
            }

            // Count votes
            for (int i = 0; i < ballots.size(); i++) {
                for (int j = 0; j < num_candidates; j++) {
                    if (!candidates[ballots[i][j] - 1].eliminated) {
                        candidates[ballots[i][j] - 1].num_votes++;
                        break;
                    }
                }
            }

            // Check for winner
            for (int i = 0; i < num_candidates; i++) {
                if (candidates[i].num_votes > ballots.size() / 2.0) {
                    winning_candidate = i;
                    break;
                }
            }

            // Get minimum and maximum vote count
            int min_votes = numeric_limits<int>::max();
            int max_votes = numeric_limits<int>::min();

            for (int i = 0; i < num_candidates; i++) {
                if (!candidates[i].eliminated) {
                    if (candidates[i].num_votes < min_votes) {
                        min_votes = candidates[i].num_votes;
                    }
                    if (candidates[i].num_votes > max_votes) {
                        max_votes = candidates[i].num_votes;
                    }    
                }
            }

            // All candidates are tied
            if (min_votes == max_votes)
                break;


            // Eliminate candidates with lowest votes
            for (int i = 0; i < num_candidates; i++) {
                if (candidates[i].num_votes == min_votes) {
                    candidates[i].eliminated = true;
                }
            }
        }


        // Explicit winner
        if (winning_candidate != -1) {
            cout << candidates[winning_candidate].name << endl;
        }
        // Tie
        else {
            for (int i = 0; i < num_candidates; i++) {
                if (!candidates[i].eliminated) {
                    cout << candidates[i].name << endl;
                }
            }
        }

        if (T != 0)
            cout << endl;
    }

    return 0;
}