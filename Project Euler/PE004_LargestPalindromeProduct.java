public class PE04_LargestPalindromeProduct {

	private static boolean isPalindrome(int n) {
		String s = Integer.toString(n);
		int end = s.length();
		int mid = end / 2;
		
		for (int i = 0; i < mid; i++) {
			if (s.charAt(i) != s.charAt(end - i - 1))
				return false;
		}
		
		return true;
	}
	
	public static void main(String[] args) {
		int prod, max = 0;
		for (int i = 999; i >= 100; i--) {
			for (int j = i; j >= 100; j--) {
				if ((prod = i*j) <= max)
					break;
				
				if (isPalindrome(prod) && prod > max)
					max = prod;
			}
		}
		System.out.println(max);
	}

}
