// g++ -std=c++14
#include<bits/stdc++.h>
typedef long long int lli;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
vector<vector<pair<lli,lli> > >gr;
vector<lli>tim;
lli n,k,m;
lli INF = 10000000000;
int main(){
  _
  cin >> n >> k >> m;
  gr.resize(n+1);
  tim.resize(n+1,INF);
  for(lli i=0;i<m;i++){
    lli u,v,t;
    cin >> u >> v >> t;
    if(u!=v){
      gr[u].pb(mp(v,t));
      gr[v].pb(mp(u,t));
    }
  }
  if(n==1){
    cout << "0\n";
    return 0;
  }
  priority_queue< pair<lli,lli>, vector <pair<lli,lli> > , greater<pair<lli,lli> > > pq;
  tim[1] = 0;
  pq.push(mp(tim[1],1));
  lli ans = INF;
  while(!pq.empty()){
    lli u = pq.top().se;
    pq.pop();
    for(lli i=0;i<gr[u].size();i++){
      lli v = gr[u][i].fi;
      lli temp = tim[u]+gr[u][i].se;
      if(v==n){
        ans = min(ans,temp);
      }
      if(temp%k==0 and (temp/k)%2==1){
        temp+=k;
      }
      if(tim[v]>temp){
        tim[v] = temp;
        pq.push(mp(tim[v],v));
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
