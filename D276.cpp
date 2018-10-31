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

string get_bin(ll n){
  string ans = "";
  while(n){
    if(n%2==1){
      ans+="1";
    }
    else{
      ans+="0";
    }
    n/=2;
  }
  reverse(ans.begin(),ans.end());
  return ans;
}

ll l,r;
string s1,s2;

int main(){
  cin>>l>>r;
  s1 = get_bin(l);
  s2 = get_bin(r);
  // tr(s1,s2);
  int n = s1.size();
  int m = s2.size();
  for(int i=0;i<m-n;i++){
    s1 = "0"+s1;
  }
  // tr(s1,s2);
  int pos = -1;
  for(int i=0;i<s1.size();i++){
    if(s1[i]!=s2[i]){
      pos = i;
      break;
    }
  }
  // tr(pos);
  if(pos==-1){
    cout<<0<<endl;
    return 0;
  }
  int ones = s1.size() - pos;
  // tr(ones);
  cout<<(ll)pow(2,ones)-1<<endl;
  return 0;
}
