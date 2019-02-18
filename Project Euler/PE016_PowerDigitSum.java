import java.math.BigInteger;

public class PE16_PowerDigitSum {

	public static void main(String[] args) {
		int sum = 0;
		
		for (char ch : new BigInteger("2").pow(1000).toString().toCharArray())
			sum += Character.getNumericValue(ch);

		System.out.println(sum);
	}

}
