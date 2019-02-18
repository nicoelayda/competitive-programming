public class PE10_SummationOfPrimes {
	
	public static void main(String[] args) {
		long sum = 0;
		int limit = 2000000;
		boolean[] isComposite = new boolean[limit+1];
		
		for (int i = 2; i*i <= limit; i++)
			if (!isComposite[i])
				for (int j = i*i; j <= limit; j += i)
					isComposite[j] = true;
		
		for (int i = 2; i <= limit; i++)
			if (!isComposite[i])
				sum += i;
		
		System.out.println(sum);
	}

}