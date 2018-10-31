import java.util.* ;
public class Cameras {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in) ;
      int N = sc.nextInt() ;
      int K = sc.nextInt() ;
      int R = sc.nextInt() ;
      boolean c[] = new boolean[N] ;
      for (int i=0; i<K; i++)
         c[sc.nextInt()-1] = true ;
      int mincam = 2 ;
      int r = 0 ;
      int s = 0 ;
      for (int i=0; i < c.length && i<R; i++)
         if (c[i])
            s++ ;
      int pa = 0 ;
      int pb = R ;
      while (pb <= N) {
         int ca = pb - 1 ;
         while (s < mincam) {
            while (c[ca])
               ca-- ;
            c[ca--] = true ;
            s++ ;
            r++ ;
         }
         if (pb >= N)
            break ;
         if (c[pa++])
            s-- ;
         if (c[pb++])
            s++ ;
      }
      System.out.println(r) ;
   }
}
