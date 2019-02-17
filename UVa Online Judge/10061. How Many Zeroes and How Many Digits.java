import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class HowManyZeroesAndHowManyDigits {
	
	private static ArrayList<Integer> primes = sieve(800);
	
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
	
	private static long countFactZeroes(long n, int base) {
		long i, zeros, min = -1;
		
		
		for (Entry<Integer, Integer> e : factorize(base).entrySet()) {
			zeros = 0;
			
			double d;
			for (i = 1; (d = Math.pow(e.getKey(), i)) <= n; i++)
				zeros += Math.floor(n / d);
			
			zeros /= e.getValue();
			
			if (zeros < min || min == -1)
				min = zeros;
		}
		return min;
	}
	
	private static long countFactDigits(long n, int base) {
		if (n == 0 || n == 1)
			return 1;
		
		double digits = 0;
		for (int i = 2; i <= n; i++)
			digits += Math.log(i) / Math.log(base);
		
		if (digits - Math.floor(digits) < 1e-14)
			digits++;
		else
			digits = Math.floor(digits+1);
		
		return (long) digits;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (in.hasNextLong()) {
			long n = in.nextLong();
			int b = in.nextInt();
			System.out.println(countFactZeroes(n, b) + " " + countFactDigits(n, b));
		}
		
		in.close();
	}

}
