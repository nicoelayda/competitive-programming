import java.math.BigInteger;
import java.util.Scanner;

public class Tiling {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger[] lookup = new BigInteger[251];
        lookup[0] = BigInteger.ONE;
        lookup[1] = BigInteger.ONE;

        for (int i = 2; i <= 250; i++) {
            lookup[i] = lookup[i-1].add(lookup[i-2].multiply(BigInteger.valueOf(2)));
        }

        while (in.hasNextInt()) {
            System.out.println(lookup[in.nextInt()].toString());
        }

        in.close();
    }
}