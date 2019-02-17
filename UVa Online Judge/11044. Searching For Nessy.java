import java.util.Scanner;

public class SearchingForNessy {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		long n, m, x, y;
		
		while (t-- != 0) {
			n = scan.nextInt() - 2;
			m = scan.nextInt() - 2;
			
			x = (long) Math.ceil((double) n / 3);
			y = (long) Math.ceil((double) m / 3);
			
			System.out.println(x * y);
		}
		
		scan.close();
	}

}
