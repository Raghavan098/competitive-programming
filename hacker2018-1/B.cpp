// g++ -std=c++14

#include<bits/stdc++.h>
#include <inttypes.h>
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
// #define ll ll

struct node{
    ll ind;ll mx;
};
const ll N = 2e5 + 4;
const ll M = 1e6 + 2;
ll p[N],c[M];
vector<vector<ll> > grp;
vector<ll> arr;
map<ll,pair<ll,ll> > ind;
node seg[4*N];
ll subs[N];
ll n,m,a,b;
ll mm;

bool cmp(ll x,ll y){
    return subs[x]<subs[y];
}

void clear_all(){
    grp.clear();
    MEMS(p,0);
    MEMS(c,0);
    arr.clear();
    ind.clear();
    MEMS(seg,0);
    MEMS(subs,0);
}
void dfs(ll u,ll pt){
    ll st = arr.size();
    subs[u] = 1;
    arr.pb(p[u]);
    for(auto v: grp[u]){
        if(v!=pt){
            dfs(v,u);
            subs[u] += subs[v];
        }
    }
    ll en = arr.size()-1;
    ind[u] = mp(st,en);
}

void build(ll id = 1,ll l = 0,ll r = n){
    if((r - l)<2){
        seg[id].mx = p[arr[l]];
        seg[id].ind = l;
        return;
    }
    ll mid = (l + r)/2;
    build(2*id,l,mid);
    build(2*id + 1,mid,r);
    if(seg[2*id].mx > seg[2*id + 1].mx){
      seg[id].mx = seg[2*id].mx;
      seg[id].ind = seg[2*id].ind;
    }
    else{
      seg[id].mx = seg[2*id + 1].mx;
      seg[id].ind = seg[2*id + 1].ind;
    }
}

void update(ll p,ll value,ll id = 1,ll l = 0,ll r = n){
    if((r - l)<2){
        seg[id].mx = value;
        return;
    }
    ll mid = (l + r)/2;
    if(p<mid){
        update(p,value,2*id,l,mid);
    }
    else{
        update(p,value,2*id + 1,mid,r);
    }
    node a = seg[2*id];
    node b = seg[2*id + 1];
    node temp;
    if(a.mx > b.mx){
      temp.mx = a.mx;
      temp.ind = a.ind;
    }
    else {
      temp.mx = b.mx;
      temp.ind = b.ind;
    }
    seg[id] = temp;
}

node segment(ll x,ll y,ll id = 1,ll l = 0,ll r = n){
    if(l>=y or x>=r){
      node temp;
      temp.mx = 0;
      temp.ind = -1;
      return temp;
    }
    if(x<=l and y>=r){
        return seg[id];
    }
    ll mid = (l + r)/2;
    node a = segment(x,y,2*id,l,mid);
    node b = segment(x,y,2*id + 1,mid, r);
    node temp;

    if(a.mx > b.mx){
      temp.mx = a.mx;
      temp.ind = a.ind;
    }
    else{
      temp.mx = b.mx;
      temp.ind = b.ind;
    }
    return temp;
}

void find_c(){
    for(ll i=0;i<mm;i++){
        c[i] = (a*i + b)%n;
    }
}

ll solve(){
    cin>>n>>mm>>a>>b;
    clear_all();
    grp.resize(n);
    p[0] = 0;
    for(ll i=1;i<n;i++){
        ll temp;
        cin>>temp;
        grp[temp].pb(i);
        grp[i].pb(temp);
        p[i] = i;
    }
    find_c();
    dfs(0,-1);
    build();
    sort(c,c+mm,cmp);
    ll final_ans = 0;
    for(ll i=0;i<mm;i++){
        auto temp = ind[c[i]];
        ll l = temp.fi;
        ll r = temp.se + 1;
        node ans = segment(l,r);
        final_ans += ans.mx;
        if(ans.ind!=-1){
            update(ans.ind,0);
        }
    }
    cout<<final_ans<<endl;
    return 0;
}

static void main2(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    __
    ll t; cin >> t;

    for (ll i = 1; i <= t; ++i){
        cout << "Case #" << i << ":";
        cout << " ";
        solve();
    }
}

static void run_with_stack_size(void (*func)(), size_t stsize) {
    char *stack, *send;
    stack=(char *)malloc(stsize);
    send=stack+stsize-16;
    send=(char *)((uintptr_t)send/16*16);
    asm volatile(
      "mov %%rsp, (%0)\n"
      "mov %0, %%rsp\n"
      :
      : "r" (send));
    func();
    asm volatile(
      "mov (%0), %%rsp\n"
      :
      : "r" (send));
    free(stack);
}


int main() {
    run_with_stack_size(main2, 64*1024*1024);
}
