package org.onlinejudge.solved;
import java.util.Scanner;


public class P10812_BeatTheSpread {
	
	public static void main(String[] args) {
		// Scanner scan = new Scanner(new File("inputs/10812.txt"));
		Scanner scan = new Scanner(System.in);
		
		int cases = scan.nextInt();
		int a, b, s, d;
		while (cases-- != 0) {
			s = scan.nextInt();
			d = scan.nextInt();
			
			if ((s + d) % 2 != 0 || (s - d) % 2 != 0) {
				System.out.println("impossible");
				continue;
			}
				
			b = (s - d) / 2;
			a = s - b;
			
			if (a < 0 || b < 0) {
				System.out.println("impossible");
				continue;
			}
			
			System.out.println(a + " " + b);
		}
		
		scan.close();
	}
}
