package org.onlinejudge.solved;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P00498_PollyThePolynomial {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String c, x;
		
		while ((c = in.readLine()) != null && (x = in.readLine()) != null) {
			StringBuilder sb = new StringBuilder();
			String[] coef = c.split("[ ]+");
			
			for (String val : x.split("[ ]+")) {
				long sum = 0;
				int cl = coef.length;
				for (int i = 0; i < cl; i++) {
					sum += Long.parseLong(coef[i]) * Math.pow(Long.parseLong(val), cl-i-1);
				}
				
				sb.append(sum).append(" ");
			}
			
			System.out.println(sb.deleteCharAt(sb.length()-1).toString());
		}
	}
}
