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

const int N = 1000 + 100;

int w[N], b[N], n, m, tot;
vector<vector<int> > g(N);
vector<vector<int> > knap_sack;
int visited[N];
int prev_comp = 0;
vector<int> curr_component;
int comp_weight = 0;
int comp_beauty = 0;

void dfs(int v){
    visited[v] = 1;
    vector<int> node(tot + 1, 0);
    for(int i = 1; i <= tot; i++){
        if(w[v] <= i){
            node[i] = max(b[v] + knap_sack[prev_comp][i - w[v]], knap_sack[prev_comp][i]);
        }
        else{
            node[i] = knap_sack[prev_comp][i];
        }
    }
    comp_weight += w[v];
    comp_beauty += b[v];
    for(int i = 1; i <= tot; i++){
        curr_component[i] = max(curr_component[i], node[i]);
    }
    for(auto u: g[v]){
        if(visited[u] == 0){
            dfs(u);
        }
    }
}

int32_t main(){ _
    cin >> n >> m >> tot;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b), g[b].pb(a);
    }
    curr_component.clear();
    curr_component.resize(tot + 1, 0);
    knap_sack.pb(curr_component);
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            comp_beauty = 0;
            comp_weight = 0;
            curr_component.clear();
            curr_component.resize(tot + 1, 0);
            dfs(i);
            vector<int> node(tot + 1, 0);
            for(int i = 1; i <= tot; i++){
                if(comp_weight <= i){
                    node[i] = max(comp_beauty + knap_sack[prev_comp][i - comp_weight], knap_sack[prev_comp][i]);
                }
                else{
                    node[i] = knap_sack[prev_comp][i];
                }
            }
            for(int i = 1; i <= tot; i++){
                curr_component[i] = max(curr_component[i], node[i]);
            }
            knap_sack.pb(curr_component);
            prev_comp++;
        }
    }
    cout << knap_sack[(int)knap_sack.size() - 1][tot] << endl;
    return 0;
}
