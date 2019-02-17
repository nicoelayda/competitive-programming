import java.util.Scanner;

public class SMSTyping {

	private static int getKeyPresses(char ch) {
		switch (ch) {
    		case 'a': case 'd': case 'g': case 'j': case 'm':
    		case 'p': case 't': case 'w': case ' ':
    			return 1;
    		case 'b': case 'e': case 'h': case 'k': case 'n':
    		case 'q': case 'u': case 'x':
    			return 2;
    		case 'c': case 'f': case 'i': case 'l': case 'o':
    		case 'r': case 'v': case 'y':
    			return 3;
    		case 's': case 'z':
    			return 4;
		}
		return 0;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = Integer.parseInt(in.nextLine());
		
		for (int tc = 1; tc <= T; tc++) {
			int sum = 0;
			for (char ch : in.nextLine().toCharArray())
				sum += getKeyPresses(ch);
			
			System.out.println("Case #" + tc + ": " + sum);
		}
		
		in.close();
	}
}