import java.text.DecimalFormat;
import java.util.*;

public class TournamentWins {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int k = s.nextInt(), r = s.nextInt();
        double ans = 0.0;
        for (int i = 1; i <= k; i++) {
            double cur = 1.0;
            for (int j = 1; j < (1 << i); j++) {
                cur *= (1 << k) - j - r + 1;
                cur /= (1 << k) - j;
            }
            ans += cur;
        }
        DecimalFormat fmt = new DecimalFormat("0.00000");
        System.out.println(fmt.format(ans));
    }
}
