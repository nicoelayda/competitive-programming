package org.onlinejudge.solved;
import java.util.Scanner;

public class P10346_PetersSmokes {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (in.hasNextInt()) {
			int n = in.nextInt();
			int k = in.nextInt();
			int total = n;
			int empty = n;
			
			while (empty >= k) {				
				int free = empty / k;
				empty = empty - free * k + free; 
				total += free;
			}
			
			System.out.println(total);
		}
		
		in.close();
	}

}
