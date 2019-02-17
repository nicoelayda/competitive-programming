import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class GreedyGiftGivers {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (in.hasNext()) {
			Map<String, Integer> expenses = new HashMap<String, Integer>();
			
			int n = Integer.parseInt(in.nextLine());
			String persons[] = in.nextLine().split(" ");
			
			for (int i = 0; i < n; i++)
				expenses.put(persons[i], 0);
			
			for (int i = 0; i < n; i++) {
				String gifter = in.next();
				int spent = in.nextInt();
				int r = in.nextInt();
				int g = r != 0 ? spent / r : 0;
				
				for (int j = 0; j < r; j++) {
					String giftee = in.next();
					expenses.put(giftee, expenses.get(giftee) + g);
				}
				
				expenses.put(gifter, expenses.get(gifter) - (g * r));
				in.nextLine();
			}
			
			for (int i = 0; i < n; i++)
				System.out.println(persons[i] + " " + expenses.get(persons[i]));
			
			if (in.hasNext())
				System.out.println();
		}
		
		in.close();
	}
}
