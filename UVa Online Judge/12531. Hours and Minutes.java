package org.onlinejudge.solved;
import java.util.Scanner;

public class P12531_HoursAndMinutes {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (in.hasNextInt())
			System.out.println(in.nextInt()%6 == 0 ? "Y" : "N");
		
		in.close();
	}

}
