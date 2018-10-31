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

ll arr[6000],x,y,ans2[6000][6000];
ll n;

int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
    ans2[i][i] = arr[i];
  }
  for(int i=2;i<=n;i++){
    for(int j=1;j<=n-i+1;j++){
      ans2[j][j+i-1]= ans2[j][j+i-2]^ans2[j+1][j+i-1];
    }
  }
  for(int i=2;i<=n;i++){
    for(int j=1;j<=n-i+1;j++){
      ans2[j][j+i-1]= max(ans2[j][j+i-2],max(ans2[j+1][j+i-1],ans2[j][j+i-1]));
    }
  }
  ll q;
  cin>>q;
  for(int i=0;i<q;i++){
    cin>>x>>y;
    cout<<ans2[x][y]<<endl;
  }
}
