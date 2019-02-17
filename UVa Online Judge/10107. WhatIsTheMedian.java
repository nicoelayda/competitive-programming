package org.onlinejudge.solved;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class P10107_WhatIsTheMedian {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		ArrayList<Integer> series = new ArrayList<Integer>(10000);
		
		while (in.hasNext()) {
			series.add(in.nextInt());
			Collections.sort(series);
			
			if (series.size() % 2 != 0) {
				System.out.println(series.get(series.size()/2));
			} else {
				System.out.println((series.get(series.size()/2-1) + series.get(series.size()/2))/2);
			}
		}
		
		in.close();
	}

}
