#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
const long long MOD = 1000000007 ;
const int MAXN = 320 ;
long long prob[MAXN][2][MAXN][MAXN] ;
int N, K ;
long long recur(int lessleft, int eqleft, int greatleft, int lessinhand) {
   if (lessleft < 0 || greatleft < 0 || eqleft < 0)
      return 0 ;
   long long r = prob[lessleft][eqleft][greatleft][lessinhand] ;
   if (r == -1) {
      int numleft = lessleft + greatleft + eqleft ;
      int nlessinhand = lessinhand ;
      if (numleft == 0)
         r = K - lessinhand ;
      else if (numleft <= N-K) {
         if (lessinhand)
            nlessinhand-- ;
         else if (eqleft == 0) {
            r = (numleft + K) ;
            for (int i=0; i<numleft; i++)
               r = (r * (i + 1)) % MOD ;
         }
      }
      if (r == -1)
         r = (lessleft * recur(lessleft-1, eqleft, greatleft, nlessinhand+1) +
              greatleft * recur(lessleft, eqleft, greatleft-1, nlessinhand) +
              eqleft * recur(lessleft, eqleft-1, greatleft, nlessinhand)) % MOD ;
      prob[lessleft][eqleft][greatleft][lessinhand] = r ;
   }
   return r ;
}
int main() {
   cin >> N >> K ;
   for (int i=0; i<=N; i++)
      for (int j=0; i+j<=N; j++)
         for (int k=0; i+j+k<=N; k++)
            prob[i][0][j][k] = prob[i][1][j][k] = -1 ;
   vector<int> v(N) ;
   for (int i=0; i<N; i++)
      cin >> v[i] ;
   sort(v.begin(), v.end()) ;
   long long osum = 0 ;
   for (int i=0; i<N; i++)
      osum = (osum + v[i] * recur(i, 1, N-i-1, 0)) % MOD ;
   cout << osum << endl ;
}
