import java.math.BigInteger;

public class PE48_SelfPowers {

    public static void main(String[] args) {
        int n = 1000;
        BigInteger sum = BigInteger.ZERO;

        for (int i = 1; i <= n; i++)
            sum = sum.add(new BigInteger(String.valueOf(i)).pow(i));

        String result = sum.toString();
        System.out.println(result.substring(result.length() - 10, result.length()));
    }
}