package org.onlinejudge.solved;

import java.util.Scanner;

public class P11661_BurgerTime {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String input;
		int len, min, tmp, r, d;
		boolean rF, dF;
		
		while ((len = Integer.parseInt(scan.nextLine())) != 0) {
			min = len;
			r = d = -1;
			rF = dF = false;
			
			input = scan.nextLine();
			
			for (int i = 0; i < len; i++) {
				char c = input.charAt(i);
				
				if (c == 'Z') {
					min = 0;
					break;
				}
				else if (c == 'R') {
					rF = true;
					r = i;
				}
				else if (c == 'D') {
					dF = true;
					d = i;
				}
				
				if (rF && dF) {
					tmp = Math.abs(r-d);
					if (tmp < min)
						min = tmp;
				}
			}
			System.out.println(min);
		}
		
		scan.close();
	}

}
