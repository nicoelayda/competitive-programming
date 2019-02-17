package org.onlinejudge.solved;

/* TLE solution. Used C instead. */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P11988_BrokenKeyboard {

	public static void main(String[] args) throws IOException {
		//long startTime = System.nanoTime();
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		boolean isHome = false;
		int offset = 0;
		int ch;
		char c;
		
		while ((ch = in.read()) != -1) {
			if (ch == 10) {
				offset = 0;
				isHome = false;
				System.out.println(sb.toString());
				sb = new StringBuilder();
			}
			
			c = (char) ch;
			
			if (c == '[') {
				isHome = true;
				offset = 0;
			}
			else if (c == ']')
				isHome = false;
			else if (isHome)
				sb.insert(offset++, c);
			else
				sb.append(c);
		}

		//System.out.println("Program execution done in " + (System.nanoTime() - startTime));
	}

}
