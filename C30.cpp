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

bool cmp(const vector<lld> &v1,const vector<lld> &v2){
  return v1[2]<v2[2];
}

lld n,x,y,t;
vector<vector<lld> >v;
lld p,ans[10000];


int main(){
  cin>>n;
  vector<lld> temp;
  for(int i=0;i<n;i++){
    cin>>x>>y>>t>>p;
    temp.clear();
    temp.pb(x);
    temp.pb(y);
    temp.pb(t);
    temp.pb(p);
    v.pb(temp);
  }
  sort(v.begin(),v.end(),cmp);
  // cout<<v<<endl;
  // cout<<"asdg"<<endl;
  for(int i=0;i<n;i++){
    // cout<<v[i]<<endl;
    ans[i] = v[i][3];
  }
  lld maxans = -1;
  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      // tr(i,abs(v[j][0] - v[i][0])+abs(v[j][1] - v[i][1]),v[i][2]- v[j][2],ans[j],ans[j]+v[i][3]);
      if(abs(v[j][0] - v[i][0])*abs(v[j][0] - v[i][0])+abs(v[j][1] - v[i][1])*abs(v[j][1] - v[i][1])<=(v[i][2]- v[j][2])*(v[i][2]- v[j][2])){
        ans[i] = max(ans[i],ans[j]+v[i][3]);
      }
    }
    // tr(i,ans[i]);
    maxans = max(maxans,ans[i]);
  }
  printf("%0.9Lf\n",maxans);
}
