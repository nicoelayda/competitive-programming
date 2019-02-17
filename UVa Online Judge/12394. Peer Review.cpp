#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct author {
    string institution;
    vector<int> to_review;
    map<int, bool> has_reviewed;

    set<int> reviewed_by;
    bool valid;

    author(string institution) {
        this->institution = institution;
        this->to_review = vector<int>();
        this->has_reviewed = map<int, bool>();
        this->reviewed_by = set<int>();
        this->valid = true;
    }
};

int main() {
    int k, n;

    while (cin >> k >> n && k + n != 0) {
        vector<author> authors;

        for (int i = 0; i < n; i++) {
            string institution;
            cin >> institution;

            authors.push_back(author(institution));

            for (int j = 0; j < k; j++) {
                int paper_index;
                cin >> paper_index;
                authors[i].to_review.push_back(paper_index);
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                int next_paper = authors[i].to_review[j] - 1;

                if (authors[i].institution == authors[next_paper].institution ||
                        authors[i].has_reviewed[next_paper]) {

                    authors[next_paper].valid = false;
                }

                authors[i].has_reviewed[next_paper] = true;

                if (authors[next_paper].valid)
                    authors[next_paper].reviewed_by.insert(i);
            }
        }

        int problems = 0;

        for (int i = 0; i < n; i++) {
            if (!authors[i].valid || authors[i].reviewed_by.size() != k)
                problems += 1;
        }

        if (problems == 0)
            cout << "NO PROBLEMS FOUND" << endl;
        else if (problems == 1)
            cout << "1 PROBLEM FOUND" << endl;
        else
            cout << problems << " PROBLEMS FOUND" << endl;
    }

    return 0;
}