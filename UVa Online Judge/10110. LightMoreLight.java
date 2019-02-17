import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class LightMoreLight {

	public final static boolean isPerfectSquare(long n) {
		long tst = (long) (Math.sqrt(n) + 0.5);
		return tst * tst == n;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		long n;

		while ((n = Long.parseLong(in.readLine())) != 0) {
			System.out.println(isPerfectSquare(n) ? "yes" : "no");
		}
	}
}
