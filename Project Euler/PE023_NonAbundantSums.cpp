#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int limit = 28123;
int sums[limit + 1];
bool is_abundant_sum[limit + 1];
vector<int> abundant_numbers;

int sum_of_proper_divisors(int n) {
    if (n <= 1) return 0;

    int sum = 1;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n/i)
                sum += n / i;
        }
    }    

    return sum;
}

int main() {
    memset(sums, 0, sizeof(int) * limit + 1);
    memset(is_abundant_sum, false, sizeof(bool) * limit + 1);

    // Generate abundant numbers
    for (int i = 12; i <= limit; i++) {
        if (sum_of_proper_divisors(i) > i) {
            abundant_numbers.push_back(i);
        }
    }

    // Mark sums of abundant numbers
    for (int i = 0; i < abundant_numbers.size(); i++) {
        for (int j = i; i < abundant_numbers.size(); j++) {
            if (abundant_numbers[i] + abundant_numbers[j] > limit)
                break;

            is_abundant_sum[abundant_numbers[i] + abundant_numbers[j]] = true;
        }
    }

    int sum = 0;
    for (int i = 0; i <= limit; i++)
        if (!is_abundant_sum[i])
            sum += i;

    cout << sum << endl;
    return 0;
}