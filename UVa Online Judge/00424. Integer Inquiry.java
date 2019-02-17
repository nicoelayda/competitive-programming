import java.math.BigInteger;
import java.util.Scanner;

public class IntegerInquiry {
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		BigInteger sum = new BigInteger("0");
		
		while (scan.hasNext()) {
			String input = scan.next();
			
			if (input.equals("0")) {
				break;
			}
			
			sum = sum.add(new BigInteger(input));
		}
		
		System.out.println(sum.toString());
		scan.close();
	}

}