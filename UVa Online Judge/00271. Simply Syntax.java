import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class SimplySyntax {

	private static boolean isCorrect(String s) {
		int count = 0;
		
		for (int i = s.length()-1; i >= 0; i--) {
			if (Character.isLowerCase(s.charAt(i))) {
				count++;
			} else if (s.charAt(i) == 'N') {
				if (count == 0)
					return false;
			} else {
				if (count < 2)
					return false;
				else
					count--;
					
			}
		}
		
		return count == 1;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String line;
		
		while ((line = in.readLine()) != null)
			System.out.println(isCorrect(line) ? "YES" : "NO");
	}

}
