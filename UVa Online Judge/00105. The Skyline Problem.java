import java.util.Scanner;

class TheSkylineProblem {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] skyline = new int[10001];
		int min = 10000, max = 0;
		int y = 0;
		
		while (in.hasNextInt()) {
			int l = in.nextInt();
			int h = in.nextInt();
			int r = in.nextInt();
			
			if (l < min)
				min = l;
			else if (r > max)
				max = r;
			
			for (int i = l; i <= r; i++) {
				if (skyline[i] < h)
					skyline[i] = h;
			}
		}

		StringBuilder sb = new StringBuilder();
		
		for (int i = min; i <= max + 1; i++) {
			if (skyline[i] != y) {
				if (y < skyline[i])
					sb.append(i).append(" ").append(skyline[i]).append(" ");
				else if (y > skyline[i])
					sb.append(i - 1).append(" ").append(skyline[i]).append(" ");

				y = skyline[i];
			}
		}
		
		System.out.println(sb.toString().trim());
		in.close();
	}

}
