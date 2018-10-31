#include <iostream>
#include <vector>
using namespace std ;
int main() {
   int N, K, ti ;
   vector<int> v ;
   cin >> N >> K ;
   for (int i=0; i<N; i++) {
      cin >> ti ;
      v.push_back(ti) ;
   }
   for (int i=0; i<N; i++) {
      int bestproblem = i ;
      for (int j=i+1; j<i+K && j<N; j++)
         if (v[j] < v[bestproblem])
            bestproblem = j ;
      swap(v[i], v[bestproblem]) ;
   }
   long long r = 0, t=0 ;
   for (auto tim : v) {
      t += tim ;
      r += t ;
   }
   cout << r << endl ;
}
