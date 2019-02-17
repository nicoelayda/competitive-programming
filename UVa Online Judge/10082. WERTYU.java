package org.onlinejudge.solved;
import java.util.Scanner;

class P10082_WERTYU {
	
	static final String kb = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (in.hasNextLine()) {
			for (char c : in.nextLine().toCharArray())
				System.out.print(c != ' ' ? kb.charAt(kb.indexOf(c) - 1): " ");
			
			System.out.println();
		}
		in.close();
	}

}
