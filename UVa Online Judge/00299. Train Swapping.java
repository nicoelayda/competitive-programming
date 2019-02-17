package org.onlinejudge.solved;
import java.util.Scanner;

public class P00299_TrainSwapping {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		while (N-- != 0) {
			int L = in.nextInt();
			int[] train = new int[L];
			for (int i = 0; i < L; i++)
				train[i] = in.nextInt();
			
			// Bubble sort
			int temp;
			int swaps = 0;
			
			for (int i = 0; i < L; i++) {
				for (int j = 1; j < L-i; j++) {
					if (train[j-1] > train[j]) {
						temp = train[j-1];
						train[j-1] = train[j];
						train[j] = temp;
						
						swaps++;
					}
				}
			}
			
			System.out.println("Optimal train swapping takes " + swaps + " swaps.");
		}
		in.close();
	}

}
