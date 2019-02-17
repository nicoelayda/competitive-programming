import java.util.Scanner;

public class Cola {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		while (scan.hasNextInt()) {
			int n = scan.nextInt();
			int total = n;
			int empty = n;
			
			while (empty >= 3) {				
				int free = empty / 3;
				empty = empty - free * 3 + free; 
				
				total += free;
			}
			
			if (empty == 2) {
				total+= 1;
			}
				
			System.out.println(total);
		}
		
		scan.close();
	}

}
