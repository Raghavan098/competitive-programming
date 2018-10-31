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
#define inf 1000000000000000001

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
ll arr[200000];
ll cnt[1000010];
ll done[1000010];
ll solve(){
  ll n;
  cin>>n;
  ll mx_ele = 0;
  for(ll i=0;i<n;i++){
    cin>>arr[i];
    cnt[arr[i]]++;
    mx_ele = max(mx_ele,arr[i]);
  }
  ll final_ans = 0;
  for(ll i=1;i<=mx_ele;i++){
    if(cnt[i]>0){
      for(ll j=i;j<=mx_ele;j+=i){
        if(cnt[j]>0 and done[j]==0){
          final_ans+=(cnt[j])*i;
          done[j] = 1;
        }
      }
    }
  }
  cout<<final_ans<<endl;
  for(int i=0;i<n;i++){
    done[i] = 0;
    done[arr[i]]= 0;
    cnt[arr[i]] =0;
  }
  return 0;
}

int main(){ _
  ll t;
  cin>>t;
  while(t--){
    solve();
  }
}
