import java.math.BigInteger;
import java.util.Scanner;

public class IfWeWereAChildAgain {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (in.hasNext()) {
			BigInteger op1 = in.nextBigInteger();
			String operator = in.next();
			BigInteger op2 = in.nextBigInteger();
			
			if (operator.equals("/")) {
				System.out.println(op1.divide(op2));
			} 
			else {
				System.out.println(op1.remainder(op2));
			}
		}
		
		in.close();
	}

}
