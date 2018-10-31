#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std ;
int main() {
   long long N, K ;
   cin >> N >> K ;
   vector<pair<long long, long long>> intvl(K) ;
   map<long long, long long> dp ;
   for (int i=0; i<K; i++) {
      cin >> intvl[i].second >> intvl[i].first ;
      intvl[i].first++ ;
   }
   sort(intvl.begin(), intvl.end()) ;
   for (auto gap : intvl) {
      auto it = dp.upper_bound(gap.second) ;
      long long tot = gap.first - gap.second ;
      if (it != dp.begin())
         tot += (--it)->second ;
      if (dp.size() == 0 || tot > dp.rbegin()->second)
         dp[gap.first] = tot ;
   }
   cout << N - dp.rbegin()->second << endl ;
}
