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
int x[200000],y[200000],z[200000];


int main(){
  cin>>s;
  for(int i=1;i<=s.size();i++){
    x[i] = x[i-1] + (s[i-1]=='x');
    y[i] = y[i-1] + (s[i-1]=='y');
    z[i] = z[i-1] + (s[i-1]=='z');
  }
  // for(int i=0;i<=s.size();i++){
  //   tr(x[i],y[i],z[i],i);
  // }
  int m;
  cin>>m;
  while(m--){
    int l,r;
    cin>>l>>r;
    if(r - l +1<3){
      cout<<"YES"<<endl;
      continue;
    }
    int a,b,c;
    a = x[r] - x[l-1];
    b = y[r] - y[l-1];
    c = z[r] - z[l-1];
    int tot = a + b + c;
    // tr(tot,a,b,c);
    tot/=3;
    // tr(tot);
    int rem = (a + b + c)%3;
    // tr(rem);
    if(a<tot or b<tot or c<tot){
      cout<<"NO\n";
    }
    else if(rem==2){
      if((a - tot)==2 or (b - tot)==2 or (c-tot)==2){
        cout<<"NO\n";
      }
      else{
        cout<<"YES\n";
      }
    }
    else{
      cout<<"YES\n";
    }
  }
  return 0;
}
