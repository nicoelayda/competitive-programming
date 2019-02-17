#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int num_books;

    while (cin >> num_books) {
        vector<int> books(num_books);

        for (int i = 0; i < num_books; i++)
            cin >> books[i];

        int money;
        cin >> money;

        sort(books.begin(), books.end());

        int i = 0, j = num_books - 1;

        int best_i, best_j;

        while (i < j) {
            if (books[i] + books[j] == money) {
                best_i = i++;
                best_j = j--;
            }
            else if (books[i] + books[j] > money) {
                j--;
            }
            else {
                i++;
            }
        }

        cout << "Peter should buy books whose prices are " 
             << books[best_i] << " and " << books[best_j] << "." << endl << endl;
    }

    return 0;
}