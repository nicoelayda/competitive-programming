package org.onlinejudge.solved;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P10033_Interpreter {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(in.readLine());
		in.readLine();
		
		while (tc-- != 0) {
			int[] ram = new int[1000];
			int[] reg = new int[10];
			int count = 0, ex = 0;
			boolean halt = false;
			String inst;
			
			while ((inst = in.readLine()) != null && !inst.equals(""))
				ram[count++] = Integer.parseInt(inst);
			
			for (int address = 0; !halt; address++, ex++) {
				int cmd = ram[address]/100;
				int d = (ram[address]/10)%10;
				int n = ram[address]%10;
				
				switch (cmd) {
				case 2:
					reg[d] = n; 
					break;
					
				case 3:
					reg[d] = (reg[d] + n) % 1000; 
					break;
					
				case 4:
					reg[d] = (reg[d] * n) % 1000; 
					break;
					
				case 5:
					reg[d] = reg[n]; 
					break;
					
				case 6:
					reg[d] = (reg[d] + reg[n]) % 1000; 
					break;
					
				case 7:
					reg[d] = (reg[d] * reg[n]) % 1000; 
					break;
					
				case 8:
					reg[d] = ram[reg[n]]; 
					break;
					
				case 9:
					ram[reg[n]] = reg[d]; 
					break;
					
				case 0:
					if (reg[n] != 0)
						address = reg[d]-1;
					 break;
					 
				default:
					halt = true;
				}
			}
			
			System.out.println(ex);
			
			if (tc != 0)
				System.out.println();
		}
	}

}
