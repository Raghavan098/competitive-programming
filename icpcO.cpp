// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
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

void solve(){
  int n;
  vector<pair<ld,ld> > v;
  ld temp1,temp2;
  int ans[500] = {0};
  cin>>n;
  int cur_ans,cur_max;
  for(int i=0;i<n;i++){
    cin>>temp1>>temp2;
    v.pb(mp(temp1,temp2));
    cur_max =-1;
    for(int j = i-1;j>=0;j--){
      if(v[j].fi<v[i].fi and v[j].se>v[i].se and ans[j]>cur_max){
        cur_max = ans[j];
      }
    }
    if(cur_max==-1){
      ans[i] = 1;
    }
    else{
      ans[i] = cur_max+1;
    }
  }
  int final_ans = -1;
  for(int i=0;i<n;i++){
    if(ans[i]>final_ans){
      final_ans = ans[i];
    }
  }
  cout<<final_ans<<endl;
  return;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
