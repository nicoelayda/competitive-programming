package org.onlinejudge.solved;
import java.util.Scanner;

public class P11132_SummingDigits {

	private static int singleDigitSum(int n) {
		do { 
			int sum = 0;
			do {
				sum += n % 10;
			} while ((n /= 10) != 0);
			n = sum;
		} while (n >= 10);
		
		return n;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n;
		
		while ((n = in.nextInt()) != 0) {
			System.out.println(singleDigitSum(n));
		}
		in.close();
	}

}
