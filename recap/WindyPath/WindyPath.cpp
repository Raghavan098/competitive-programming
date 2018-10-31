#include <iostream>
#include <vector>
#include <string>
using namespace std ;
struct pt { 
   bool operator<(const pt &o) const {
      if (o.x != x)
         return x < o.x ;
      return y < o.y ;
   }
   double x, y ;
} ;
double side(const pt &a, const pt &b, const pt &c) {
   pt ab{b.x-a.x, b.y-a.y}, ac{c.x-a.x, c.y-a.y} ;
   return ab.x*ac.y-ab.y*ac.x ;
}
int main() {
   int N ;
   cin >> N ;
   string s ;
   vector<pt> pts(N) ;
   vector<int> perm(N) ;
   for (int i=0; i<N; i++) {
      cin >> pts[i].x >> pts[i].y ;
      perm[i] = i ;
   }
   cin >> s ;
   int st = 0 ;
   for (int i=0; i<N; i++)
      if (pts[i] < pts[st])
         st = i ;
   swap(pts[0], pts[st]) ;
   swap(perm[0], perm[st]) ;
   for (int i=1; i+1<N; i++) {
      int b = i ;
      for (int j=i+1; j<N; j++)
         if (side(pts[i-1], pts[b], pts[j]) * (s[i-1] == 'L' ? 1 : -1) < 0)
            b = j ;
      swap(pts[i], pts[b]) ;
      swap(perm[i], perm[b]) ;
   }
   for (int i=0; i<N; i++)
      cout << (i == 0 ? "" : " ") << (perm[i]+1) ;
   cout << endl ;
}
