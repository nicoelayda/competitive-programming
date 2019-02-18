public class PE14_LongestCollatzSequence {

	public static void main(String[] args) {
		int max = 0, start = -1;
		
		for (int i = 1; i < 1000000; i++) {
			int count = 1;
			long n = i;
			
			while (n != 1) {
				n = n%2 == 0 ? n/2 : 3*n+1;
				count++;
			}
			
			if (count > max) {
				max = count;
				start = i;
				System.out.println(i + " " + count);
			}
		}
		
		System.out.println(start);
	}

}
