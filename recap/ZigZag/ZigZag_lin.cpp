#include <iostream>
using namespace std ;
int main() {
   int n, v, r=1, prevdelta=0, prevval ;
   cin >> n >> prevval ;
   for (int i=1; i<n; i++) {
      cin >> v ;
      if (v != prevval) {
         int delta = v - prevval ;
         if (prevdelta == 0 || delta * prevdelta < 0)
            r++ ;
         prevval = v ;
         prevdelta = delta ;
      }
   }
   cout << r << endl ;
}
