package org.onlinejudge.solved;

import java.math.BigInteger;
import java.util.Scanner;

public class P10106_Product {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (in.hasNext()) {
			BigInteger op1 = in.nextBigInteger();
			BigInteger op2 = in.nextBigInteger();
			
			System.out.println(op1.multiply(op2));
		}		
		in.close();
	}

}
