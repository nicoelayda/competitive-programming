import java.util.Arrays;
import java.util.Scanner;

public class P11858_FroshWeek {
	
	static long count = 0;
	
	private static int[] merge(int[] left, int[] right) {
		int[] merged = new int[left.length + right.length];
		int i = 0, li = 0, ri = 0;
		
		while(left.length != li && right.length != ri) {
			if(left[li] < right[ri]) {
				merged[i++] = left[li++];
			}
			else {
				merged[i++] = right[ri++];
				count += left.length - li;
			}
		}
		
		while(left.length != li)
			merged[i++] = left[li++];
        while(right.length != ri)
        	merged[i++] = right[ri++];
		
		return merged;
	}
	public static int[] mergeSort(int[] array) {
		if (array.length <= 1)
		    return array;
		
		int cutoff = array.length / 2;

		int[] left = Arrays.copyOfRange(array, 0, cutoff);
		int[] right = Arrays.copyOfRange(array, cutoff, array.length);
		
		return merge(mergeSort(left), mergeSort(right));
		
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		while (scan.hasNext()) {
			int n = scan.nextInt();
			int[] students = new int[n];
			
			for (int i = 0; i < n; i++)
				students[i] = scan.nextInt();
			
			count = 0;
			
			students = mergeSort(students);
			System.out.println(count);
		}
		
		scan.close();
	}
}
