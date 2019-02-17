import java.util.Scanner;

class PowerOfCryptography {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n;
		double p;
		
		while (in.hasNextInt()) {
			n = in.nextInt();
			p = in.nextDouble();
			System.out.println((int) Math.round(Math.pow(Math.E, Math.log(p) / n)));
		}

		in.close();
	}
}
