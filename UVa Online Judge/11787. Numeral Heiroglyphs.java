import java.util.Scanner;

class NumeralHeiroglyphs {
	
	public static boolean isValidHeiroglyph (String heiroglyph) {
		boolean isAscending = true;
		boolean isDescending = true;
		boolean overflow = false;
		
		int lastVal = -1;
		int currVal = 0;
		int currValCount = 0;
		
		for (char c : heiroglyph.toCharArray()) {
			currVal = getCharVal(c);
			
			if (lastVal == -1) {
				lastVal = currVal;
			}
			
			// Check if consecutive
			if (currVal == lastVal) {
				currValCount++;
			}
			else {
				currValCount = 1;
			}
			
			// Check for overflow
			if (currValCount >= 10) {
				overflow = true;
				break;
			}
			
			// Check descending
			if (currVal > lastVal) {
				isDescending = false;
			}
			
			// Check ascending
			if (currVal < lastVal) {
				isAscending = false;
			}
		
			lastVal = currVal;
		}
		
		return (isAscending || isDescending) && !overflow;
	}
	public static int getCharVal(char c) {
		switch (c) {
		case 'B':
			return 1;
		case 'U':
			return 10;
		case 'S':
			return 100;
		case 'P':
			return 1000;
		case 'F':
			return 10000;
		case 'T':
			return 100000;
		case 'M':
			return 1000000;
		}
		
		return 0;
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int cases = Integer.parseInt(scan.nextLine());
		
		while (cases-- != 0) {
			String input = scan.nextLine();
			int totalVal = 0;
			
			if (isValidHeiroglyph(input)) {
				for (char c : input.toCharArray()) {
					totalVal += getCharVal(c);
				}
				
				System.out.println(totalVal);
			}
			else {
				System.out.println("error");
			}
		}
		
		scan.close();
	}

}
