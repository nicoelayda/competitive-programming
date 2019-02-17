import java.util.Scanner;
import java.math.BigInteger;

public class MultipleOf17 {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger n;

        while (!(n = new BigInteger(in.nextLine())).equals(BigInteger.ZERO)) {
            System.out.println(n.mod(BigInteger.valueOf(17)).equals(BigInteger.ZERO) ? "1" : "0");
        }

        in.close();
    }
}