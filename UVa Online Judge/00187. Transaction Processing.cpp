#include <iostream>
#include <iomanip>
#include <map>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string line;
    map<string, string> accounts;

    while (getline(cin, line)) {
        string account_num = line.substr(0, 3);
        string account_name = line.substr(3);

        if (account_num == "000") break;

        accounts[account_num] = account_name;
    }

    int curr_balance = 0;
    string last_transaction = "";
    stringstream curr_report;

    string record;
    int amount;

    while (cin >> record >> amount) {
        string sequence_num = record.substr(0, 3);
        string account_num = record.substr(3);

        if (sequence_num != last_transaction) {
            if (curr_balance != 0) {
                cout << "*** Transaction " << last_transaction << " is out of balance ***" << endl;
                cout << curr_report.str();
                cout << "999 "
                     << left << setw(30) << "Out of Balance" << " "
                     << right << setw(10) << fixed << setprecision(2) << abs(curr_balance / 100.0) << endl << endl;
            }

            curr_balance = 0;
            curr_report.str("");
        }
        
        curr_balance += amount;
        curr_report << account_num << " " 
                    << left << setw(30) << accounts[account_num] << " "
                    << right << setw(10) << fixed << setprecision(2) << (amount / 100.0) << endl;

        last_transaction = sequence_num;
    }

    return 0;
}