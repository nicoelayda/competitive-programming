import java.math.BigInteger;

public class PE20_FactorialDigitSum {
    
    public static void main(String[] args) {
        int sum = 0;
        BigInteger n = BigInteger.ONE;
        for (int i = 2; i <= 100; i++)
            n = n.multiply(new BigInteger(Integer.toString(i)));

        for (char ch : n.toString().toCharArray())
            sum += (ch - '0');
    
        System.out.println(sum);
    }
}