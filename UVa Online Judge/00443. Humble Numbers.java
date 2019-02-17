import java.util.Scanner;

public class HumbleNumbers {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long[] humble = new long[5842];
		long[] val = {1, 1, 1, 1};
		int[] hi = {0, 0, 0, 0};
		
		humble[0] = 1;
		
		for (int i = 1; i < 5842; i++) {
			val[0] = humble[hi[0]] * 2;
			val[1] = humble[hi[1]] * 3;
			val[2] = humble[hi[2]] * 5;
			val[3] = humble[hi[3]] * 7;
			
			humble[i] = Math.min(val[0], Math.min(val[1], Math.min(val[2], val[3])));
			
			if (humble[i] == val[0]) hi[0]++;
			if (humble[i] == val[1]) hi[1]++;
			if (humble[i] == val[2]) hi[2]++;
			if (humble[i] == val[3]) hi[3]++;
		}
		
		int n;
		while ((n = in.nextInt()) != 0) {
			if (n%100 == 11 || n%100 == 12 || n%100 == 13)
				System.out.print("The " + n + "th humble number is "); 
			else if (n%10 == 1)
				System.out.print("The " + n + "st humble number is ");
			else if (n%10 == 2)
				System.out.print("The " + n + "nd humble number is ");
			else if (n%10 == 3)
				System.out.print("The " + n + "rd humble number is ");
			else
				System.out.print("The " + n + "th humble number is ");
			
			System.out.println(humble[n-1] + ".");
		}
		
		in.close();
	}
}
