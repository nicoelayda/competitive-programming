import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class SkewBinary {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String line;
		
		while (!(line = in.readLine()).equals("0")) {
			int sum = 0;
			int l = line.length();
			
			for (int i = 0; i < l; i++)
				sum += (Character.getNumericValue(line.charAt(i)) * (Math.pow(2, l-i)-1));
			
			System.out.println(sum);
		}
	}

}
