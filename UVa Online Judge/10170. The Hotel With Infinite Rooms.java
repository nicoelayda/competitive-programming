import java.util.Scanner;

public class TheHotelWithInfiniteRooms {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		while (in.hasNextInt()) {
			int i, S = in.nextInt();
			long D = in.nextLong();
			long day = 0;
			
			for (i = S; day < D; i++)
				day += i;
			
			System.out.println(i-1);
		}
		in.close();
	}
}
