import java.util.Scanner;

class TheSnail {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		double h, u, d, f;
		double o;
		double l;
		int day;
		
		while (true) {
			h = in.nextInt();
			u = in.nextInt();
			d = in.nextInt();
			f = in.nextInt();
			
			if (h == 0) {
				break;
			}
			
			// reset offset
			o = 0;
			// reset day
			day = 0;
			// set fatigue loss
			l = (f / 100) * u;
			
			while (true) {
				day++; // new day
				
				o += u; // climb
				
				if (o > h) {
					System.out.println("success on day " + day);
					break;
				}
					
				
				o -= d; // sleep
				
				if (o < 0) {
					System.out.println("failure on day " + day);
					break;	
				}
				
				u -= l; // fatigue
				
				if (u < 0) {
					u = 0;
				}
			}
			
			
		}
		in.close();
	}

}
