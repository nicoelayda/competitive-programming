public class PE09_SpecialPythagoreanTriplet {

	public static void main(String[] args) {
		int limit = 1000;
		int[] sq = new int[limit+1];
		
		for (int i = 1; i <= limit; i++) {
			sq[i] = i*i;
		}
		
		for (int a = 1; a < limit; a++) {
			for (int b = a+1; b <= limit-a; b++) {
				for (int c = b+1; c <= limit-b-a; c++) {
					if (a+b+c == limit && sq[a] + sq[b] == sq[c])
						System.out.println(a * b * c);
				}
			}
		}

	}

}
