import java.util.Scanner;

public class DigitCounting {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		while (T-- != 0) {
			int n = in.nextInt();
			StringBuilder sb = new StringBuilder();
			
			for (int i = 1; i <= n; i++)
				sb.append(i);

			int[] count = new int[10];

			for (char digit : sb.toString().toCharArray())
				count[Character.getNumericValue(digit)]++;
			
			for (int i = 0; i < 10; i++)
				System.out.print(i != 9 ? count[i] + " " : count[i] + "\n");
		}
		
		in.close();
	}
}
