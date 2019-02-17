import java.util.Scanner;

public class GoogleIsFeelingLucky {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int cases = scan.nextInt();
		
		for (int c = 1; c <= cases; c++) {
			int max = 0;
			String results = "";
			
			System.out.println("Case #" + c + ":");
			
			for (int i = 0; i < 10; i++) {
				String url = scan.next();
				int relevance = scan.nextInt();
				
				if (relevance > max) {
					max = relevance;
					results = url + "\n";
				}
				else if (relevance == max) {
					results += url + "\n";
				}
			}
			
			System.out.print(results);
		}
		
		scan.close();
	}

}
