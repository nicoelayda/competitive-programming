import java.util.Scanner;

public class BoxOfBricks {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n, set = 0;
		
		while ((n = in.nextInt()) != 0) {
			int[] h = new int[n];
			int avg = 0;
			
			for (int i = 0; i < n; i++) {
				h[i] = in.nextInt();
				avg += h[i];
			}
			
			avg /= n;
			int steps = 0;
			
			for (int i = 0; i < n; i++) {
				if (h[i] > avg)
					steps += (h[i] - avg);
			}
			
			System.out.println("Set #" + ++set);
			System.out.println("The minimum number of moves is " + steps + ".");
			System.out.println();
		}
		in.close();
	}
}