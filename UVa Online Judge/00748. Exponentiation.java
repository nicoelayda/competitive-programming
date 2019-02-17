/* UVa Problem 748 - Exponentiation
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=689
 */

import java.math.BigDecimal;
import java.util.Scanner;

public class Exponentiation {
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		while(scan.hasNext()) {	
			BigDecimal r = new BigDecimal(scan.next());
			int n = scan.nextInt();
			
			r = r.pow(n);
			
			String output = r.stripTrailingZeros().toPlainString();
			if(output.charAt(0) == '0')
				output = output.substring(1,output.length());
			
			System.out.println(output);	
		}
		
		scan.close();
	}
}
