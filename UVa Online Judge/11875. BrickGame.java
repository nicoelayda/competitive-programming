package org.onlinejudge.solved;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P11875_BrickGame {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		
		for (int tc = 1; tc <= T; tc++) {
			String[] team = in.readLine().split(" ");
			System.out.println(new StringBuilder("Case ").append(tc).append(": ").append(team[Integer.parseInt(team[0])/2 + 1]).toString());
		}
	}
}
