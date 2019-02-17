#include <iostream>
#include <vector>

using namespace std;

string get_name(vector<string> &students, int pos) {
    if (students[pos] != "?")
        return students[pos];
    else {
        string name = "";
        bool left_found = false, right_found = false;

        for (int i = 1; !left_found && !right_found; i++) {
            if (pos - i >= 0 && students[pos - i] != "?")
                left_found = true;

            if (pos + i < students.size() && students[pos + i] != "?")
                right_found = true;

            if (left_found && right_found)
                name =  "middle of " + students[pos - i] + " and " + students[pos + i];

            else if (left_found) {
                for (int j = 0; j < i; j++)
                    name += "right of ";

                name += students[pos - i];
            }

            else if (right_found) {
                for (int j = 0; j < i; j++)
                    name += "left of ";

                name += students[pos + i];
            }
        }

        return name;
    }
}

int main() {
    int num_students;
    cin >> num_students;

    vector<string> students(num_students);
    for (int i = 0; i < num_students; i++)
        cin >> students[i];

    int queries;
    cin >> queries;

    while (queries-- != 0) {
        int query;
        cin >> query;
        cout << get_name(students, query - 1) << endl;
    }
    return 0;
}