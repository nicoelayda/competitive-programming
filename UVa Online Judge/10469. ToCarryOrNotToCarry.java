package org.onlinejudge.solved;
import java.util.Scanner;

public class P10469_ToCarryOrNotToCarry {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		while (in.hasNextLong())
			System.out.println(in.nextLong() ^ in.nextLong());
		in.close();
	}
}
