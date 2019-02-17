/* UVa Problem 10193 - All You Need Is Love
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1134
 */
package org.onlinejudge.solved;

import java.util.Scanner;

public class P10193_AllYouNeedIsLove {

	public static int getGCD(int a, int b) {
        int c;
        
        while (true) {
            c = a % b;
            if (c == 0)
                return b;
            a = b;
            b = c;
        }
    }
    
    public static int binConvert(String bin) {
        int dec = 0;
        
        for (int i = 0; i < bin.length(); i++) {
            dec += (Character.getNumericValue(bin.charAt(i)) * Math.pow(2, bin.length() - i - 1));
        }
        return dec;
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int cases, gcd;
        String S1, S2;
  
        cases = scan.nextInt();
           
        for (int caseNum = 1; caseNum <= cases; caseNum++) {
            gcd = -1;
            S1 = scan.next();
            S2 = scan.next();
            
            gcd = getGCD(binConvert(S1), binConvert(S2));
            
            if (gcd == 1)
                System.out.println("Pair #" + caseNum + ": Love is not all you need!");
            else
                System.out.println("Pair #" + caseNum + ": All you need is love!");
            
            
        }
        scan.close();
    }

}
