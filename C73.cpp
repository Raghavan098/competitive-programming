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
string s;
int k;
int n;
int inp[30][30];
int dp[200][200][200];

int f(int prev, int curr, int k){
  // tr(prev,curr,k);
  if(curr==s.size()){
    return 0;
  }
  if(prev==-1){
    int r = INT_MIN;
    for(int i=0;i<26;i++){
      for(int j=0;j<26;j++){
        int cost = i!=(s[curr] - 'a');
        cost += j!=(s[curr+1] - 'a');
        if((k - cost) >= 0){
          r = max(r,f(j,2,k-cost) + inp[i][j]);
        }
      }
    }
    return r;
  }
  int x = dp[prev][curr][k];
  if(x!=-1){
    return x;
  }
  x = INT_MIN;
  for(int i=0;i<26;i++){
    int cost = i!=(s[curr] - 'a');
    if((k - cost)>=0){
      x = max(x,f(i,curr+1,k-cost) + inp[prev][i]);
    }
  }
  dp[prev][curr][k] = x;
  return x;
}


int main(){ _
  cin>>s;
  cin>>k;
  cin>>n;
  for(int i=0;i<n;i++){
    char a,b;
    int c;
    cin>>a>>b>>c;
    inp[a-'a'][b-'a'] = c;
  }
  MEMS(dp,-1);
  cout<<f(-1,0,k)<<endl;
}
