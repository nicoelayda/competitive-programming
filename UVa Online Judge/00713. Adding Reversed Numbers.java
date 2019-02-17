/* 
 * UVa Problem 713 - Adding Reversed Numbers
 * http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=654
 */

import java.math.BigInteger;
import java.util.Scanner;

class AddingReversedNumbers {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testCases = Integer.parseInt(scan.next());
		
		while (testCases-- != 0) {
			BigInteger num = new BigInteger(new StringBuilder(scan.next()).reverse().toString());
			num = num.add(new BigInteger(new StringBuilder(scan.next()).reverse().toString()));
			
			System.out.println(new StringBuilder(num.toString()).reverse().toString().replaceFirst("^0+(?!$)", ""));
		}
		scan.close();
	}
}
