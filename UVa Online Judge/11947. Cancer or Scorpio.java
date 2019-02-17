import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;


class CancerOrScorpio {

	private static String getZodiac(Calendar cal) {
		int m = cal.get(Calendar.MONTH);
        int d = cal.get(Calendar.DAY_OF_MONTH);
        
        if ((m == Calendar.DECEMBER && d >= 23 && d <= 31) || (m ==  Calendar.JANUARY && d >= 1 && d <= 20))
        	return "capricorn";
        else if ((m == Calendar.JANUARY && d >= 21 && d <= 31) || (m == Calendar.FEBRUARY && d >= 1 && d <= 19))
            return "aquarius";
        else if ((m == Calendar.FEBRUARY && d >= 20 && d <= 29) || (m == Calendar.MARCH && d >= 1 && d <= 20))
            return "pisces";
        else if ((m == Calendar.MARCH && d >= 21 && d <= 31) || (m == Calendar.APRIL && d >= 1 && d <= 20))
            return "aries";
        else if ((m == Calendar.APRIL && d >= 21 && d <= 30) || (m == Calendar.MAY && d >= 1 && d <= 21))
            return "taurus";
        else if ((m == Calendar.MAY && d >= 22 && d <= 31) || (m == Calendar.JUNE && d >= 1 && d <= 21))
            return "gemini";
        else if ((m == Calendar.JUNE && d >= 22 && d <= 30) || (m == Calendar.JULY && d >= 1 && d <= 22))
            return "cancer";
        else if ((m == Calendar.JULY && d >= 23 && d <= 31) || (m == Calendar.AUGUST && d >= 1 && d <= 21))
            return "leo";
        else if ((m == Calendar.AUGUST && d >= 22 && d <= 31) || (m == Calendar.SEPTEMBER && d >= 1 && d <= 23))
            return "virgo";
        else if ((m == Calendar.SEPTEMBER && d >= 24 && d <= 30) || (m == Calendar.OCTOBER && d >= 1 && d <= 23))
            return "libra";
        else if ((m == Calendar.OCTOBER && d >= 24 && d <= 31) || (m == Calendar.NOVEMBER && d >= 1 && d <= 22))
            return "scorpio";
        else if ((m == Calendar.NOVEMBER && d >= 23 && d <= 30) || (m == Calendar.DECEMBER && d >= 1 && d <= 22))
            return "sagittarius";
        else
            return "invalid date";
	}
	
	public static void main(String[] args) throws IOException, ParseException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(in.readLine().trim());
		DateFormat parseFormat = new SimpleDateFormat("MMddyyyy");
		DateFormat printFormat = new SimpleDateFormat("MM/dd/yyyy");
		
		Calendar cal = Calendar.getInstance();
		
		for (int n = 1; n <= N; n++) {
			cal.setTime(parseFormat.parse(in.readLine().trim()));
			cal.add(Calendar.DATE, 280);
			
			System.out.println(n + " " + printFormat.format(cal.getTime()) + " " + getZodiac(cal));
		}
	}

}
