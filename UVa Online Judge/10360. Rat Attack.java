import java.util.Scanner;

public class RatAttack {
	
	private static boolean isValid(int x, int y) {
		return x >= 0 && x < 1025 && y >= 0 && y < 1025;
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		
		while (T-- != 0) {
			int[][] grid = new int[1025][1025];
			int d = scan.nextInt();
			int n = scan.nextInt();
			
			while (n-- != 0) {
				int x = scan.nextInt();
				int y = scan.nextInt();
				int pop = scan.nextInt();
				
				for (int i = x - d; i <= x + d; i++) {
					for (int j = y - d; j <= y + d; j++) {
						if (isValid(i, j)) {
							grid[i][j] += pop;
						}
					}
				}
			}
			
			int[] max = {-1, -1, -1};
			
			for (int i = 0; i < 1025; i++) {
				for (int j = 0; j < 1025; j++) {
					if (grid[i][j] > max[0]) {
						max[0] = grid[i][j];
						max[1] = i;
						max[2] = j;
					}
				}
			}
			
			System.out.println(max[1] + " " + max[2] + " " + max[0]);	
		}
		
		scan.close();
	}
}
