import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class SloganLearningOfPrincess {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Map<String, String> map = new HashMap<String, String>();
		
		int n = Integer.parseInt(scan.nextLine());
		for (int i = 0; i < n; i++) {
			map.put(scan.nextLine(), scan.nextLine());
		}
		
		int q = Integer.parseInt(scan.nextLine());
		for (int i = 0; i < q; i++) {
			System.out.println(map.get(scan.nextLine()));
		}
		
		scan.close();
	}

}
