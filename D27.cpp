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

const int N = 110;

int n, m;
int g[N][N][2];
vector<int> lol[2];

int get_after(int v){
    if(v == n){
        return 1;
    }
    return v + 1;
}

int get_before(int v){
    if(v == 1){
        return n;
    }
    return v - 1;
}

void dfs(int u, int p, int d, int st, int i){
    // tr(u);
    if(u == d){
        return;
    }
    lol[st].pb(u);
    int v = get_after(u);
    if(v != p){
        dfs(v, u, d, st, i);
    }
    else{
        v = get_before(u);
        dfs(v, u, d, st, i);
    }
}


int32_t main(){
    cin >> n >> m;
    for(int i = 1; i < n; i++){
        g[i][i + 1][0] = 1;
        g[i + 1][i][0] = 1;
        g[i][i + 1][1] = 1;
        g[i + 1][i][1] = 1;
    }
    g[1][n][1] = 1;
    g[n][1][1] = 1;
    g[1][n][0] = 1;
    g[n][1][0] = 1;
    string ans = "";
    for(int edg = 0; edg < m; edg++){
        int a, b;
        cin >> a >> b;
        int q = get_before(a);
        int w = get_after(a);
        lol[0].clear();
        lol[1].clear();
        dfs(q, a, b, 0, 0);
        dfs(w, a, b, 1, 0);
        int done = 0;
        for(auto i: lol[0]){
            for(auto j: lol[1]){
                if(g[i][j][0] == 1 or g[j][i][0] == 1){
                    done = 1;
                    goto here;
                }
            }
        }
        here:
        if(done == 0){
            g[a][b][0] = 1;
            g[b][a][0] = 1;
            ans += 'i';
            continue;
        }
        if(done == 1){
            lol[0].clear();
            lol[1].clear();
            dfs(q, a, b, 0, 1);
            dfs(w, a, b, 1, 1);
            done = 0;
            for(auto i: lol[0]){
                for(auto j: lol[1]){
                    if(g[i][j][1] == 1 or g[j][i][1] == 1){
                        done = 1;
                        break;
                    }
                }
                if(done == 1){
                    cout << "Impossible\n";
                    return 0;
                }
            }
            g[a][b][1] = 1;
            g[b][a][1] = 1;
            ans += 'o';
        }
    }
    cout << ans << endl;
    return 0;
}
