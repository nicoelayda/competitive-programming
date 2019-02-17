import java.util.Scanner;

public class Overflow {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String inputString, operator;
		String[] inputs;
		double firstNum, secondNum, result;
		
		while (scan.hasNext()) {
			inputString = scan.nextLine();
			inputs = inputString.trim().split(" +");
			
			firstNum = Double.parseDouble(inputs[0]);
			secondNum = Double.parseDouble(inputs[2]);
			operator = inputs[1];
			
			if (operator.equals("+"))
				result = firstNum + secondNum;
			else
				result = firstNum * secondNum;
			
			System.out.println(inputString);
			
			if (firstNum > Integer.MAX_VALUE)
				System.out.println("first number too big");
			
			if (secondNum > Integer.MAX_VALUE)
				System.out.println("second number too big");
				
			if (result > Integer.MAX_VALUE)
				System.out.println("result too big");
			
		}
		
		scan.close();
	}

}
