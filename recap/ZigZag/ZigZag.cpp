#include <iostream>
#include <vector>
using namespace std ;
int main() {
   int N, r=1 ;
   cin >> N ;
   vector<int> up(N), down(N), a(N) ;
   for (int i=0; i<N; i++) {
      cin >> a[i] ;
      up[i] = down[i] = 1 ;
      for (int j=0; j<i; j++)
         if (a[j] < a[i])
            up[i] = max(up[i], down[j]+1) ;
         else if (a[j] > a[i])
            down[i] = max(down[i], up[j]+1) ;
   }
   for (auto v : up)
      r = max(r, v) ;
   for (auto v : down)
      r = max(r, v) ;
   cout << r << endl ;
}
