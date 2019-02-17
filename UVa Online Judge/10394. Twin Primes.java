package org.onlinejudge.solved;
import java.util.ArrayList;
import java.util.Scanner;


public class P10394_TwinPrimes {
	static ArrayList<Integer> primes = new ArrayList<Integer>();
	static ArrayList<int[]> twinPrimes = new ArrayList<int[]>(100000);
	
	private static void sieve(int n) {
		boolean[] isComposite = new boolean[n+1];
		double limit = Math.sqrt(n);
		
		for (int i = 2; i <= limit; i++) {
			if (!isComposite[i]) {
				for (int j = i*i; j <= n; j += i) {
					isComposite[j] = true;
				}
			}
		}
		
		for (int i = 2; i <= n; i++) {
			if (!isComposite[i]) {
				primes.add(i);
			}
		}
	}
	
	private static void printNthTwinPrime(int n) {
		while (n > twinPrimes.size()) {
			int maxPrime = twinPrimes.get(twinPrimes.size() - 1)[1];
			for (int i = primes.indexOf(maxPrime)+1; i < primes.size() - 1; i++) {
				if (primes.get(i) + 2 == primes.get(i+1))
					twinPrimes.add(new int[] {primes.get(i), primes.get(i+1)});
			} 
		}
		System.out.println("(" + twinPrimes.get(n-1)[0] + ", " + twinPrimes.get(n-1)[1] + ")");
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		twinPrimes.add(new int[] {3, 5});
		sieve(20000000);
		while (in.hasNextInt())
			printNthTwinPrime(in.nextInt());
		
		in.close();
	}

}
