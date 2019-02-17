import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

class TheBlocksProblem {
	
	public static final int CMD_SOURCE = 0;
	public static final int BLK_SOURCE = 1;
	public static final int CMD_DEST = 2;
	public static final int BLK_DEST = 3;
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String input;
		String[] command;
		int a, b;
		
		int numBlocks = Integer.parseInt(scan.nextLine());
		int[] blockPosition = new int[numBlocks];
		List<Stack<Integer>> blocks = new ArrayList<Stack<Integer>>();
		
		// Initialize blocks and positions
		for (int i = 0; i < numBlocks; i++) {
			blocks.add(new Stack<Integer>());
			blocks.get(i).push(i);
			blockPosition[i] = i;
		}
		
		while (!(input = scan.nextLine()).equals("quit")) {
			command = input.split(" ");
			// Parse a and b
			a = Integer.parseInt(command[BLK_SOURCE]);
			b = Integer.parseInt(command[BLK_DEST]);
			
			Stack<Integer> currSource = blocks.get(blockPosition[a]);
			Stack<Integer> currDest = blocks.get(blockPosition[b]);
			
			// Check for illegal command
			if (a == b || blockPosition[a] == blockPosition[b])
				continue;
			
			if (command[CMD_DEST].equals("onto")) {
				// Remove all blocks on top of b to their original positions
				while (!currDest.isEmpty() && currDest.peek() != b) {
					int tmpVal = currDest.pop();
					blocks.get(tmpVal).push(tmpVal);
					blockPosition[tmpVal] = tmpVal;
				}
			}
			
			if (command[CMD_SOURCE].equals("move")) {
				// Remove all blocks on top of a to their original positions
				while (!currSource.isEmpty() && currSource.peek() != a) {
					int tmpVal = currSource.pop();
					blocks.get(tmpVal).push(tmpVal);
					blockPosition[tmpVal] = tmpVal;
				}
			}
			
			// Merge a and b
			int pileIndex = 0;
			while (currSource.get(pileIndex) != a)
				pileIndex++;
			
			while (!currSource.isEmpty() && pileIndex < currSource.size()) {
				int tmpVal = currSource.remove(pileIndex);
				currDest.push(tmpVal);
				blockPosition[tmpVal] = blockPosition[b];
			}
		}
		
		// Print final
		for (int i = 0; i < numBlocks; i++) {
			Iterator<Integer> it = blocks.get(i).iterator();
			System.out.print(i + ":");
			
			while (it.hasNext()) {
				System.out.print(" " + it.next());
			}
			
			System.out.println();
		}
		
		scan.close();
	}

}