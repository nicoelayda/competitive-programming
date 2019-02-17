import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

class TheDoleQueue {

	static int mod(int a, int b) {
		return ((a % b) + b) % b;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String line;
		
		while ((line = in.readLine()) != null) {
			String[] tokens = line.split(" ");
			int n = Integer.parseInt(tokens[0]);
			int k = Integer.parseInt(tokens[1]);
			int m = Integer.parseInt(tokens[2]);
			
			if (n == 0 && k == 0 && m == 0) break;
			
			ArrayList<Integer> doleQueue = new ArrayList<Integer>(n);
			for (int i = 1; i <= n; i++)
				doleQueue.add(i);
			
			int ki = -1;
			int mi = n;
			int rem1, rem2;
			StringBuilder sb = new StringBuilder();
			while (!doleQueue.isEmpty()) {
				ki = mod(ki+k, doleQueue.size());
				mi = mod(mi-m, doleQueue.size());
				
				if (sb.length() != 0)
					sb.append(",");
				
				if (ki == mi) {
					sb.append(String.format("%3d", doleQueue.remove(ki--)));
				} else if (ki > mi) {
					sb.append(String.format("%3d", doleQueue.remove(ki)));
					sb.append(String.format("%3d", doleQueue.remove(mi)));
					ki -= 2;
				} else {
					rem1 = doleQueue.remove(mi--);
					rem2 = doleQueue.remove(ki--);
					sb.append(String.format("%3d", rem2));
					sb.append(String.format("%3d", rem1));
				}
			}
			
			System.out.println(sb.toString());
		}
	}
}