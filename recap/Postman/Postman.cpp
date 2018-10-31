#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
long long solve(vector<pair<int, int>> &a, long long k) {
   sort(a.begin(), a.end()) ;
   int at = a.size() - 1 ;
   long long r = 0 ;
   while (at >= 0) {
      long long ntrips = (a[at].second + k - 1) / k ;
      r += a[at].first * 2 * ntrips ;
      long long cap = ntrips * k ;
      while (cap > 0 && at >= 0) {
         if (a[at].second <= cap) {
            cap -= a[at].second ;
            at-- ;
         } else {
            a[at].second -= cap ;
            break ;
         }
      }
   }
   return r ;
}
int main() {
   int n, k ;
   cin >> n >> k ;
   vector<pair<int, int>> c1, c2 ;
   for (int i=0; i<n; i++) {
      int x, t ;
      cin >> x >> t ;
      (x < 0 ? c1 : c2).push_back(make_pair(abs(x), t)) ;
   }
   cout << (solve(c1, k) + solve(c2, k)) << endl ;
}
