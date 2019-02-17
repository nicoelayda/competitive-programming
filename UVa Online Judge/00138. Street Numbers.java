class StreetNumbers {

	public static void main(String[] args) {
		long left = 1, right = 3;
		
		for (int pairs = 0, house = 2, last = 3; pairs != 10; left += house++, right -= house) {
			if (left < right && house >= last-1) {
				last = house+2;
				right += last;
			}
			else {
				while (left > right)
					right += ++last;
			}
			
			if (left == right) {
				System.out.printf("%10d%10d\n", house, last);
				pairs++;
			}
		}
	}
}
