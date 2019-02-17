#include <iostream>
#include <vector>

using namespace std;

struct manufacturer {
    string name;
    int low, high;

    manufacturer(string name, int low, int high) {
        this->name = name;
        this->low = low;
        this->high = high;
    }
};

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int num_manufacturers;
        cin >> num_manufacturers;

        vector<manufacturer> manufacturers;

        while (num_manufacturers-- != 0) {
            string name;
            int low, high;

            cin >> name >> low >> high;
            manufacturers.push_back(manufacturer(name, low, high));
        }

        int num_queries;
        cin >> num_queries;

        while (num_queries-- != 0) {
            int price;
            cin >> price;

            int matches = 0;
            string manufacturer_name;

            for (int i = 0; i < manufacturers.size(); i++) {
                if (price >= manufacturers[i].low && price <= manufacturers[i].high) {
                    matches++;
                    manufacturer_name = manufacturers[i].name;
                }

                if (matches > 1) break;
            }

            if (matches != 1)
                cout << "UNDETERMINED" << endl;
            else
                cout << manufacturer_name << endl;
        }

        if (T != 0)
            cout << endl;
    }
    return 0;
}