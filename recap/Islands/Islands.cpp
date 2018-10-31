#include <iostream>
#include <vector>
using namespace std ;
int off, h, w, r=0 ;
vector<char> b ;
int f(int i, int j) {
   return off * (i + 1) + (j + 1) ;
}
void chase(int at) {
   if (b[at] == 'W' || b[at] == 0)
      return ;
   b[at] = 0 ;
   for (int i : vector<int>{-1, 1, -off, off})
      chase(at+i) ;
}
int main() {
   cin >> h >> w ;
   b = vector<char>((h+2)*(w+2)) ;
   off = w + 1 ;
   for (int i=0; i<h; i++)
      for (int j=0; j<w; j++)
         cin >> b[f(i,j)] ;
   for (int i=0; i<h; i++)
      for (int j=0; j<w; j++)
         if (b[f(i,j)] == 'L') {
            r++ ;
            chase(f(i,j)) ;
         }
   cout << r << endl ;
}
