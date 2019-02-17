import java.util.Scanner;

public class BoxGame {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long n, m;
		
		while ((n = scan.nextLong()) != 0) {
			m = 1;
			
			while (m < n) {
				m = m * 2 + 1;
			}
			
			System.out.println(m != n ? "Alice" : "Bob");
		}
		
		scan.close();
	}

}
