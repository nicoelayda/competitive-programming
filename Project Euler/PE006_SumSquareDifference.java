public class PE06_SumSquareDifference {

	static final int n = 100;
	
	public static void main(String[] args) {
		// Sum of first n squares: n(n+1)(2n+1) / 6
		// Sum of first n numbers: n(n+1) / 2
		
		System.out.println((long) Math.pow((n * (n+1)) / 2, 2) - ((n * (n+1) * (2*n+1)) / 6));
	}

}
