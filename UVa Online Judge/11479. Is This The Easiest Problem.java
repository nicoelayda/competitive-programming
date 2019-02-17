import java.util.Arrays;
import java.util.Scanner;

public class IsThisTheEasiestProblem {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String out;
		int T = scan.nextInt();
		double[] s;
		
		for (int i = 1; i <= T; i++) {
			out = "Case " + i + ": ";
			s = new double[] { scan.nextDouble(), scan.nextDouble(), scan.nextDouble() };
			Arrays.sort(s);
			
			if (s[0] <= 0 || s[0] + s[1] <= s[2])
				out += "Invalid";
			else if (s[0] == s[1] && s[0] == s[2])
				out += "Equilateral";
			else if (s[0] == s[1] || s[1] == s[2])
				out += "Isosceles";
			else
				out += "Scalene";
			
			System.out.println(out);
		}
		
		scan.close();
	}
}