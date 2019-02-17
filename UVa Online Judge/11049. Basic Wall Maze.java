/* 
 * UVa Problem 11049 - Basic wall maze
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1990
 */

import java.util.LinkedList;
import java.util.Scanner;

public class BasicWallMaze {

	private static final int GRID_SIZE  = 6;
	private static final int WALL_COUNT = 3;
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
        while (true) {
    		// Get start coordinates
    		int startCol = scan.nextInt() - 1;
    		int startRow = scan.nextInt() - 1;
        	
    		if (startCol + 1 == 0 && startRow + 1 == 0)
    			break;
    		
        	// Get goal coordinates
            int goalCol = scan.nextInt() - 1;
            int goalRow = scan.nextInt() - 1;
            
            // Create grid
            Cell[][] grid = new Cell[GRID_SIZE][GRID_SIZE];
            
            for (int i = 0; i < GRID_SIZE; i++) {
                for (int j = 0; j < GRID_SIZE; j++) {
                	// Create cells
                    grid[i][j] = new Cell(i, j);
                    
                    // Set grid boundaries
                    if (i == 0)
                        grid[i][j].canGoNorth = false;
                    else if (i == grid.length - 1)
                    	grid[i][j].canGoSouth = false;
                    
                    if (j == 0)
                        grid[i][j].canGoWest = false;
                    else if (j == grid.length - 1)
                    	grid[i][j].canGoEast = false;
                }
            }
            
            // Place movement restrictions
            for (int i = 0; i < WALL_COUNT; i++) {
            	// Get wall coordinates
            	int wallStartCol = scan.nextInt();
            	int wallStartRow = scan.nextInt();

            	int wallEndCol = scan.nextInt();
            	int wallEndRow = scan.nextInt(); 
            	
            	// Vertical wall
            	if (wallStartCol == wallEndCol) {
            		for (int j = wallStartRow; j < wallEndRow; j++) {
            			if (wallStartCol > 0) {
            				grid[j][wallStartCol - 1].canGoEast = false;
            			}
            			
            			if (wallStartCol < grid.length) {
            				grid[j][wallStartCol].canGoWest = false;
            			}
            				
            		}
            	}
            	
            	// Horizontal wall
            	else if (wallStartRow == wallEndRow) {
            		for (int j = wallStartCol; j < wallEndCol; j++) {
            			if (wallStartRow > 0) {
            				grid[wallStartRow - 1][j].canGoSouth = false;
            			}
            			
            			if (wallStartRow < grid.length) {
            				grid[wallStartRow][j].canGoNorth = false;
            			}
            				
            		}
            	}
            }
            
            
            // Start search
            State startState = new State(grid[startRow][startCol]); 
            LinkedList<State> queue = new LinkedList<State>();
            queue.add(startState);
            
            while (true) {
            	State currentState = queue.poll();
            	
            	currentState.cell.visited = true;
            	
            	if (currentState.cell == grid[goalRow][goalCol]) {
            		System.out.println(currentState.path);
            		break;
            	}
            		
            	
            	if (currentState.cell.canGoNorth) {
            		Cell next = grid[currentState.getRow() - 1][currentState.getCol()];
            		
            		if (!next.visited) {
                		queue.add(new State(next, currentState.path + "N"));	
            		}
            	}
            	
            	if (currentState.cell.canGoWest) {
            		Cell next = grid[currentState.getRow()][currentState.getCol() - 1];
            		
            		if (!next.visited) {
                		queue.add(new State(next, currentState.path + "W"));
            		}
            	}
            	
            	if (currentState.cell.canGoSouth) {
            		Cell next = grid[currentState.getRow() + 1][currentState.getCol()];
            		
            		if (!next.visited) {
            			queue.add(new State(next, currentState.path + "S"));
            		}
            	}
            	
            	if (currentState.cell.canGoEast) {
            		Cell next = grid[currentState.getRow()][currentState.getCol() + 1];
            		
            		if (!next.visited) {
            			queue.add(new State(next, currentState.path + "E"));
            		}
            	}
            }
        }
        
        scan.close();
	}
	
	static class State {
		Cell cell;
		String path;
		
		public State (Cell cell) {
			this(cell, "");
		}
		
		public State (Cell cell, String path) {
			this.cell = cell;
			this.path = path;
		}
		
		public int getRow() {
			return cell.row;
		}
		
		public int getCol() {
			return cell.col;
		}
	}
	
	static class Cell {
		int row, col;
		
		boolean visited;
		
		boolean canGoNorth, canGoSouth;
		boolean canGoWest, canGoEast;
		
		public Cell(int row, int col) {
			this.row = row;
			this.col = col;
			
			this.visited = false;
			
			this.canGoNorth = true;
			this.canGoSouth = true;
			this.canGoWest = true;
			this.canGoEast = true;
		}
	}
}
