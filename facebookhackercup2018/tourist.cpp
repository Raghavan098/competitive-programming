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

map<string,ll> mp;

bool cmp(string &s1,string s2){
  return mp[s1]<mp[s2];
}

ll solve(ll test){
  ll n,k,v;
  cin>>n>>k>>v;
  queue<string> q;
  vector<string> ans;
  for(ll i=0;i<n;i++){
    string temp;
    cin>>temp;
    mp[temp] = i;
    q.push(temp);
  }
  v = (v-1)*k;
  for(ll i=0;i<v%n;i++){
    string temp = q.front();
    q.pop();
    q.push(temp);
  }
  cout<<"Case #"<<test<<": ";
  for(ll i=0;i<k;i++){
    string temp = q.front();
    q.pop();
    ans.pb(temp);
    q.push(temp);
  }
  sort(ans.begin(),ans.end(),cmp);
  cout<<ans<<endl;
  return 0;
}


int main(){ _
  ll t;
  cin>>t;
  for(ll i=1;i<=t;i++){
    solve(i);
  }
}
