import java.util.* ;
public class Shopping {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in) ;
      int n = sc.nextInt() ;
      int q = sc.nextInt() ;
      long ar[] = new long[n] ;
      for (int i=0; i<n; i++)
         ar[i] = sc.nextLong() ;
      final int chunk = 512 ;
      int nchunks = (n + chunk - 1) / chunk ;
      long mar[] = new long[nchunks] ;
      for (int i=0; i<nchunks; i++) {
         mar[i] = ar[i*chunk] ;
         for (int j=i*chunk+1; j<n && j<(i+1)*chunk; j++)
            mar[i] = Math.min(mar[i], ar[j]) ;
      }
      for (int i=0; i<q; i++) {
         long v = sc.nextLong() ;
         int a = sc.nextInt()-1 ;
         int b = sc.nextInt() ;
         while (v > 0 && a < b) {
            while (a < b && (a & (chunk-1)) == 0 && v < mar[a / chunk])
               a += chunk ;
            if (a < b && ar[a] <= v)
               v = v % ar[a] ;
            a++ ;
         }
         System.out.println(v) ;
      }
   }
}
