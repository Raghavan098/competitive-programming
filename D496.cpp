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

int n;
int arr[100100];
int a[100100];
int b[100100];
int t1,t2;
int ap,bp,jump,cur_idx;
vector<pair<int,int> >ans;
map<int,int> am,bm;
pair<int,bool> find(int cur_idx,int jump){
  int at = a[cur_idx] + jump;
  int bt = b[cur_idx] + jump;
  int ind = 9999999;
  int aa = 9999999;
  int bb = 9999999;
  if(am.find(at)!=am.end()){
    aa = am[at];
  }
  if(bm.find(bt)!=bm.end()){
    bb = bm[bt];
  }
  // tr(aa,bb,jump,ap,bp);
  if(aa<bb){
    ap++;
    if(aa==n and ap>bp){
      ans.pb(mp(ap,jump));
    }
    return mp(aa,true);
  }
  else if(bb<aa){
    bp++;
    if(bb==n and bp>ap){
      ans.pb(mp(bp,jump));
    }
    return mp(bb,true);
  }
  else{
    return mp(0,false);
  }
}


int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    if(arr[i]==1){
      t1++;
    }
    else{
      t2++;
    }
  }
  for(int i=1;i<=n;i++){
    a[i] = a[i-1] + (arr[i-1]==1);
    b[i] = b[i-1] + (arr[i-1]==2);
    if(am.find(a[i])==am.end()){
      am[a[i]] = i;
    }
    if(bm.find(b[i])==bm.end()){
      bm[b[i]] = i;
    }
  }
  for(int i=1;i<=max(t1,t2);i++){
    ap = 0;
    bp = 0;
    jump = 1;
    cur_idx = 0;
    while(jump<=n){
      auto ind = find(cur_idx,i);
      // tr(ind,i,ap,bp);
      if(ind.se==false){
        break;
      }
      cur_idx = ind.fi;
    }
  }
  cout<<ans.size()<<endl;
  sort(ans.begin(),ans.end());
  for(auto i: ans){
    cout<<i.fi<<" "<<i.se<<endl;
  }
  return 0;
}
