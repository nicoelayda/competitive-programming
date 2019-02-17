package org.onlinejudge.solved;
import java.text.DecimalFormat;
import java.util.Scanner;

public class P10424_LoveCalculator {

	private static int calculateNameValue(String name) {
		int value = 0;
		name = name.toLowerCase();
		
		for (char c : name.toCharArray()) {
			if (c >= 'a' && c <= 'z')
				value += c - 'a' + 1;
		}
		
		do { 
			int sum = 0;
			do {
				sum += value % 10;
			} while ((value /= 10) != 0);
			value = sum;
		} while (value >= 10);
		
		return value;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		DecimalFormat df = new DecimalFormat("0.00");

		while (in.hasNextLine()) {
			int n1 = calculateNameValue(in.nextLine());
			int n2 = calculateNameValue(in.nextLine());
			
			System.out.println(df.format((double)Math.min(n1, n2) / Math.max(n1, n2) * 100) + " %");
		}
		
		in.close();
	}

}
