#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int first;

    while (cin >> first && first != 0) {
        int num;
        vector<int> nums;
        nums.push_back(first);

        while (cin >> num && num != 0)
            nums.push_back(num);

        sort(nums.begin(), nums.end());

        first = nums[0];
        int divisor = nums[1] - first;

        for (int i = 2; i < nums.size(); i++)
            divisor = gcd(divisor, nums[i] - first);

        cout << divisor << endl;
    }


    return 0;
}