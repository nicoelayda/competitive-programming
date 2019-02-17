import java.math.BigInteger;
import java.util.Scanner;

class VeryEasy {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int n, a;
		BigInteger sum;
		
		while (scan.hasNext()) {
			n = scan.nextInt();
			a = scan.nextInt();
			sum = BigInteger.ZERO;
			
			for (int i = 1; i <= n; i++) {
				sum = sum.add(new BigInteger("" + a).pow(i).multiply(new BigInteger("" + i)));
			}
			
			System.out.println(sum.toString());
		}
		
		scan.close();
	}

}
