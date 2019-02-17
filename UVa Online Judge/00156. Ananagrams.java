import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

class Ananagrams {
	
	private static boolean isAnagram(String str1, String str2) {
		char[] s1 = str1.toLowerCase().toCharArray();
		char[] s2 = str2.toLowerCase().toCharArray();
		
		Arrays.sort(s1);
		Arrays.sort(s2);
			
		return Arrays.equals(s1, s2);
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		ArrayList<String> words = new ArrayList<String>();
		String word;
		
		while (!(word = in.next()).equals("#"))
			words.add(word);
		
		Collections.sort(words);
		
		for (int i = 0; i < words.size(); i++) {
			if (words.get(i).length() == 1) {
				System.out.println(words.get(i));
				continue;
			}
				
			boolean matched = false;
			for (int j = 0; j < words.size(); j++) {
				if (i != j && isAnagram(words.get(i), words.get(j))) {
					matched = true;
					break;
				}
			}
			
			if (!matched)
				System.out.println(words.get(i));
		}
		
		in.close();
	}
}
