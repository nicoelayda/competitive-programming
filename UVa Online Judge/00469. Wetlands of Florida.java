import java.util.Scanner;

public class WetlandsOfFlorida {
	static char [][] map;
	static char [][] tmp;
	static int count;
	
	private static boolean indexOutOfBounds(int r, int c, int rows, int cols) {
		return r < 0 || r >= rows || c < 0 || c >= cols;
	}
	
	private static void flood (int row, int col, int rows, int cols) {
		if (!indexOutOfBounds(row, col, rows, cols) && tmp[row][col] == 'W') {
			tmp[row][col] = 'X';
			count++;
			
			int rowOffset[] = {1, -1, 0, 0, 1, 1, -1, -1};
			int colOffset[] = {0, 0, 1, -1, 1, -1, 1, -1};
			
			for (int i = 0; i < rowOffset.length; i++) {
				if (!indexOutOfBounds(row + rowOffset[i], col + colOffset[i], rows, cols) && 
						tmp[row+rowOffset[i]][col+colOffset[i]] == 'W')
					flood(row + rowOffset[i], col + colOffset[i], rows, cols);
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int tc = Integer.parseInt(in.nextLine());
		
		while (tc-- != 0) {
			in.nextLine(); // Read empty line
			int rows = 0;
			int cols = 0;
			
			String firstLine = in.nextLine();
			cols = firstLine.length();
			
			map = new char[100][100];
			map[rows++] = firstLine.toCharArray();
			
			// Read map
			while (!in.hasNextInt()) {
				map[rows++] = in.nextLine().toCharArray();
			}
			
			
			while (in.hasNextInt()) {
				int r = in.nextInt();
				int c = in.nextInt();
				in.nextLine(); // dump;
				count = 0;
				
				tmp = new char[map.length][];
				for(int i = 0; i < map.length; i++)
					tmp[i] = map[i].clone();
				
				flood(r-1, c-1, rows, cols);
				
				System.out.println(count);
			}
			
			if (in.hasNextLine())
				System.out.println();
		}
		
		in.close();
	}

}
