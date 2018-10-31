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

int a,n,m,l,r;
vector<pair<int,int> > inp;
vector<pair<int,int> >umb;

bool cmp(pair<int,int> l,pair<int,int> r){
  return l.se<r.se;
}

int main(){
  cin>>a>>n>>m;
  for(int i=0;i<n;i++){
    cin>>l>>r;
    inp.pb(mp(l,r));
  }
  for(int i=0;i<m;i++){
    cin>>l>>r;
    umb.pb(mp(l,r));
  }
  sort(inp.begin(),inp.end());
  sort(umb.begin(),umb.end(),cmp);
  int lp = 0;
  vector<pair<int,int> > v;
  int min_cost;
  int l,r;
  int tot_cost =0;
  pair<int,int> sel;
  cout<<umb<<endl;
  for(int i=0;i<n;i++){
    while(lp<umb.size() and umb[lp].se<=inp[i].fi){
      v.pb(umb[lp]);
      lp++;
    }
    tr(lp);
    min_cost =  -1;
    l = inp[i].fi;
    r = inp[i].se;
    tr(l,r);
    for(int j=0;j<v.size();j++){
      if(min_cost==-1 || min_cost>((r - v[i].fi+1)*v[i].se)){
        min_cost = ((r - v[i].fi+1)*v[i].se);
        sel = v[i];
      }
    }
    tr(min_cost,sel);
    tot_cost+=min_cost;
    v.clear();
    v.pb(mp(r,sel.se));
  }
  cout<<tot_cost<<endl;
  return 0;
}
