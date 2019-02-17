import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class Divisor {

	private static ArrayList<Integer> primes = sieve(1000);
	
	private static ArrayList<Integer> sieve(int n) {
		ArrayList<Integer> primes = new ArrayList<Integer>(n);
		boolean[] isComposite = new boolean[n+1];
		double limit = Math.sqrt(n);
		
		for (int i = 2; i <= limit; i++) {
			if (!isComposite[i]) {
				for (int j = i*i; j <= n; j += i)
					isComposite[j] = true;
			}
		}
		
		for (int i = 2; i <= n; i++) {
			if (!isComposite[i])
				primes.add(i);
		}
		
		return primes;
	}
	
	private static Map<Integer, Integer> factorize(int n) {
		Map<Integer, Integer> factors = new HashMap<Integer, Integer>();
		int j = 0;
		for (int i = primes.get(j); i <= n && j < primes.size(); i = primes.get(j++)) {
			while (n%i == 0) {
				factors.put(i, factors.containsKey(i) ? factors.get(i)+1 : 1);
				n /= i;
			}
		}
		return factors;
	}
	
	private static int countDivisors(int n) {
		int divisors = 1;
		for (Entry<Integer, Integer> e : factorize(n).entrySet())
			divisors *= e.getValue()+1;
		return divisors;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		while (N-- != 0) {
			int L = in.nextInt();
			int U = in.nextInt();
			int max = 0, md = 0;
			
			for (int i = L; i <= U; i++) {
				int d = countDivisors(i);
				if (d > md) {
					md = d;
					max = i;
				}
			}
			
			System.out.println("Between " + L + " and " + U + ", " + max + " has a maximum of " + md + " divisors.");
		}
		in.close();
	}
}
