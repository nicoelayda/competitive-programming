package org.onlinejudge.solved;

import java.util.Scanner;
import java.util.Stack;

public class P00673_ParenthesesBalance {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = Integer.parseInt(in.nextLine());
		
		while (n-- != 0) {
			String line = in.nextLine();
			Stack<Character> stack = new Stack<Character>();
			boolean valid = true;
			for (char c : line.toCharArray()) {
				
				switch (c) {
				case '(': case '[':
					stack.push(c);
					break;
				case ')': 
					valid = !stack.isEmpty() && stack.pop() == '(';
					break;
				case ']':
					valid = !stack.isEmpty() && stack.pop() == '[';
					break;
				}
				
				if (!valid) break;
			}
			
			System.out.println(valid && stack.isEmpty() ? "Yes" : "No");
		}
		
		in.close();
	}

}
