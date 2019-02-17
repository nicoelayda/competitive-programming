#include <cstdio>
#include <utility>
#include <queue>

using namespace std;

int main() {
    int n, k;

    while (scanf("%d %d", &n, &k)) {
        if (n == 0 && k == 0) break;

        queue< pair<int, int> > students;

        for (int i = 1; i <= n; i++)
            students.push(make_pair(i, 40));

        int limit = 0;
        int output_store = 0;

        while (!students.empty()) {
            if (output_store == 0) {
                if (++limit > k)
                    limit = 1;

                output_store = limit;
            }

            pair<int, int> student = students.front();
            students.pop();

            if (student.second <= output_store) {
                output_store -= student.second;
                printf("%3d", student.first);
            }
            else {
                student.second -= output_store;
                output_store = 0;
                students.push(student);
            }
        }

        printf("\n");
    }
    
    return 0;
}