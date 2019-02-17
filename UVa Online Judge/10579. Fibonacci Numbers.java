package org.onlinejudge.solved;
import java.math.BigInteger;
import java.util.Scanner;

public class P10579_FibonacciNumbers {
	
	private static BigInteger[] fib = new BigInteger[5000];
	
	private static BigInteger fib(int n) {
		if (n == 0)
			return BigInteger.ZERO;
		if (n == 1)
			return BigInteger.ONE;
		
		if (fib[n] == null)
			fib[n] = fib(n-1).add(fib(n-2));
		
		return fib[n]; 
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (in.hasNextInt())
			System.out.println(fib(in.nextInt()));
		
		in.close();
	}

}
