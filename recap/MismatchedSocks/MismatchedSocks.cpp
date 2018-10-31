#include <iostream>
#include <vector>
using namespace std ;
int main() {
   long long N, cnts, tot=0, hi=0 ;
   cin >> N ;
   for (int i=0; i<N; i++) {
      cin >> cnts ;
      tot += cnts ;
      hi = max(hi, cnts) ;
   }
   cout << (tot >= 2 * hi ? tot/2 : (tot-hi)) << endl ;
}
