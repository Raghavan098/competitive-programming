#include <iostream>
#include <vector>
#include <string>
using namespace std ;
int main() {
   int w, h ;
   cin >> h >> w ;
   vector<string> b(h) ;
   for (int i=0; i<h; i++)
      cin >> b[i] ;
   for (int i=0; i<w; i++) {
      int at = h-1 ;
      while (at > 0) {
         if (b[at][i] == '.' && b[at-1][i] == 'o') {
            swap(b[at][i], b[at-1][i]) ;
            if (at < h-1)
               at++ ;
         } else {
            at-- ;
         }
      }
   }
   for (auto s : b)
      cout << s << endl ;
}
