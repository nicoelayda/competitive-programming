import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

class PrimeNumbers {

	private static List<Integer> primes = sieve(1000000);
	private static int p_size = primes.size();
	
	private static ArrayList<Integer> sieve(int n) {
		ArrayList<Integer> primes = new ArrayList<Integer>((int) Math.ceil(Math.sqrt(n)));
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
	
	private static List<Integer> factorize(int n) {
		List<Integer> factors = new ArrayList<Integer>();
		
		if (Collections.binarySearch(primes, n) >= 0) {
			factors.add(n);
			return factors;
		}
		
		int j = 0;
		for (int i = primes.get(j); i <= n && j < p_size; i = primes.get(j++)) {
			while (n%i == 0) {
				factors.add(i);
				n /= i;
			}
		}
		
		if (n != 1)
			factors.add(n);
		
		return factors;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb;
		while (true) {
			int n = Integer.parseInt(in.readLine());
			if (n == 0) break;
			sb = new StringBuilder();
			
			sb.append(n).append(" = ");
			if (n < 0) sb.append("-1 x ");
			
			List<Integer> factors = factorize(Math.abs(n));
			Iterator<Integer> it = factors.iterator();
			while (it.hasNext()) {
				sb.append(it.next());
				if (it.hasNext())
					sb.append(" x ");
				else
					System.out.println(sb.toString());
			}
			
		}
	}

}
