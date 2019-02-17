#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int num_people;
    bool first = true;

    while (cin >> num_people) {
        vector<string> people(num_people);
        map<string, int> balance;

        if (first) 
            first = false;
        else 
            cout << endl;

        for (int i = 0; i < num_people; i++) {
            cin >> people[i];
            balance[people[i]] = 0;
        }
        
        for (int i = 0; i < num_people; i++) {
            string person;
            int money, num_recipients;
            int gift_cost = 0;

            cin >> person >> money >> num_recipients;

            if (num_recipients != 0) {
                gift_cost = money / num_recipients;
                balance[person] -= (gift_cost * num_recipients);
            }

            for (int j = 0; j < num_recipients; j++) {
                string recipient;
                cin >> recipient;

                balance[recipient] += gift_cost;
            }
        }

        for (int i = 0; i < num_people; i++) {
            cout << people[i] << " " << balance[people[i]] << endl;
        }
    }

    return 0;
}