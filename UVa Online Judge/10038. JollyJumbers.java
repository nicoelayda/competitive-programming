package org.onlinejudge.solved;

import java.util.Scanner;

public class P10038_JollyJumbers {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (in.hasNextInt()) {
			int n;
			int[] seq = new int[n = in.nextInt()];
			boolean[] matches = new boolean[n-1];
			boolean jolly = true;
			
			for (int i = 0; i < n; i++)
				seq[i] = in.nextInt();
			
			for (int i = 0; i < n-1; i++) {
				int r = Math.abs(seq[i] - seq[i+1]);
				if (r == 0 || r >= n || matches[r-1]) {
					jolly = false;
					break;
				}
				else
					matches[r-1] = true;
			}
			
			System.out.println(jolly ? "Jolly" : "Not jolly");
		}
		
		in.close();
	}

}
