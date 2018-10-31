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

vector<string> v;
vector<string> ans;

string s;
int n,m;

int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>s;
    v.pb(s);
  }
  for(int i=0;i<m;i++){
    vector<string> temp;
    string s1;
    for(int j=0;j<n;j++){
      if(ans.size()!=0){
        s1 = ans[j]+v[j][i];
        temp.pb(s1);
      }
      else{
        s1 = v[j][i];
        temp.pb(s1);
      }
    }
    int done =0;
    for(int j=0;j<n-1;j++){
      if(temp[j]>temp[j+1]){
        done=1;
        break;
      }
    }
    if(done==0){
      ans.clear();
      for(int j=0;j<n;j++){
        ans.pb(temp[j]);
      }
    }
  }
  if(ans.size()>0){
    cout<<m - ans[0].size()<<endl;
  }
  else{
    cout<<m<<endl;
  }
  return 0;
}
