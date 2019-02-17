import java.util.Scanner;

class ErrorCorrection {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n;
		int rowSum, colSum;
		int rowError, colError;
		boolean corrupt;
		
		while ((n = in.nextInt()) != 0) {
			int[][] data = new int[n][n];
			
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					data[i][j] = in.nextInt();
			
			corrupt = false;
			rowError = colError = -1;
			
			for (int i = 0; i < n; i++) {
				rowSum = colSum = 0;
				for (int j = 0; j < n; j++) {
					rowSum += data[i][j];
					colSum += data[j][i];
				}
				
				if (rowSum % 2 != 0) {
					if (rowError == -1)
						rowError = i;
					else {
						corrupt = true;
						break;
					}
						
				}
				
				if (colSum % 2 != 0) {
					if (colError == -1)
						colError = i;
					else {
						corrupt = true;
						break;
					}
				}
			}
			
			if (corrupt || (colError != -1 ^ rowError != -1))
				System.out.println("Corrupt");
			else if (colError != -1 && rowError != -1)
				System.out.println("Change bit (" + (rowError+1) + "," + (colError+1) + ")");
			else
				System.out.println("OK");
		}
		
		in.close();
	}

}
