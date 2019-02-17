import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class P00630_AnagramsII {

	private static boolean isAnagram(String str1, String str2) {
		char[] s2 = str2.toCharArray();
		Arrays.sort(s2);
			
		return str1.equals(new String((s2)));
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int m = Integer.parseInt(in.nextLine());
		
		for (int ds = 1; ds <= m; ds++) {
			in.nextLine();
			int n = Integer.parseInt(in.nextLine());
			ArrayList<String> dict = new ArrayList<String>(n);
			
			for (int w = 1; w <= n; w++)
				dict.add(in.nextLine());
			
			String test;
			while (!(test = in.nextLine()).equals("END")) {
				char[] c = test.toCharArray();
				Arrays.sort(c);
				String sortedTest = new String(c); 
				int a = 0;
				
				System.out.println("Anagrams for: " + test);
				for (int i = 0; i < n; i++) {
					if (isAnagram(sortedTest, dict.get(i))) {
						System.out.printf("%3d) %s\n", ++a, dict.get(i));
					}
				}
				
				if (a == 0)
					System.out.println("No anagrams for: " + test);
				
			}
			
			if (m != ds)
				System.out.println();
		}
		in.close();
	}
}
