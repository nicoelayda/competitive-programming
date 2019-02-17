import java.util.Scanner;

class Steps {

	private static int countSteps(int diff) {
		if (diff == 0)
			return 0;
		
		if (diff % 2 != 0) {
			return (int) Math.ceil(2 * Math.sqrt(diff) - 1);
		}
		else {
			return (int) Math.ceil(Math.sqrt(4 * diff + 1) - 1);
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		while (n-- != 0) {
			int x = in.nextInt();
			int y = in.nextInt();
			
			System.out.println(countSteps(y-x));
		}
		
		in.close();
	}

}
