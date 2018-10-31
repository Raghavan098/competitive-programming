#include <iostream>
#include <string>
using namespace std ;
int main() {
   string ec, s ;
   cin >> s ;
   for (char c : s) {
      auto it = lower_bound(ec.begin(), ec.end(), c) ;
      if (it == ec.end())
         ec.push_back(c) ;
      else
         *it = c ;
   }
   cout << (26-ec.size()) << endl ;
}
