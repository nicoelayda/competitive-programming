package org.onlinejudge.solved;
import java.util.Scanner;


public class P11854_Egypt {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long a, b, c;
		while ((a = in.nextLong()) != 0 && (b = in.nextLong()) != 0 && (c = in.nextLong()) != 0) {
			long a2 = a*a;
			long b2 = b*b;
			long c2 = c*c;
			
			if (a2 == b2 + c2 || b2 == a2 + c2 || c2 == a2 + b2)
				System.out.println("right");
			else
				System.out.println("wrong");
		}
		
		in.close();
	}

}
