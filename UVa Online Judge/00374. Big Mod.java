import java.util.Scanner;

public class BigMod {
	
	public static long bigPowMod(int b, int p, int m) {
		if (p == 0)
			return 1;
		if (p == 1)
			return b % m;
		
		if (p%2 != 0)
			 return (b%m * bigPowMod( ((b%m)*(b%m)), (p-1) / 2, m)%m)%m;
		else
			return bigPowMod(((b%m)*(b%m))%m, p / 2, m);
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while (in.hasNextInt())
			System.out.println(bigPowMod(in.nextInt(), in.nextInt(), in.nextInt()));
		
		in.close();
	}
}
