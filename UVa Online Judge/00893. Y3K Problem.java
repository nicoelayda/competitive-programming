import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;

public class Y3KProblem {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        DateFormat formatter = new SimpleDateFormat("d M yyyy");

        while (in.hasNext()) {
            int days = in.nextInt();

            int d = in.nextInt();
            int m = in.nextInt();
            int y = in.nextInt();    

            if (days == 0 && d == 0 && m == 0 && y == 0)
                break;

            Calendar cal = new GregorianCalendar(y, m-1, d);
            cal.add(Calendar.DATE, days);

            System.out.println(formatter.format(cal.getTime()));
        }

        in.close();   
    }
}