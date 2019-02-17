package org.onlinejudge.solved;
import java.util.Scanner;

public class P10035_PrimaryArithmetic {

	private static int countCarry(long n1, long n2) {
		int carry = 0;
		int count = 0;
		String s1 = new StringBuilder(String.format("%010d", n1)).reverse().toString();
		String s2 = new StringBuilder(String.format("%010d", n2)).reverse().toString();		
		
		for (int i = 0; i < 10; i++) {
			int d1 = Character.getNumericValue(s1.charAt(i));
			int d2 = Character.getNumericValue(s2.charAt(i));
			
			if (d1 + d2 + carry > 9) {
				carry = 1;
				count++;
			}
			else
				carry = 0;
		}
		
		return count;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (true) {
			long n1 = in.nextLong();
			long n2 = in.nextLong();
			
			if (n1 == 0 && n2 == 0)
				break;
			
			int carry = countCarry(n1, n2);
			
			if (carry == 0)
				System.out.println("No carry operation.");
			else if (carry == 1)
				System.out.println("1 carry operation.");
			else
				System.out.println(carry + " carry operations.");
		}
		
		in.close();
	}

}
