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

int n,m,k;
char arr[400][400];

bool check(int k,int i,int j){
  return ((i-k>=0) and (j-k>=0) and (i+k<n) and (j+k<m));
}

int main(){
  cin>>n>>m>>k;
  for(int i=0;i<n;i++){
    for(int j = 0;j<m;j++){
      cin>>arr[i][j];
    }
  }
  vector<pair<pair<int,int> ,int > > ans;
  for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){
      if(arr[i][j]=='*'){
        for(int k1 = 1;k1<max(n,m);k1++){
          if(check(k1,i,j)){
            if(arr[i-k1][j]=='*' and arr[i+k1][j]=='*' and arr[i][j-k1]=='*' and arr[i][j+k1]=='*'){
              ans.pb(mp(mp(k1,i),j));
            }
          }
          else{
            break;
          }
        }
      }
    }
  }
  sort(ans.begin(),ans.end());
  // cout<<ans<<endl;

  if(k>ans.size()){
    cout<<-1<<endl;
    return 0;
  }
  int i = ans[k-1].fi.se + 1;
  int j = ans[k-1].se + 1;
  int k1 = ans[k-1].fi.fi;
  cout<<i<<" "<<j<<endl;
  cout<<i-k1<<" "<<j<<endl;
  cout<<i+k1<<" "<<j<<endl;
  cout<<i<<" "<<j-k1<<endl;
  cout<<i<<" "<<j+k1<<endl;
  return 0;
}
