// g++ -std=c++14

/*

Today might be the chance to grasp the chance to let your talent bloom.
May be tomorrow, the day after, or next year...
May be even when you are 30. I'm not sure if physique has anything to do with it
but if you think that it will never come, it probably never will.

- Tooru Oikawa.

*/


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
#define all(c) c.begin(),c.end()
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

#define int ll

// const int N = 1e6 + 100;

vector<int> arr;
int n, q, l;
vector<vector<int> > g;
vector<int> dp, curr;
vector<vector<int> > up;

void dfs(int v, int p){
    up[v][0] = p;
    for(int i = 1; i <= l; ++i){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    if(v == 1){
        dp[v] = 1;
        curr[v] = arr[v];
    }
    else if(arr[v] > curr[p]){
        dp[v] = dp[p] + 1;
        curr[v] = arr[v];
    }
    else{
        dp[v] = dp[p];
        curr[v] = curr[p];
    }
    for(auto u: g[v]){
        if(u != p){
            dfs(u, v);
        }
    }
}

void clear_all(){
    g.clear();
    arr.clear();
    up.clear();
    dp.clear();
    curr.clear();
}

void pre_process(){
    l = ceil(log2(n));
    up.resize(n + 1, vector<int>(l + 3));
    dfs(1, 1);
}

int solve(){
    clear_all();
    cin >> n;
    arr.resize(n+1);
    dp.resize(n+1);
    curr.resize(n+1);
    g.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 2; i <= n; i++){
        int temp;
        cin >> temp;
        g[temp].pb(i);
        g[i].pb(temp);
    }
    pre_process();
    int ans = 0;
    cin >> q;
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        int v = a^ans;
        int w = b^ans;
        int u = v;
        for(int i = l; i >= 0; i--){
            if(curr[up[u][i]] > w){
                u = up[u][i];
            }
        }
        if(u == v){
            if(curr[u] > w){
                ans = 1;
                cout << 1 << endl;
            }
            else{
                ans = 0;
                cout << ans << endl;
            }
            continue;
        }
        ans = dp[v] - dp[u] + 1;
        cout << ans << endl;
        // ans = 0;
    }
}

int32_t main(){_
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
