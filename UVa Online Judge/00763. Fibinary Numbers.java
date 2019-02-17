import java.math.BigInteger;
import java.util.Scanner;

public class FibinaryNumbers {
    
    static BigInteger[] fib = new BigInteger[201];

    private static String toFibinary(BigInteger n) {
        StringBuilder fibinary = new StringBuilder();

        int i = 1;
        while (n.compareTo(fib[i]) >= 0) {
            i++;
        }

        while (i >= 1) {
            if (n.compareTo(fib[i]) != -1) {
                fibinary.append("1");
                n = n.subtract(fib[i]);

                if (i != 1) {
                    fibinary.append("0");
                    i--;
                }
            }
            else if (fibinary.length() != 0) {
                fibinary.append("0");
            }

            i--;
        }

        if (fibinary.length() == 0)
            fibinary.append("0");

        return fibinary.toString();
    }

    private static BigInteger toDecimal(String str) {
        BigInteger sum = BigInteger.ZERO;

        for (int i = str.length() - 1, j = 1; i >= 0; i--, j++) {
            if (str.charAt(i) == '1')
                sum = sum.add(fib[j]);
        }

        return sum;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        fib[0] = fib[1] = BigInteger.ONE;

        for (int i = 2; i <= 200; i++) {
            fib[i] = fib[i - 2].add(fib[i - 1]);
        }

        while (in.hasNextLine()) {
            BigInteger sum = toDecimal(in.nextLine()).add(toDecimal(in.nextLine()));
            System.out.println(toFibinary(sum));

            if (in.hasNextLine()) {
                in.nextLine();
                System.out.println();
            }
        }

        in.close();
    }
}