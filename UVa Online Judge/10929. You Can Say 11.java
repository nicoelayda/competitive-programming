package org.onlinejudge.solved;

import java.math.BigInteger;
import java.util.Scanner;

public class P10929_YouCanSay11 {

	private static final BigInteger ELEVEN = new BigInteger("11"); 
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String line;
		
		while (!(line = in.nextLine()).equals("0"))
			System.out.println(line + " is " + (new BigInteger(line).mod(ELEVEN).equals(BigInteger.ZERO) ? "" : "not ") + "a multiple of 11.");
			
		
		in.close();
	}
}
