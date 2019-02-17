package org.onlinejudge.solved;
import java.util.Scanner;

public class P11185_Ternary {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long n;
		
		while ((n = in.nextLong()) >= 0) {
			System.out.println(Long.toString(n, 3));
		}
		
		in.close();
	}

}
