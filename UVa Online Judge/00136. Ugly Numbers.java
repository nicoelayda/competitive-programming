public class UglyNumbers {
	
	public static void main(String[] args) {
		long[] ugly = new long[1500];
		long[] val = {1, 1, 1};
		int[] u = {0, 0, 0};
		
		ugly[0] = 1;
		
		for (int i = 1; i < 1500; i++) {
			val[0] = ugly[u[0]] * 2;
			val[1] = ugly[u[1]] * 3;
			val[2] = ugly[u[2]] * 5;
			
			ugly[i] = Math.min(val[0], Math.min(val[1], val[2]));
			
			if (ugly[i] == val[0]) u[0]++;
			if (ugly[i] == val[1]) u[1]++;
			if (ugly[i] == val[2]) u[2]++;
		}
		
		System.out.println("The 1500'th ugly number is " + ugly[1499] + ".");
	}
}
