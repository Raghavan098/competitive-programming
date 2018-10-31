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

#define auto pair<ll,ll>

struct node{
  ll mx,ind,ts;
};

ll n,n1;
ll arr[(ll)2e6];
ll seg_arr[(ll)2e6];

node seg_tree[(ll)2e6];

multiset<pair<ll,ll> > values[(ll)2e6];
vector<stack<pair<ll,ll> > > stks[(ll)2e6];

void build(ll id = 1,ll l=0,ll r = n){
  if(r - l <2){
    seg_tree[id].mx = seg_arr[l];
    seg_tree[id].ind = l;
    seg_tree[id].ts = 0;
    return;
  }
  ll mid = (l+r)/2;
  build(2*id,l,mid);
  build(2*id + 1,mid,r);
  if(seg_tree[2*id].mx > seg_tree[2*id + 1].mx){
    seg_tree[id].mx = seg_tree[2*id].mx;
    seg_tree[id].ind = seg_tree[2*id].ind;
  }
  else{
    seg_tree[id].mx = seg_tree[2*id + 1].mx;
    seg_tree[id].ind = seg_tree[2*id + 1].ind;
  }
  seg_tree[id].ts = 0;
}

node segment(ll x,ll y,ll id = 1,ll l = 0,ll r = n){
  if(l>=y or x>=r){
    node temp;
    temp.mx = 0;
    temp.ind = 0;
    temp.ts = 0;
    return temp;
  }
  if(x<=l && y>=r){
    return seg_tree[id];
  }
  ll mid = (l + r)/2;
  node a = segment(x,y,2*id,l,mid);
  node b = segment(x,y,2*id + 1,mid, r);
  node temp;

  if(a.mx > b.mx){
    temp.mx = a.mx;
    temp.ind = a.ind;
    temp.ts = a.ts;
  }
  else if(b.mx > a.mx){
    temp.mx = b.mx;
    temp.ind = b.ind;
    temp.ts = b.ts;
  }
  else{
    if(a.ts > b.ts){
      temp.mx = a.mx;
      temp.ind = a.ind;
      temp.ts = a.ts;
    }
    else{
      temp.mx = b.mx;
      temp.ind = b.ind;
      temp.ts = b.ts;
    }
  }
  return temp;
}

void update(ll p,ll value,ll time_stamp,ll id =1,ll l = 0,ll r = n){
  if((r - l)<2){
    seg_tree[id].mx = value;
    seg_tree[id].ts = time_stamp;
    return;
  }
  ll mid = (l + r)/2;
  if(p<mid){
    update(p,value,time_stamp,2*id,l,mid);
  }
  else{
    update(p,value,time_stamp,2*id+1,mid,r);
  }
  node a = seg_tree[2*id];
  node b = seg_tree[2*id + 1];

  node temp;

  if(a.mx > b.mx){
    temp.mx = a.mx;
    temp.ind = a.ind;
    temp.ts = a.ts;
  }
  else if(b.mx > a.mx){
    temp.mx = b.mx;
    temp.ind = b.ind;
    temp.ts = b.ts;
  }
  else{
    if(a.ts > b.ts){
      temp.mx = a.mx;
      temp.ind = a.ind;
      temp.ts = a.ts;
    }
    else{
      temp.mx = b.mx;
      temp.ind = b.ind;
      temp.ts = b.ts;
    }
  }
  seg_tree[id] = temp;
}

int main(){ _
  cin>>n1;
  n = 2*n1;
  for(ll i=0;i<n1;i++){
    cin>>arr[i+1];
  }
  if(n1==1){
    arr[n1] = 0;
  }
  arr[0] = arr[n1];
  for(ll i=1;i<2*n1;i++){
    ll temp = i%n1;
    seg_arr[i] = seg_arr[i-1] + arr[temp];
  }
  build();
  for(ll i=0;i<n;i++){
    values[i].insert(mp(0,0));
    stack<pair<ll,ll> > temp;
    temp.push(mp(0,0));
    stks[i].pb(temp);
  }
  ll m;
  cin>>m;
  ll t = 0;
  while(m--){
    t++;
    ll temp1;
    cin>>temp1;
    if(temp1==1){
      ll x,w;
      cin>>x>>w;
      x--;
      node read = segment(x,x + n1);
      ll y = (read.ind)%n1;
      auto hi = *(values[y].rbegin());
      values[y].erase(values[y].find(hi));
      stks[y][hi.se].push(mp(w,t));
      hi.fi += w;
      values[y].insert(hi);
      update(y,hi.fi + seg_arr[y],t);
      update(y + n1,hi.fi + seg_arr[y + n1],t);
      // tr(segment(y+1,y+n1).mx,y,y+n1);
    }
    else if(temp1==2){
      ll x,w;
      cin>>x>>w;
      x--;
      node read = segment(x,x+1);
      ll ii = stks[x].size();
      stack<pair<ll,ll> > temp;
      temp.push(mp(w,t));
      stks[x].pb(temp);
      values[x].insert(mp(w,ii));
      if(w + seg_arr[x]>read.mx){
        update(x,w+seg_arr[x],t);
        update(x+n1,w+seg_arr[x+n1],t);
      }
    }
    else if(temp1==3){
      ll x;
      cin>>x;
      x--;
      node read = segment(x,x+n1);
      ll y = (read.ind)%n1;
      auto hi = *(values[y].rbegin());
      auto diff = stks[y][hi.se].top();
      stks[y][hi.se].pop();
      if(stks[y][hi.se].empty()){
        stks[y][hi.se].push(mp(0,0));
      }
      values[y].erase(values[y].find(hi));
      values[y].insert(mp(hi.fi - diff.fi,hi.se));
      auto udp = *(values[y].rbegin());
      ll time_this = stks[y][udp.se].top().se;
      update(y,udp.fi + seg_arr[y],time_this);
      update(y+n1,udp.fi + seg_arr[y+n1],time_this);
    }
    else{
      ll x;
      cin>>x;
      x--;
      node read = segment(x,x + n1);
      cout<<read.mx - seg_arr[x]<<endl;
    }
  }
  return 0;
}
