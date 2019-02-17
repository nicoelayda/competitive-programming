package org.onlinejudge.solved;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.SortedMap;
import java.util.TreeMap;

public class P10420_ListOfConquests {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = Integer.parseInt(in.nextLine());
		SortedMap<String, Integer> map = new TreeMap<String, Integer>();
		
		while (n-- != 0) {
			String country = in.nextLine().split(" ", 2)[0];
			map.put(country, map.containsKey(country) ? map.get(country)+1 : 1);
		}
		
		for (Entry<String, Integer> e : map.entrySet())
			System.out.println(e.getKey() + " " + e.getValue());
		
		in.close();
	}
}
