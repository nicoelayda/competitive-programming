import java.util.Scanner;

public class FactorialYouMustBeKidding {
	
	public static long factorial(int n) {
		long prod = 1;
		for (int i = 1; i <= n; i++) 
			prod *= i;
		return prod; 
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (in.hasNextInt()) {
			int n = in.nextInt();
			
			if (0 <= n && n <= 7)
				System.out.println("Underflow!");
			
			else if (8 <= n && n <= 13)
				System.out.println(factorial(n));
			
			else if (n > 13)
				System.out.println("Overflow!");
			
			else 
				System.out.println(n % 2 != 0 ? "Overflow!" : "Underflow!");
		}
		
		in.close();
	}

}
