package org.onlinejudge.solved;
import java.util.Scanner;

public class P10018_ReverseAndAdd {

	private static boolean isPalindrome(long n) {
		String s = String.valueOf(n);
		int length = s.length();
		int half = length / 2;
		
		for (int i = 0; i < half; i++) {
			if (s.charAt(i) != s.charAt(length - i - 1))
				return false;
		}
		return true;
	}
	
	private static long reverse(long n) {
		long reverse = 0;
		
		do {
			reverse *= 10;
			reverse += n%10;
		} while ((n /= 10) != 0);
		
		return reverse;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long T = in.nextLong();
		
		while (T-- != 0) {
			long n = in.nextLong();
			int i = 0;
			
			while (!isPalindrome(n)) {
				n += reverse(n);
				i++;
			}		
			System.out.println(i + " " + n);
		}
		in.close();
	}
}
