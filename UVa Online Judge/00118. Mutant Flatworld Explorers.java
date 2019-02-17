import java.util.Scanner;

class MutantFlatworldExplorers {

	static final int NORTH = 0;
	static final int EAST = 1;
	static final int SOUTH = 2;
	static final int WEST = 3;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int r = in.nextInt() + 1;
		int c = in.nextInt() + 1;
		
		int[][] grid = new int[r][c];
		
		while (in.hasNext()) {
			int xPos = in.nextInt();
			int yPos = in.nextInt();
			int orientation;
			
			switch (in.nextLine().charAt(1)) {
				case 'N': 
					orientation = NORTH; 
					break;
				case 'E': 
					orientation = EAST; 
					break;
				case 'S': 
					orientation = SOUTH; 
					break;
				default: 
					orientation = WEST;
			}
			
			boolean lost = false;
			for (char inst : in.nextLine().toCharArray()) {
				if (lost) break;
				switch (inst) {
				case 'L': 
					orientation = (((orientation - 1) % 4) + 4) % 4;
					break;
				case 'R': 
					orientation = (((orientation + 1) % 4) + 4) % 4;
					break;
					
				default: 
					int xPrev = xPos;
					int yPrev = yPos;
					
					switch (orientation) {
					case NORTH:
						yPos++;
						break;
					case EAST:
						xPos++; 
						break;
					case SOUTH:
						yPos--; 
						break;
					default:
						xPos--;
						break;
					}
					
					if (!isValid(xPos, yPos, r, c)) {
						xPos = xPrev;
						yPos = yPrev;
						if (grid[xPrev][yPrev] != 1) {
							grid[xPrev][yPrev] = 1;
							lost = true;
						}
					}
					
				}
			}
			
			System.out.println(xPos + " " + yPos + " " + getDir(orientation) + (lost ? " LOST" : ""));
		}
		
		in.close();
	}

	
	static boolean isValid(int x, int y, int r, int c) {
		return x >= 0 && x < r && y >= 0 && y < c;
	}
	
	static char getDir(int orientation) {
		switch (orientation) {
		case NORTH: return 'N';
		case SOUTH: return 'S';
		case WEST: return 'W';
		default: return 'E';
		}
	}
}
