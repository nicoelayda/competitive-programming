import java.util.Scanner;

public class WhatBaseIsThis {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
	
		while (in.hasNext()) {
			String x = in.next();
			String y = in.next();
			boolean matched = false;
			int i = 0, j = 0;
			
			for (i = 2; i <= 36; i++) {
				for (j = 2; j <= 36; j++) {
					try {
						if (Integer.parseInt(x, i) == Integer.parseInt(y, j)) {
							matched = true;
							break;
						}
					} catch (NumberFormatException ex) {
						continue;
					}
				}
				if (matched)
					break;
			}
			
			if (matched)
				System.out.println(x + " (base " + i + ") = " + y + " (base " + j + ")");
			else
				System.out.println(x + " is not equal to " + y + " in any base 2..36");
				
		}
		in.close();
	}
}
