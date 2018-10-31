#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;
vector<pair<long long, long long>> intvl ;
long long recur(long long at, long long tot, long long to) {
   if (at == intvl.size())
      return tot ;
   if (intvl[at].second < to)
      return recur(at+1, tot, to) ;
   return max(recur(at+1, tot, to),
          recur(at+1, tot+intvl[at].first-intvl[at].second, intvl[at].first)) ;
}
int main() {
   int N ;
   cin >> N ;
   intvl = vector<pair<long long, long long>>(N) ;
   for (int i=0; i<N; i++)
      cin >> intvl[i].second >> intvl[i].first ;
   sort(intvl.begin(), intvl.end()) ;
   cout << recur(0, 0, 0) << endl ;
}
