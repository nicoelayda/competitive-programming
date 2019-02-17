import java.util.Scanner;

public class AutomaticPoetry {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = Integer.parseInt(in.nextLine());
		
		while (n-- != 0) {
			Scanner stream = new Scanner(in.nextLine());
			stream.useDelimiter("");
			
			StringBuilder sb = new StringBuilder("");
			String[] sub = new String[5];
			int i = 0;
			while (stream.hasNext()) {
				String s = stream.next();
				
				if (s.equals("<") || s.equals(">")) {
					sub[i++] = sb.toString();
					sb = new StringBuilder();
				}
				else
					sb.append(s);
			}
			sub[i] = sb.toString();
			
			System.out.println(sub[0]+sub[1]+sub[2]+sub[3]+sub[4]);
			System.out.println(in.nextLine().replace("...", sub[3]+sub[2]+sub[1]+sub[4]));
			stream.close();
		}
		in.close();
	}

}
