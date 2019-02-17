package org.onlinejudge.solved;

import java.util.ArrayList;
import java.util.Scanner;

public class P10591_HappyNumber {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
				
		for (int i = 1; i <= T; i++) {
			ArrayList<Integer> found = new ArrayList<Integer>();
			int n = scan.nextInt();
			boolean happy = false;
			int sum;
			
			System.out.print("Case #" + i + ": " + n + " is ");
			found.add(n);
			
			do {
				sum = 0;
				do {
					int digit = n % 10;
					sum += digit * digit;
				} while ((n /= 10) > 0);
				n = sum;
			} while (!(happy = (n == 1)) && !found.contains(n) && found.add(n));
			
			System.out.println((happy ? "a Happy" : "an Unhappy") + " number.");
		}
		
		scan.close();
	}

}
