import java.math.BigInteger;
import java.util.Scanner;

public class TheGhostOfProgrammers {

    static int[] div = {2, 5, 7, 11, 15, 20, 28, 36};
    static String[] ghosts = {
        "Tanveer Ahsan",
        "Shahriar Manzoor",
        "Adrian Kugel",
        "Anton Maydell",
        "Derek Kisman",
        "Rezaul Alam Chowdhury",
        "Jimmy Mardell",
        "Monirul Hasan",
        "K. M. Iftekhar"
    };

    private static boolean isLeapYear(String yearString) {
        BigInteger year = new BigInteger(yearString);

        if (year.mod(BigInteger.valueOf(4)).equals(BigInteger.ZERO) && 
            !year.mod(BigInteger.valueOf(100)).equals(BigInteger.ZERO)) {
            return true;
        }
        else if (year.mod(BigInteger.valueOf(400)).equals(BigInteger.ZERO)) {
            return true;
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String num;
        boolean first = true;

        while (!(num = in.nextLine()).equals("0")) {
            if (!first)
                System.out.println();
            else
                first = false;

            System.out.println(num);
            BigInteger year = new BigInteger(num).subtract(BigInteger.valueOf(2148));
            int ghostCount = 0;

            if (year.compareTo(BigInteger.ZERO) != -1) {
                for (int i = 0; i < 8; i++) {
                    if (year.mod(BigInteger.valueOf(div[i])).equals(BigInteger.ZERO)) {
                        System.out.println("Ghost of " + ghosts[i] + "!!!");
                        ghostCount++;
                    }
                }

                if (isLeapYear(num)) {
                    System.out.println("Ghost of " + ghosts[8] + "!!!");
                    ghostCount++;
                }
            }

            if (ghostCount == 0) {
                System.out.println("No ghost will come in this year");
            }
        }

        in.close();
    }
}