import java.util.Scanner;

class WordScramble {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (in.hasNextLine()) {
			String line = in.nextLine();
			StringBuilder out = new StringBuilder();
			
			for (String word : line.split(" "))
				out.append(new StringBuilder(word).reverse()).append(" ");
			
			System.out.println(out.toString().trim());
		}	
		in.close();
	}

}
