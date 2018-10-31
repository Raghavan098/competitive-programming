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

const unsigned PRIME_BASE = 125959;
const unsigned PRIME_MOD = 1000000007;
const unsigned PRIME_BASE2 = 99023;
const unsigned PRIME_MOD2 = 795533;
string s,c;
ll k;
vector<pair<ll,ll> > hash_values;

int main(){
  cin>>s;
  cin>>c;
  cin>>k;
  set<char> bad;
  for(ll i=0;i<26;i++){
    if(c[i]=='0'){
      bad.insert(i+'a');
    }
  }
  string temp;
  ll cnt = 0;
  for(ll i=0;i<s.size();i++){
    temp = "";
    cnt = 0;
    ll ret = 0;
    ll ret2 = 0;
    for(ll j=i;j<s.size();j++){
      temp+=s[j];
      if(bad.find(s[j])!=bad.end()){
        cnt++;
      }
      if(cnt>k){
        break;
      }
      else{
        ret = ret*PRIME_BASE + s[j];
        ret%=PRIME_MOD;
        ret2 = ret2*PRIME_BASE2 + s[j];
        ret%=PRIME_MOD2;
        hash_values.pb(mp(ret,ret2));
        // tr(temp,ret);
      }
    }
  }
  sort(hash_values.begin(),hash_values.end());
  ll final_ans = 0;
  // cout<<hash_values<<endl;
  for(ll i=0;i<hash_values.size();i++){
    if(i==0 || hash_values[i]!=hash_values[i-1]){
      final_ans++;
    }
  }
  cout<<final_ans<<endl;
}
