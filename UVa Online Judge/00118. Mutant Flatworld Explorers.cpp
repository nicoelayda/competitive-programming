#include <iostream>
#include <vector>

using namespace std;

bool valid_coord(int r, int c, int rows, int cols) {
	return r >= 0 && r < rows && c >= 0 && c < cols;
}

char to_direction(int n) {
	switch (n) {
		case 0: return 'N';
		case 1: return 'E';
		case 2: return 'S';
		case 3: return 'W';
	}
}

int main() {
	int max_x, max_y;
	cin >> max_x >> max_y;
	max_x += 1; max_y += 1;
	
	vector < vector<bool> > scented(max_x, vector<bool>(max_y, false));
	
	int curr_x, curr_y;
	char ch;
	int orientation;
	string command;
	
	while (cin >> curr_x >> curr_y >> ch >> command) {
		switch(ch) {
			case 'N': orientation = 0; break;
			case 'E': orientation = 1; break;
			case 'S': orientation = 2; break;
			case 'W': orientation = 3; break;
		}
		
		bool lost = false;
		for (int i = 0; i < command.length(); i++) {
			if (lost)
				break;
		
			switch(command[i]) {
				case 'L':
					orientation = (((orientation - 1) % 4) + 4) % 4;
					break;
				case 'R':
					orientation = (((orientation + 1) % 4) + 4) % 4;
					break;
					
				default:
					int prev_x = curr_x;
					int prev_y = curr_y;
					
					switch(orientation) {
						case 0: 
							curr_y++;
							break;
						case 1:
							curr_x++;
							break;
						case 2:
							curr_y--;
							break;
						default:
							curr_x--;
							break;
					}
					
					if (!valid_coord(curr_x, curr_y, max_x, max_y)) {
						curr_x = prev_x;
						curr_y = prev_y;
						if (!scented[curr_x][curr_y]) {
							scented[curr_x][curr_y] = true;
							lost = true;
						}
					}
			}
		}
		
		cout << curr_x << " " << curr_y << " " << to_direction(orientation) << (lost ? " LOST" : "") << endl;
	}
	return 0;
}
