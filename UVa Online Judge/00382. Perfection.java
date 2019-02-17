import java.util.Scanner;

public class Perfection {

	private static int sumOfDivisors(int n) {
		int sum = 0;
		for (int i = n/2; i >= 1; i--) {
			if (n%i == 0)
				sum += i;
			
			if (sum > n)
				break;
		}		
		return sum;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n;
		
		System.out.println("PERFECTION OUTPUT");
		
		while ((n = in.nextInt()) != 0) {
			int sum = sumOfDivisors(n);
			
			if (sum > n)
				System.out.printf("%5d  ABUNDANT\n", n);
			else if (sum < n)
				System.out.printf("%5d  DEFICIENT\n", n);
			else
				System.out.printf("%5d  PERFECT\n", n);
		}
		
		System.out.println("END OF OUTPUT");
		
		
		in.close();
	}

}
