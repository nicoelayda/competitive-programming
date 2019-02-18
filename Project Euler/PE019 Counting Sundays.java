import java.util.Calendar;

public class CountingSundays {
    
    public static void main(String[] args) {
        int sundays = 0;
        Calendar cal = Calendar.getInstance();
        
        for (int y = 1901; y <= 2000; y++) {
            for (int m = Calendar.JANUARY; m <= Calendar.DECEMBER; m++) {
                cal.set(y, m, 1);
                if (cal.get(Calendar.DAY_OF_WEEK) == Calendar.SUNDAY)
                    sundays++;
            }
        }

        System.out.println(sundays);
    }
}