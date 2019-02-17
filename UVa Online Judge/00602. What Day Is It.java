import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class WhatDayIsIt {
		
	static boolean leap;
	static boolean julian;
	
	static String getMonth(int m) {
		switch (m) {
			case 1:
				return "January";
			case 2:
				return "February";
			case 3:
				return "March";
			case 4:
				return "April";
			case 5:
				return "May";
			case 6:
				return "June";
			case 7:
				return "July";
			case 8:
				return "August";
			case 9:
				return "September";
			case 10:
				return "October";
			case 11:
				return "November";
			default:
				return "December";			
		}
	}
	
	static String dayOfWeek(int month, int day, int year) {
		int Y = (month > 2 ? year : year-1);
		int m = mod(month-2, 12);
		if (m == 0) m = 12;
		int c = Y % 100;
		int w;
		
		if (!julian) {
			w =  (int)(day + Math.floor(2.6*m - 0.2) + 5*mod(c, 4) + 4*mod(Y, 100) + 6*mod(Y,400)) % 7;
		} else {
			w =  (int)(day + Math.floor(2.6*m - 2.2) + 5*mod(c, 4) + 3*mod(Y, 7)) % 7;
		}
				
		switch(w) {
			case 0:
				return "Sunday";
			case 1:
				return "Monday";
			case 2:
				return "Tuesday";
			case 3:
				return "Wednesday";
			case 4:
				return "Thursday";
			case 5:
				return "Friday";
			default:
				return "Saturday";
		}
	}
	
	static boolean setDate(int m, int d, int y) {
		julian = y < 1752 || (y== 1752 && (m <= 9 && d <= 2 || m < 9));
		if (!julian)
			leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
		else
			leap = y % 4 == 0;
		
		boolean valid = true;
		
		if (y == 1752 && m == 9 && d >= 3 && d <= 13)
			return false;
		
		if (y < 0)
			valid = false;
		
		
		if (m < 1 || m > 12)
			valid = false;
		
		switch (m) {
		case 1: case 3:
		case 5:	case 7:
		case 8:	case 10:
		case 12:
			if (d < 1 || d > 31)
				valid = false;
			break;
		case 2:
			if (d < 1 || (leap && d > 29) || (!leap && d > 28))
				valid = false;
			break;
		default:
			if (d < 1 || d > 30)
				valid = false;
		}
		
		return valid;
	}
	
	static int mod(int a, int b) {
		return (((a % b) + b) % b);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb;
		String line;
		int m, d, y;
		while ((line = in.readLine()) != null) {
			
			String[] tokens = line.split(" ");
			m = Integer.parseInt(tokens[0]);
			d = Integer.parseInt(tokens[1]);
			y = Integer.parseInt(tokens[2]);
			
			if (m == 0 && d == 0 && y == 0)
				break;
			
			if (setDate(m, d, y))
				sb = new StringBuilder(getMonth(m)).append(" ").append(d).append(", ").append(y).append(" is a ").append(dayOfWeek(m, d, y));
			else
				sb = new StringBuilder().append(m).append("/").append(d).append("/").append(y).append(" is an invalid date.");
			
			System.out.println(sb.toString());
				
		}
	}

}
