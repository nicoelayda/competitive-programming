import java.text.DecimalFormat;
import java.util.Scanner;

class ClockHands {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (true) {
			String[] time = in.nextLine().split(":");
			if (time[0].equals("0") && time[1].equals("00")) break;
			
			double angle = Math.abs(0.5 * (60 * Integer.parseInt(time[0]) - 11 * Integer.parseInt(time[1])));
			System.out.println(new DecimalFormat("0.000").format(angle > 180 ? 360 - angle : angle));
		}
		
		in.close();
	}

}
