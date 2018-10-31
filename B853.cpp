#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

int n,m,k,d,f,t,c,best;

map<int , pair<set<vector<int> >,set<vector<int> > > > cost;
vector<vector<int> > inp;

int main(){ _

  cin>>n>>m>>k;
  for(int i=0;i<m;i++){
    cin>>d>>f>>t>>c;
    if(f==0 and d>k){
      cost[t].second().insert({c,d});
    }
    else if(t==0 and d==1){
      cost[f].first().insert({c,d});
    }
    inp.push_back({d,f,t,c});
  }
  best = 0;
  for(int i=1;i<=n;i++){
    best+=cost[i].first().begin();
    best+=cost[i].second().begin();
  }
  for(int i=1;i<n-k;i++){

  }
  return 0;
}
