package org.onlinejudge.solved;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class P10878_DecodeTheTape {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		String s;
		
		in.readLine();
		while (!(s = in.readLine()).equals("___________")) {
			sb.append((char)Integer.parseInt(s.replace("|", "").replace(".", "").replace('o', '1').replace(' ', '0'), 2));
		}
		
		System.out.print(sb.toString());
	}

}
