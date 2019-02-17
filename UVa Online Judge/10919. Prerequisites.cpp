#include <iostream>
#include <map>

using namespace std;

int main() {
    int num_courses, num_categories;

    while (cin >> num_courses >> num_categories && num_courses != 0) {
        bool can_graduate = true;
        map<string, bool> is_taking;

        for (int i = 0; i < num_courses; i++) {
            string course;
            cin >> course;
            is_taking[course] = true;
        }

        for (int i = 0; i < num_categories; i++) {
            int course_in_category, courses_required;
            cin >> course_in_category >> courses_required;

            while (course_in_category-- != 0) {
                string course;
                cin >> course;

                if (is_taking[course])
                    courses_required--;
            }

            if (courses_required > 0)
                can_graduate = false;
        }

        cout << (can_graduate ? "yes" : "no") << endl;

    }

    return 0;
}