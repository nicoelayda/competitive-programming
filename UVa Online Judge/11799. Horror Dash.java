import java.util.Scanner;

public class HorrorDash {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = Integer.parseInt(in.nextLine());
		
		for (int tc = 1; tc <= T; tc++) {
			Scanner intParser = new Scanner(in.nextLine());
			int max = 0;
            
			while (intParser.hasNextInt()) {
                max = Math.max(max, intParser.nextInt());
			}
			
			System.out.println("Case " + tc + ": " + max);
			intParser.close();
		}
		in.close();
	}

}
