import java.util.Scanner;

public class TEXQuotes {
	
	public static void main(String[] args)  {
		Scanner in = new Scanner(System.in);
		int count = 0;
		
		while (in.hasNextLine()) {
			String line = in.nextLine();
			
			while (line.contains("\""))
				line = line.replaceFirst("\"", count++ % 2 == 0 ? "``" : "''");
				
			System.out.println(line);
		}
		
		in.close();
	}
}
