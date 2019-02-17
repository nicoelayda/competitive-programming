import java.math.BigInteger;
import java.util.Scanner;

public class BasicRemains {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int base;

        while ((base = in.nextInt()) != 0) {
            BigInteger p = new BigInteger(in.next(), base);
            BigInteger m = new BigInteger(in.next(), base);

            System.out.println(p.mod(m).toString(base));
        }
        
        in.close();
    }
}