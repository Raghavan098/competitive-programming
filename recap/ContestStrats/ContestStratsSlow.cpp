#include <iostream>
#include <vector>
using namespace std ;
const int MAXN = 512 ;
double prob[2][2][MAXN][MAXN] ;
int main() {
   int N, K, ti ;
   cin >> N >> K ;
   vector<double> sums ;
   for (int m=0; m<N; m++) {
      prob[0][0][0][0] = 1.0 ;
      double sum = 0 ;
      double w = N+K ;
      for (int r=0; r<=N+K; r++, w--) {
         int r0 = r & 1 ;
         int r1 = 1 - r0 ;
         for (int a=0; a<=m && a<=r; a++) // count < m solved
            for (int b=0; a+b<=m && a+b<=r; b++) // count < m still in hand
               for (int c=0; c<2 && a+b+c<=r; c++) { // count == m still in hand
                  double f = prob[r0][c][a][b] ;
                  if (f == 0.0)
                     continue ;
                  prob[r0][c][a][b] = 0.0 ;
                  if (r >= K && c && b==0) { // solve m here
                     sum += w * f ;
                  } else { // did not solve; forward propogate
                     int na = a ;
                     int nb = b ;
                     if (r >= K && b) { // solve one
                        nb-- ;
                        na++ ;
                     }
                     if (r >= N) {
                        prob[r1][c][na][nb] = f ;
                     } else {
                        double eq = (1-c) / (double)(N - r) ;
                        double lt = (m-a-b) / (double)(N - r) ;
                        double gt = (N-r-(1-c)-(m-a-b)) / (double)(N-r) ;
                        prob[r1][1][na][nb] += eq * f ;
                        prob[r1][c][na][nb+1] += lt * f ;
                        prob[r1][c][na][nb] += gt * f ;
                     }
                  }
               }
      }
      sums.push_back(sum) ;
   }
   vector<int> v(N) ;
   for (int i=0; i<N; i++)
      cin >> v[i] ;
   sort(v.begin(), v.end()) ;
   double osum = 0 ;
   for (int i=0; i<N; i++)
      osum += v[i] * sums[i] ;
   cout << osum << endl ;
}
