import java.util.Scanner;
import java.math.BigInteger;

public class FibonacciFreeze {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger[] fib = new BigInteger[5001];
        
        fib[0] = BigInteger.ZERO;
        fib[1] = BigInteger.ONE;

        for (int i = 2; i <= 5000; i++)
            fib[i] = fib[i-1].add(fib[i-2]);

        while (in.hasNextInt()) {
            int n = in.nextInt();
            System.out.println("The Fibonacci number for " + n + " is " + fib[n].toString());
        }
    }
}