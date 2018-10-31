// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

ll n;
ll arr[600][600];
ll del[600];
ll present[600];
ll sp[600][600];
int main(){
  cin>>n;
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){
      cin>>arr[i][j];
      sp[i][j] = arr[i][j];
    }
  }
  for(ll i=1;i<=n;i++){
    cin>>del[i];
  }
  reverse(del+1,del+n+1);
  for(ll i=1;i<=n;i++){
    sp[i][i] = 0;
    // tr(del[i]);
  }
  vector<ll> ans;
  ll sum = 0;
  for(ll d=1;d<=n;d++){
    ll k = del[d];
    for(ll i=1;i<=n;i++){
      if(present[i]){
        sum+=arr[i][k];
        sum+=arr[k][i];
      }
    }
    for(ll i=1;i<=n;i++){
      if(present[i]){
        for(ll j=1;j<=n;j++){
          if(present[j]){
            if(sp[k][i] + sp[i][j]<sp[k][j]){

              sum -= sp[k][j];
              sum += (sp[k][i] + sp[i][j]);
              sp[k][j] = (sp[k][i] + sp[i][j]);

            }
          }
        }
      }
    }
    for(ll i=1;i<=n;i++){
      if(present[i]){
        for(ll j=1;j<=n;j++){
          if(present[j]){
            if(sp[i][j] + sp[j][k]<sp[i][k]){

              sum -= sp[i][k];
              sum += (sp[i][j] + sp[j][k]);
              sp[i][k] = (sp[i][j] + sp[j][k]);

            }
          }
        }
      }
    }
    for(ll i=1;i<=n;i++){
      if(present[i]){
        for(ll j=1;j<=n;j++){
          if(present[j]){
            if(sp[i][k] + sp[k][j]<sp[i][j]){
              // tr(i,j,k,sp[i][j]);

              sum -= sp[i][j];
              sum += (sp[i][k] + sp[k][j]);
              sp[i][j] = sp[i][k] + sp[k][j];

            }
          }
        }
      }
    }
    present[k] = 1;
    ans.pb(sum);
  }
  reverse(ans.begin(),ans.end());
  cout<<ans<<endl;
  return 0;
}
