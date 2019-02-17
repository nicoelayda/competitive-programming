package org.onlinejudge.solved;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class P11849_CD {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		while (true) {
			String[] nm = in.readLine().split(" ");
			int n = Integer.parseInt(nm[0]);
			int m = Integer.parseInt(nm[1]);
			
			if (n == 0 && m == 0) break;
			
			int[] jack = new int[n];
			int both = 0;
			
			for (int i = 0; i < n; i++)
				jack[i] = Integer.parseInt(in.readLine());
			
			for (int i = 0; i < m; i++) {
				if (Arrays.binarySearch(jack, Integer.parseInt(in.readLine())) >= 0)
					both++;
			}
			
			System.out.println(both);
		}
	}

}
