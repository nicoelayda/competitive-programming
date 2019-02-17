/*
 * UVa Problem 11352 - Crazy King
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2327
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class CrazyKing {

	private static char[][] board;

	private static final int knightPosX[] = {1, 1, -1, -1, 2, 2, -2, -2};
	private static final int knightPosY[] = {2, -2, 2, -2, 1, -1, 1, -1};
	private static final int kingPosX[] = {1, 1, 1, 0, 0, -1, -1, -1};
    private static final int kingPosY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		// Start and goal coordinates
		int initRow = -1, initCol = -1;
		int goalRow = -1, goalCol = -1;
		
		// Get case count
		int T = Integer.parseInt(in.readLine());
		
		while (T-- != 0) {
			st = new StringTokenizer(in.readLine());
			// Get chess board size
			int M = Integer.parseInt(st.nextToken());
			int N = Integer.parseInt(st.nextToken());
			
			// Create MxN chess board
			board = new char[M][N];
			
			// Create cells
			for (int m = 0; m < M; m++) {
				for (int n = 0; n < N; n++) {
					board[m][n] = (char) in.read();
					
					switch(board[m][n]) {
					// Set start and goal coordinates
					case 'A':
						initRow = m;
						initCol = n;
						break;
					case 'B':
						goalRow = m;
						goalCol = n;
						break;
					}
				}
				in.readLine();
			}
			
			for (int m = 0; m < M; m++) {
				for (int n = 0; n < N; n++) {					
					switch(board[m][n]) {
					case 'Z':
						// Block knights' target positions
						for (int i = 0; i < 8; i++) {
							int blockRow = m + knightPosX[i];
							int blockCol = n + knightPosY[i];
							
							if (blockRow >= 0 && blockRow < M &&
								blockCol >= 0 && blockCol < N &&
								board[blockRow][blockCol] != 'Z')
								board[blockRow][blockCol] = '0';
						}
						break;
					}
				}
			}
			
			// Unblock kingdoms
			board[initRow][initCol] = 'A';
			board[goalRow][goalCol] = 'B';			
			
			// Start search
			State initState = new State(initRow, initCol);
			LinkedList<State> queue = new LinkedList<State>();
			queue.add(initState);
			int L = 0;
			
			while (!queue.isEmpty()) {
				State current = queue.poll();
				board[current.row][current.col] = '0';
				
				// Goal found
				if (current.row == goalRow && current.col == goalCol) {
					L = current.pathCost;
					break;
				}
				
				// Branch out tree
				for (int q = 0; q < 8; q++) {
					int moveRow = current.row + kingPosX[q];
                	int moveCol = current.col + kingPosY[q];

                	if (moveRow >= 0 && moveRow < M &&
	                    moveCol >= 0 && moveCol < N)
	                    if (board[moveRow][moveCol] != '0' && board[moveRow][moveCol] != 'Z') {
	                    	board[moveRow][moveCol] = '0';
	                    	queue.add(new State(moveRow, moveCol, current.pathCost + 1));
	                    }
	                    	
				}
			}
			
			if (L > 0) 
				System.out.println("Minimal possible length of a trip is " + L);
			else
				System.out.println("King Peter, you can't go now!");	
		}
	}
	
	static class State {
		int row, col;
		int pathCost;
		
		public State (int row, int col) {
			this(row, col, 0);
		}
		
		public State (int row, int col, int pathCost) {
			this.row = row;
			this.col = col;
			this.pathCost = pathCost;
		}
		
	}
}
