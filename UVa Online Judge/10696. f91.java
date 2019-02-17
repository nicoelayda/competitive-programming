import java.util.Scanner;

/* TLE Solution */

public class f91 {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n;
		
		while ((n = in.nextInt()) != 0)
			System.out.println("f91(" + n + ") = " + (n >= 101 ? n-10 : 91));
		
		in.close();
	}
}
