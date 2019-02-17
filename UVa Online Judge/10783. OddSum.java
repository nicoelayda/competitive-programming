import java.util.Scanner;

class OddSum {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int a, b, n;
		for (int i = 1; i <= T; i++) {
			a = in.nextInt();
			b = in.nextInt();
			
			if (a%2 == 0) a++;
			if (b%2 == 0) b--;
			
			n = (b - a) / 2 + 1;
			
			System.out.println("Case "+ i +": " + ((a + b) / 2 * n));
		}
		
		in.close();
	}

}
