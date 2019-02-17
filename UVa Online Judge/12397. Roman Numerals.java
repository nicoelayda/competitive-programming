/* UVa Problem 12397 - Roman Numerals
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3828
 */
package org.onlinejudge.solved;

import java.util.Scanner;

public class P12397_RomanNumerals {

	private static int countHeads(String romanString) {
        int totalHeads = 0;

        for (char c : romanString.toCharArray()) {
            switch (c) {
                case 'I':
                    totalHeads += 1;
                    break;

                case 'V':
                case 'X':
                case 'L':
                case 'C':
                    totalHeads += 2;
                    break;

                case 'D':
                    totalHeads += 3;
                    break;

                case 'M':
                    totalHeads += 4;
                    break;
            }    
        }

        return totalHeads;
    }
	
	private static String convertToRomanString(int i) {
        final String huns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        final String tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        final String ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        String romanString = "";

        while (i >= 1000) {
            romanString += "M";
            i -= 1000;
        }

        romanString += huns[i / 100];
        i %= 100;

        romanString += tens[i / 10];
        i %= 10;

        romanString += ones[i];

        return romanString;
    }
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

        while (scan.hasNext()) {
            int n = scan.nextInt();
            System.out.println(countHeads(convertToRomanString(n)));
        }

        scan.close();
	}
}
