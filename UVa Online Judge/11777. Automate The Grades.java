import java.util.Scanner;

public class AutomateTheGrades {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		int ct1, ct2, ct3;
		double total;
		char grade;
		
		
		for (int i = 1; i <= T; i++) {
			total = 0;

			total += scan.nextDouble(); // term 1
			total += scan.nextDouble(); // term 2
			total += scan.nextDouble(); // final
			total += scan.nextDouble(); // attendance
			ct1 = scan.nextInt(); // class tests
			ct2 = scan.nextInt();
			ct3 = scan.nextInt();
			total += ((ct1 + ct2 + ct3 - Math.min(ct1, Math.min(ct2, ct3))) / 2);
			
			if (total >= 90)
				grade = 'A';
			else if (total >= 80 && total < 90)
				grade = 'B';
			else if (total >= 70 && total < 80)
				grade = 'C';
			else if (total >= 60 && total < 70)
				grade = 'D';
			else
				grade = 'F';
			
			System.out.println("Case " + i + ": " + grade);
		}
		
		scan.close();
	}

}
