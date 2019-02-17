import java.util.Scanner;

public class JumpingMario {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		for (int tc = 1; tc <= T; tc++) {
			int n = in.nextInt();
			
			int[] walls = new int[n];
			int low = 0, high = 0;
			
			for (int i = 0; i < n; i++)
				walls[i] = in.nextInt();
						
			for (int i = 0; i < n-1; i++) {
				if (walls[i] > walls[i+1])
					low++;
				else if (walls[i] < walls[i+1])
					high++;
			}
			
			System.out.println("Case " + tc + ": " + high + " " + low);
		}
		
		in.close();
	}

}
