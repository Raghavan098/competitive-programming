#include <iostream>
#include <vector>
#include <set>
using namespace std ;
void recur(long long el, long long ar, int at,
           const vector<long long>&p, set<long long> &sides) {
   if (at == p.size()) {
      if (el == ar)
         sides.insert(el+ar) ;
   } else {
      recur(el+p[at], ar, at+1, p, sides) ;
      recur(el, ar+p[at], at+1, p, sides) ;
      recur(el, ar, at+1, p, sides) ;
   }
}
int main() {
   int B, P ;
   cin >> B >> P ;
   vector<long long> b(B), p(P) ;
   for (auto i=0; i<b.size(); i++)
      cin >> b[i] ;
   for (auto i=0; i<p.size(); i++)
      cin >> p[i] ;
   set<long long> sides, tot ;
   recur(0, 0, 0, p, sides) ;
   for (auto bar:b)
      for (auto plates:sides)
         tot.insert(bar+plates) ;
   for (auto w:tot)
      cout << w << endl ;
}
