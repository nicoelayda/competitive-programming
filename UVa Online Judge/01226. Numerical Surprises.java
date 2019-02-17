import java.math.BigInteger;
import java.util.Scanner;

public class NumericalSurprises {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = Integer.parseInt(in.nextLine());

        while (T-- != 0) {
            BigInteger n = new BigInteger(in.nextLine());
            BigInteger p = new BigInteger(in.nextLine());

            System.out.println(p.mod(n).toString());
        }

        in.close();
    }
}