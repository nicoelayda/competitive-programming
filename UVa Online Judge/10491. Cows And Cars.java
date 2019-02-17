import java.text.DecimalFormat;
import java.util.Scanner;

class CowsAndCars {

	public static void main(String[] args) {
		DecimalFormat df = new DecimalFormat("0.00000");
		Scanner in = new Scanner(System.in);
		while (in.hasNextInt()) {
			int cows = in.nextInt();
			int cars = in.nextInt();
			int show = in.nextInt();
			int total = cows + cars;
			
			System.out.println(df.format((cars * (total - 1)/(double)(total * (total - show - 1)))));
		}
		in.close();
	}
}