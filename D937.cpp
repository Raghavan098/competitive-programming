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

const int N = 1e5 + 100;

int n, m, s;
vector<vector<int> > g(N);
int visited[N][2];
int color[N];
int detected;

void dfs(int v, int par, int ans){
    visited[v][par] = ans;
    par ^= 1;
    for(auto u: g[v]){
        if(visited[u][par] == 0){
            dfs(u, par, v);
        }
    }
}

void dfs2(int v){
    color[v] = 1;
    for(auto u: g[v]){
        if(color[u] == 0){
            dfs2(u);
        }
        else if(color[u] == 1){
            detected = 1;
        }
    }
    color[v] = 2;
}

bool has_cycle(){
    dfs2(s);
    if(detected){
        return true;
    }
    return false;
}

int32_t main(){ _
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int cnt;
        cin >> cnt;
        for(int j = 0; j < cnt; j++){
            int temp;
            cin >> temp;
            g[i].pb(temp);
        }
    }
    cin >> s;
    dfs(s, 0, s);
    for(int i = 1; i <= n; i++){
        if((int)g[i].size() == 0 and visited[i][1] != 0){
            vector<int> ans;
            int cur = i;
            int par = 1;
            while(!(cur == s and par == 0)){
                ans.pb(cur);
                cur = visited[cur][par];
                par ^= 1;
            }
            ans.pb(s);
            reverse(all(ans));
            cout << "Win" << endl;
            cout << ans << endl;
            return 0;
        }
    }
    if(has_cycle() == 1){
        cout << "Draw" << endl;
    }
    else{
        cout << "Lose" << endl;
    }
    return 0;
}
