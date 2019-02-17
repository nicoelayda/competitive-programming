package org.onlinejudge.solved;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.Map;


public class P11340_Newspaper {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		DecimalFormat df = new DecimalFormat("0.00");
		int n = Integer.parseInt(in.readLine());
		
		while (n-- != 0) {
			int k = Integer.parseInt(in.readLine());
			Map<Character, Integer> pricemap = new HashMap<Character, Integer>(k);
			
			for (int i = 0; i < k; i++)
				pricemap.put((char) in.read(), Integer.parseInt(in.readLine().trim()));
			
			int m = Integer.parseInt(in.readLine());
			
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < m; i++)
				sb.append(in.readLine());
			
			double sum = 0;
			for (char ch : sb.toString().toCharArray()) {
				if (pricemap.containsKey(ch))
					sum += pricemap.get(ch);
			}
			
			System.out.println(df.format(sum/100) + "$");
		}
	}

}
