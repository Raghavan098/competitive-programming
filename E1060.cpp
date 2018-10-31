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

const int N = 2e5 + 100;


int n;
vector<vector<int> > g(N);
int subtree[N], ori_score[N], dp1[N], dp2[N], parent[N];

void dfs1(int v, int p){
    subtree[v] = 1;
    for(auto u: g[v]){
        if(u != p){
            dfs1(u, v);
            subtree[v] += subtree[u];
            ori_score[v] += (ori_score[u] + subtree[u]);
            parent[u] = v;
        }
    }
}

void dfs2(int v, int p){
    for(auto u: g[v]){
        if(u != p){
            dp1[v]++;
            for(auto w: g[u]){
                if(w != v){
                    dp1[v] += (ori_score[w] + subtree[w]);
                }
            }
        }
    }
    if(p != 0){
        dp2[v] = (dp1[p] - )
    }
    for(auto u: g[v]){
        if(u != p){
            dfs2(u, v);
        }
    }
}

int32_t main(){ _
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += (dp1[i] + dp2[i]);
    }
    for(int i = 1; i <= n; i++){
        tr(i, parent[i], subtree[i], ori_score[i], dp1[i], dp2[i]);
    }
    cout << ans << endl;
}
