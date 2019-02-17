package org.onlinejudge.solved;
import java.util.Scanner;


public class P10921_FindTheTelephone {
	
	private static boolean isLetter(char c) {
		return c >= 'A' && c <= 'Z';
	}
	
	private static char getPhoneNum(char c) {
		switch (c) {
		case 'A':
		case 'B':
		case 'C':
			return '2';
		case 'D':
		case 'E':
		case 'F':
			return '3';
		case 'G':
		case 'H':
		case 'I':
			return '4';
		case 'J':
		case 'K':
		case 'L':
			return '5';
		case 'M':
		case 'N':
		case 'O':
			return '6';
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
			return '7';
		case 'T':
		case 'U':
		case 'V':
			return '8';
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			return '9';
		default:
			return 0;
		}
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		while (scan.hasNextLine()) {
			String input = scan.nextLine();
			String output = "";
			for (char c : input.toCharArray()) {
				if (isLetter(c)) {
					output += getPhoneNum(c);
				}
				else {
					output += c;
				}
			}
			System.out.println(output);
		}
		
		scan.close();
	}

}
