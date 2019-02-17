/*
 * UVa Problem 11805 - Bafana Bafana
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=2905
 */

import java.util.Scanner;

class BafanaBafana {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testCases, numPlayers, numPasses, startPlayer, lastPlayer;
		
		testCases = scan.nextInt();
		
		for (int i = 1; i <= testCases; i++) {
			numPlayers = scan.nextInt();
			startPlayer = scan.nextInt();
			numPasses = scan.nextInt();
			
			lastPlayer = numPasses % numPlayers + startPlayer;
			
			if (lastPlayer > numPlayers)
				lastPlayer %= numPlayers;
			
			System.out.println("Case " + i + ": " + lastPlayer);
		}
		
		scan.close();
	}
}
