package org.onlinejudge.solved;
import java.math.BigInteger;
import java.util.Scanner;

public class P10220_ILoveBigNumbers {

	static BigInteger[] factTable = new BigInteger[1001];
	static int maxFact = 1;
	
	private static BigInteger factorial(int n) {
		if (n <= maxFact)
			return factTable[n];
		
		BigInteger m = new BigInteger(Integer.toString(n));

		BigInteger factorial = factTable[maxFact]; 
		for (BigInteger i = new BigInteger(Integer.toString(maxFact)).add(BigInteger.ONE); i.compareTo(m) <= 0; i = i.add(BigInteger.ONE)) { 
			factorial = factorial.multiply(i); 
			factTable[++maxFact] = factorial;
		}
		return factorial; 
	}
	
	private static int sumDigits(BigInteger n) {
		int sum = 0;
		
		for (char c : n.toString().toCharArray())
			sum += Character.getNumericValue(c);
		
		return sum;
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		factTable[0] = BigInteger.ONE;
		factTable[1] = BigInteger.ONE;
		
		while (scan.hasNext())
			System.out.println(sumDigits(factorial(scan.nextInt())));
		
		scan.close();
	}

}
