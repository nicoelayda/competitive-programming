#include <iostream>
#include <algorithm>

using namespace std;

string to_binary(unsigned long long n) {
	if (n == 0) return "0";
	if (n == 1) return "1";
	return to_binary(n >> 1) + (n % 2 == 0 ? "0" : "1");
}

unsigned long long to_int(string binary_string) {
	unsigned long long total = 0;
	
	for (unsigned long long i = 0; i < binary_string.length(); i++)
		if (binary_string[i] == '1')
			total += pow(2, binary_string.length() - i - 1);
	
	return total;
}

int main() {
	unsigned long long n, l, u;
	string bin_n, bin_l, bin_u;
	
	while (cin >> n >> l >> u) {
		bin_n = to_binary(n);
		bin_l = to_binary(l);
		bin_u = to_binary(u);
		
		bin_n = string(32 - bin_n.length(), '0') + bin_n;
		bin_l = string(32 - bin_l.length(), '0') + bin_l;
		bin_u = string(32 - bin_u.length(), '0') + bin_u;
		
		string bin_m = string(32, '0');

		bool minimized = true;
		bool maximized = true;
		
		for (int i = 0; i < bin_m.length(); i++) {
			if (bin_n[i] == '0') {
				if (bin_u[i] == '1' || !maximized)
					bin_m[i] = '1';
				else
					bin_m[i] = '0';
			}
			else if (bin_n[i] == '1') {
				if (bin_l[i] == '0' || !minimized)
					bin_m[i] = '0';
				else
					bin_m[i] = '1';
			}
			
			if (bin_m[i] != bin_l[i])
				minimized = false;
				
			if (bin_m[i] != bin_u[i])
				maximized = false;
		}
		
		cout << to_int(bin_m) << endl;
	}
	
	return 0;
}