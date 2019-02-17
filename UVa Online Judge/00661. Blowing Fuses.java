import java.util.Scanner;

class BlowingFuses {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n, m, c, tc = 0;
		
		while ((n = in.nextInt()) != 0 && (m = in.nextInt()) != 0 && (c = in.nextInt()) != 0) {
			int[] devices = new int[n];
			boolean[] state = new boolean[n];
			for (int i = 0; i < n; i++)
				devices[i] = in.nextInt();
			
			boolean blown = false;
			int power = 0;
			int max = 0;
			
			for (int i = 0; i < m; i++) {
				int d = in.nextInt()-1;
				
				if (!blown) {
					if (state[d] = !state[d]) {
						power += devices[d];
						if (power > max)
							max = power;
					}
					else
						power -= devices[d];
					
					blown = (power > c);
				}
			}
			
			System.out.println("Sequence " + ++tc);
			
			if (blown)
				System.out.println("Fuse was blown.");
			else {
				System.out.println("Fuse was not blown.");
				System.out.println("Maximal power consumption was " + max + " amperes.");
			}
			System.out.println();
		}
		
		in.close();
	}

}
