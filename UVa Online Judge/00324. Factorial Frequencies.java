package org.onlinejudge.solved;
import java.math.BigInteger;
import java.util.Scanner;


public class P00324_FactorialFrequencies {

	private static int[] countEachDigit(String s) {
		int[] count = new int[10];
		
		for (char digit : s.toCharArray())
			count[Character.getNumericValue(digit)]++;
		
		return count;
	}
	
	private static String factorial(BigInteger n) {
	    BigInteger result = BigInteger.ONE;

	    while (!n.equals(BigInteger.ZERO)) {
	        result = result.multiply(n);
	        n = n.subtract(BigInteger.ONE);
	    }

	    return result.toString();
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] count;
		BigInteger n;
		
		while (!(n = in.nextBigInteger()).equals(BigInteger.ZERO)) {
			count = countEachDigit(factorial(n));
			
			// Output
			System.out.println(n + "! --");
			for (int i = 0; i < 10; i++)
				System.out.print(" (" + i + ") " + count[i] + (i == 4 || i == 9 ? "\n" : ""));
		}
		
		in.close();
	}

}
