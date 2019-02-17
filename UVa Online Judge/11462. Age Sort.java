import java.util.Arrays;
import java.util.Scanner;

public class AgeSort {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		StringBuilder sb;
		int[] data;
		int n;
		
		while ((n = scan.nextInt()) != 0) {
			data = new int[n];
			
			for (int i = 0; i < n; i++) {
				data[i] = scan.nextInt();
			}
			
			Arrays.sort(data);
			
			sb = new StringBuilder();
			
			for (int i = 0; i < n; i++) {
				sb.append(data[i]);
				
				if (i != n - 1)
					sb.append(" ");
			}
			
			System.out.println(sb.toString());
		}
		
		scan.close();
	}

}
