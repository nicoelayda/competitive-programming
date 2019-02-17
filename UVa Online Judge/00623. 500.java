import java.math.BigInteger;
import java.util.Scanner;

public class FiveHundredFactorial {

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
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		factTable[0] = BigInteger.ONE;
		factTable[1] = BigInteger.ONE;
		
		while (in.hasNextInt()) {
			int n = in.nextInt();
			System.out.println(n + "!");
			System.out.println(factorial(n));
		}
		in.close();
	}

}
