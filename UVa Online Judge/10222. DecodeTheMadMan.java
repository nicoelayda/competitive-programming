package org.onlinejudge.solved;
import java.util.Scanner;

class P10222_DecodeTheMadMan {
	
	static final String kb = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		
		for (char ch : in.nextLine().toLowerCase().toCharArray())
			sb.append(ch != ' ' ? kb.charAt(kb.indexOf(ch) - 2) : " ");
		
		System.out.println(sb.toString());
		in.close();
	}
}
