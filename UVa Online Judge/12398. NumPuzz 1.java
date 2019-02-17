/* 
 * UVa Problem 12398 - NumPuzz I
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3829
 */
import java.util.Scanner;

public class NumPuzz1 {

	private static boolean isValidCoord(int x, int y) {
		return (x >= 0 && x < 3 && y >= 0 && y < 3);
	}
	
	private static int[][] newZeroGrid() {
		int[][] grid = new int[3][3];
		
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				grid[i][j] = 0;
		
		return grid;
	}
	
	private static int[][] pressGrid(String solution) {
		int[][] grid = newZeroGrid();
		
		int[] dr = {0, 0, 1, -1};
		int[] dc = {1, -1, 0, 0};
		
		int r, c;
		int buttonIndex;
		int solLength = solution.length();
		
		for (int i = 0; i < solLength; i++) {
			buttonIndex = solution.charAt(i) - 'a';
			
			r = buttonIndex / 3;
			c = buttonIndex % 3;
			
			grid[r][c] = (grid[r][c] + 1) % 10;
			
			for (int j = 0; j < 4; j++) {
				if (isValidCoord(r + dr[j], c + dc[j]))
					grid[r + dr[j]][c + dc[j]] = (grid[r + dr[j]][c + dc[j]] + 1) % 10;
			}
		}
		
		return grid;
	}
	
	private static void printGrid(int[][] grid, int caseNum) {
		System.out.printf("Case #%d:\n", caseNum);
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				System.out.print(grid[i][j]);
				if (j != 2)
					System.out.print(" ");
				else
					System.out.println();
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int[][] grid;
		int cases = 0;
		String solution = null;
		
		while (scan.hasNext()) {
			solution = scan.nextLine();
			cases++;
			
			grid = pressGrid(solution);
			printGrid(grid, cases);
		}
		
		scan.close();
	}

}
