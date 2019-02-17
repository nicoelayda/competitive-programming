#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;

    while (cin >> n && n != 0) {
        priority_queue<int, vector<int>, greater<int> > numbers;

        while (n-- != 0) {
            int num;
            cin >> num;
            numbers.push(num);
        }

        long long total_cost = 0;
        
        while (numbers.size() != 1) {
            int n1 = numbers.top(); numbers.pop();
            int n2 = numbers.top(); numbers.pop();

            int sum = n1 + n2;
            total_cost += sum;
            numbers.push(sum);
        }

        cout << total_cost << endl;
    }

    return 0;
}