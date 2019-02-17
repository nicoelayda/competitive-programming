import java.text.DecimalFormat;
import java.util.Scanner;

class P12578_10_6_2 {

	static final double PI = Math.acos(-1);
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		DecimalFormat df = new DecimalFormat("0.00");
		int T = scan.nextInt();
		double l, w, r, red, green;
		
		while (T-- != 0) {
			l = scan.nextInt();
			w = l * 0.6;
			r = l * 0.2;
			red = PI * r * r;
			green = l * w - red;
			
			System.out.println(df.format(red) + " " + df.format(green));
		}
		
		scan.close();
	}

}
