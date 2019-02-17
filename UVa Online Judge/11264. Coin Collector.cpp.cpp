#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	while (T-- != 0) {
		int num_coins;
		cin >> num_coins;
		
		vector<int> coins(num_coins);
		
		for (int i = 0; i < num_coins; i++)
			cin >> coins[i];
		
		int max_coins = num_coins;
		int cumulative_total = coins[0];
		
		for (int i = 1; i < num_coins - 1; i++) {
			if (cumulative_total + coins[i] >= coins[i + 1])
				max_coins--;
			else
				cumulative_total += coins[i];
		}
		
		cout << max_coins << endl;
	}
	return 0;
}

/*
2
6
1 2 4 8 16 32
6
1 3 6 8 15 20
*/