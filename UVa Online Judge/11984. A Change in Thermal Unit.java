import java.text.DecimalFormat;
import java.util.Scanner;

class AChangeInThermalUnit {

	private static double toFahrenheit(double c) {
		return (9.0/5) * c - 32;
	}
	
	private static double toCelsius(double f) {
		return (5.0/9) * (f + 32);
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		DecimalFormat df = new DecimalFormat("0.00");
		int T = in.nextInt();
		
		for (int tc = 1; tc <= T; tc++) {
			System.out.println("Case " + tc + ": " + df.format(toCelsius(toFahrenheit(in.nextInt()) + in.nextInt())));
		}
		
		in.close();
	}

}
