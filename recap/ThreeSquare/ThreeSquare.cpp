#include <iostream>
#include <vector>
#include <math.h>
using namespace std ;
int main(int argc, char *argv[]) {
   vector<int> v(6) ;
   for (int i=0; i<6; i++)
      cin >> v[i] ;
   int a = v[0]*v[1] + v[2]*v[3] + v[4]*v[5] ;
   int s = (int)sqrt(a) ;
   int success = 0 ;
   if (s * s == a) {
      int s2 = -1 ;
      for (int i=0; i<6; i += 2)
         if (v[i] == s || v[i+1] == s) {
            swap(v[4], v[i]) ;
            swap(v[5], v[i+1]) ;
            s2 = 2 * s - v[4] - v[5] ;
         }
      if (s2 > 0) {
         if (((v[0] == s || v[1] == s) && (v[2] == s || v[3] == s)) ||
             ((v[0] == s2 || v[1] == s2) && (v[2] == s2 || v[3] == s2)))
            success++ ;
      }
   }
   cout << (success ? "YES" : "NO") << endl ;
}
