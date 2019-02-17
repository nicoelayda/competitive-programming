import java.math.BigInteger;
import java.util.Scanner;

public class LeapYearOrNotLeapYearAnd {
	
	static BigInteger FOUR = new BigInteger("4");
	static BigInteger ONEHUNDRED = new BigInteger("100");
	static BigInteger FOURHUNDRED = new BigInteger("400");
	static BigInteger FIFTEEN = new BigInteger("15");
	static BigInteger FIFTYFIVE = new BigInteger("55");
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (in.hasNextBigInteger()) {
			boolean ordinary = true;
			boolean bulukulu = false;
			BigInteger n = in.nextBigInteger();
			
			if ((n.mod(FOUR).equals(BigInteger.ZERO) && !n.mod(ONEHUNDRED).equals(BigInteger.ZERO)) ||
					n.mod(FOURHUNDRED).equals(BigInteger.ZERO)) {
				System.out.println("This is leap year.");
				ordinary = false;
				
				if (n.mod(FIFTYFIVE).equals(BigInteger.ZERO))
					bulukulu = true;
			}
			
			if (n.mod(FIFTEEN).equals(BigInteger.ZERO)) {
				System.out.println("This is huluculu festival year.");
				ordinary = false;
			}
			
			if (bulukulu) {
				System.out.println("This is bulukulu festival year.");
			}
			
			if (ordinary) {
				System.out.println("This is an ordinary year.");
			}
			
			if (in.hasNextBigInteger())
				System.out.println();
		}
		
		in.close();
	}

}
