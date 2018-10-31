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

string s;
int n;

typedef pair<int,pair<int,int> > pii;

int t[5000000],o[5000000],c[5000000];

void build(int id = 1,int l = 0,int r = n){
  // tr(l,r);
  if(r-l<2){
    if(s[l]=='('){
      o[id] = 1;
    }
    else{
      c[id] = 1;
    }
    return;
  }
  int mid = (l+r)/2;
  build(2*id, l, mid);
  build(2*id + 1, mid, r);
  int tmp = min(o[2*id],c[2*id+1]);
  t[id] = t[2*id]+t[2*id+1] + 2*tmp;
  o[id] = o[2*id] + o[2*id+1] - tmp;
  c[id] = c[2*id] + c[2*id+1] - tmp;
  // tr(id,t[id],o[id],c[id]);
}

pii segment(int x,int y,int id = 1,int l = 0,int r = n){
  // tr(x,y,id,l,r);
  if(l>=y or x>=r){
    return mp(0,mp(0,0));
  }
  if(x<=l && y>=r){
    return mp(t[id],mp(o[id],c[id]));
  }
  int mid = (l+r)/2;
  pii a = segment(x,y,2*id,l,mid);
  pii b = segment(x,y,2*id+1,mid,r);
  // tr(a,b,id);
  int tot,open,close,temp;
  temp = min(a.se.fi,b.se.se);
  tot = a.fi + b.fi + 2*temp;
  open = a.se.fi+b.se.fi - temp;
  close = a.se.se + b.se.se - temp;
  return mp(tot,mp(open,close));
}

int main(){
  cin>>s;
  n = s.size();
  build();
  int m,l,r;
  cin>>m;
  while(m--){
    cin>>l>>r;
    cout<<segment(l-1,r).fi<<endl;
  }
}
