class PE001_MultiplesOf3And5 {

	static final int target = 999;
	
	private static int sumOfMultiples(int n) {
		int p = target / n;
		return n * (p * (p + 1)) / 2;
	}
	
	public static void main(String[] args) {
		System.out.println(sumOfMultiples(3) + sumOfMultiples(5) - sumOfMultiples(15));
	}

}
