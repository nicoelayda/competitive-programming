import java.util.Scanner;

class GroupReverse {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (true) {
			String[] tc = in.nextLine().split(" ");
			int g = Integer.parseInt(tc[0]);
			if (g == 0) break;
			String word = tc[1];
			int gl = word.length() / g;
			
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < word.length(); i++) {
				sb.append(word.charAt(i));
				if ((i+1)%gl == 0) {
					System.out.print(sb.reverse().toString());
					sb = new StringBuilder();
				}
			}
			System.out.println();
		}
		
		in.close();
	}

}
