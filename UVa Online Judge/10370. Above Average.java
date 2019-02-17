package org.onlinejudge.solved;
import java.text.DecimalFormat;
import java.util.Scanner;

public class P10370_AboveAverage {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		DecimalFormat df = new DecimalFormat("0.000");
		int c = in.nextInt();
		
		while (c-- != 0) {
			int n = in.nextInt();
			int[] grades = new int[n];
			double avg = 0;
			
			
			for (int i = 0; i < n; i++) {
				grades[i] = in.nextInt();
				avg += grades[i];
			}
			
			avg /= n;
			
			double aboveavg = 0;
			
			for (int i = 0; i < n; i++) {
				if (grades[i] > avg)
					aboveavg++;
			}
			
			System.out.println(df.format(aboveavg/n*100) + "%");
		}
		
		in.close();
	}
}