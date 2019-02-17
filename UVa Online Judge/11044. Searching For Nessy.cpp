#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T;
	cin >> T;
	
	while (T-- != 0) {
		int n, m;
		cin >> n >> m;
		
		n -= 2;
		m -= 2;
		
		int s = int(ceil(n / 3.0) * ceil(m / 3.0));
		cout << s << endl;
	}

	return 0;
}
