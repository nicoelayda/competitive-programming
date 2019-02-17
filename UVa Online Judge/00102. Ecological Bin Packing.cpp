#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <limits>

using namespace std;

int main() {
	string line;
	
	while (getline(cin, line)) {
		stringstream ss(line);
		vector< vector<int> > bins(3, vector<int>(3, 0));
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				ss >> bins[i][j];
			}
		}
		
		string perm = "BCG";
		
		int min_transfers = numeric_limits<int>::max();
		string min_perm = "";
		
		do {
			int transfers = 0;
			
			for (int i = 0; i < 3; i++) {
				switch(perm[i]) {
					case 'B':
						transfers += bins[i][1] + bins[i][2];
						break;
					case 'G':
						transfers += bins[i][0] + bins[i][2];
						break;
					case 'C':
						transfers += bins[i][0] + bins[i][1];
						break;
				}
			}
			
			if (transfers < min_transfers) {
				min_transfers = transfers;
				min_perm = perm;
			}
		} while (next_permutation(perm.begin(), perm.end()));
		
		cout << min_perm << " " << min_transfers << endl;
	}

	return 0;
}