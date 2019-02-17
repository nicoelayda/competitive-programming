import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P10189_Minesweeper {

	static int[] xOffset = {-1, 0, 1, -1, 1, -1, 0, 1};
	static int[] yOffset = {-1, -1, -1, 0, 0, 1, 1, 1};
	static boolean first = true;
	
	static boolean isValid(int x, int y, int r, int c) {
		return x >= 0 && x < r && y >= 0 && y < c;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int cases = 1;
		while (true) {
			String[] tokens = in.readLine().split(" ");
			int r = Integer.parseInt(tokens[0]);
			int c = Integer.parseInt(tokens[1]);
			
			if (r == 0 && c == 0) break;
			
			if (first)
				first = false;
			else
				System.out.println();
			
			char[][] grid = new char[r][c];
			int[][] count = new int[r][c];
			
			for (int i = 0; i < r; i++) {
				grid[i] = in.readLine().toCharArray();
				for (int j = 0; j < c; j++) {
					if (grid[i][j] == '*') {
						for (int k = 0; k < 8; k++) {
							int mx = i+xOffset[k];
							int my = j+yOffset[k];
							
							if (isValid(mx, my, r, c))
								count[mx][my]++;
						}
					}
				}
			}
			
			System.out.println("Field #" + cases++ + ":");
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					System.out.print(grid[i][j] == '*' ? "*" : count[i][j]);
				}
				System.out.println();
			}
		}
		
	}

}
