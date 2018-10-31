import java.util.Arrays;
import java.util.Scanner;

public class ContestStrats_lewin {
  public static int mod = 1000000007;
  public static long[] inv;
  public static void main (String[] args) {
    Scanner in = new Scanner(System.in);
    
    int n = in.nextInt(), k = in.nextInt();
    inv = new long[n+10];
    inv[1] = 1;
    for (int i = 2; i < inv.length; i++) inv[i] = (mod - mod/i) * inv[mod % i] % mod;
    int[] t = new int[n];
    for (int i = 0; i < n; i++) t[i] = in.nextInt();
    Arrays.sort(t);
    
    dp = new long[2][k+1][n+1][n+1];
    for (long[][][] x : dp) for (long[][] y : x) for (long[] z : y) Arrays.fill(z, -1);
    long ans = 0;
    for (int i = 0; i < n; i++)
      ans = (ans+(n-getPlace(false, k, i, n-i-1)+k+mod) * t[i]) % mod;
    for (int i = 1; i <= n; i++)
      ans = ans * i % mod;
    System.out.println(ans);
    System.exit(0);
  }
  
  public static long[][][][] dp;
  public static long getPlace(boolean has, int inless, int outless, int outmore) {
    if (dp[has?1:0][inless][outless][outmore] != -1) return dp[has?1:0][inless][outless][outmore];
    if (has && inless == 0) return 0;
    int total = outless + outmore + (has?0:1);
    if (total == 0) return inless;
    if (inless>0) inless--;
    return dp[has?1:0][inless+1][outless][outmore] = (1
                   + (!has?getPlace(true, inless, outless, outmore)*inv[total] % mod:0)
                   + (outless>0?getPlace(has, inless+1, outless-1, outmore)*outless%mod*inv[total] % mod:0)
                   + (outmore>0?getPlace(has, inless, outless, outmore-1)*outmore%mod*inv[total] % mod:0)) % mod;
    
  }
}
