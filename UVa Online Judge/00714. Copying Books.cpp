#include <iostream>
#include <limits>
#include <vector>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int num_books, num_partitions;
        cin >> num_books >> num_partitions;

        // Using 64-bit integers to avoid overflow
        long long books[num_books]; // List of books
        long long sum[num_books];   // Sum table for the number of pages of each 
                                    // book from the 0th book to the ith book.


        // 2-dimensional DP table for storing the maximum number of pages at state (i, j), 
        // initialized to infinity.
        // row    = number of partitions needed
        // column = number of books currently being considered
        vector< vector<long long> > dp(num_partitions, vector<long long>(num_books, INF));

        // Parse input and fill the sum table.
        for (int i = 0; i < num_books; i++) {
            cin >> books[i];
            sum[i] = books[i];

            if (i != 0) {
                sum[i] += sum[i - 1];
            }

            // Initialize the base case of the DP table
            dp[0][i] = sum[i];
        }

        // Fill table via bottom-up DP.
        for (int i = 1; i < num_partitions; i++) {
            for (int j = 0; j < num_books; j++) {
                for (int k = i - 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][k], sum[j] - sum[k]));
                }
            }
        }

        // Maximum number of pages of the optimal configuration will
        // be at the last cell.
        int max_pages = dp[num_partitions - 1][num_books - 1];

        // Greedily generate the output string.
        int curr_total = 0;
        string result = "";

        // Start from the last book working backwards to satisfy the problem's 
        // constraint of minimizing the leftmost scribers first.
        for (int i = num_books - 1; i >= 0; i--) {

            // If adding the current book will exceed the maximum number of pages, OR
            // the number of books remaining is just enough for the number of partitions
            // still needed, create a new partition and set the total to the cost
            // of the current book.
            if (curr_total + books[i] > max_pages || num_partitions - 1 == i + 1) {

                // Insert in front of the string (index 0) since we are working backwards.
                result.insert(0, " " + to_string(books[i]) + " /");

                curr_total = books[i];
                num_partitions--;
            }

            // Otherwise, simply add the current book to the current partition.
            else {
                result.insert(0, " " + to_string(books[i]));
                curr_total += books[i];
            }
        }

        // Print from index 1 to remove leading whitespace.
        cout << result.substr(1) << endl;
    }

    return 0;
}