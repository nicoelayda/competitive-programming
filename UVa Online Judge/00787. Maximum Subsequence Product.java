import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MaximumSubsequenceProduct {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while (in.hasNext()) {
            int n;
            List<Integer> numbers = new ArrayList<Integer>();
            while (in.hasNextInt() && (n = in.nextInt()) != -999999) {
                numbers.add(n);
            }

            BigInteger product, maxProduct = BigInteger.valueOf(numbers.get(0));

            for (int i = 0; i < numbers.size(); i++) {
                product = BigInteger.valueOf(numbers.get(i));
                maxProduct = maxProduct.max(product);

                for (int j = i + 1; j < numbers.size(); j++) {
                    product = product.multiply(BigInteger.valueOf(numbers.get(j)));
                    maxProduct = maxProduct.max(product);
                }
            }

            System.out.println(maxProduct.toString());
        }

        in.close();
    }
}