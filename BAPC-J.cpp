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
#define inf 100

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

const int N = 200;

int n, m;
char inp[N][N];
vector<vector<int> > dist, dist2;
vector<vector<int> > visited;

bool valid(int a, int b){
    if(a >= 0 and a < n and b >= 0 and b < m){
        if(inp[a][b] != '*'){
            return true;
        }
    }
    return false;
}

void bfs(pair<int, int> v, pair<int, int> u){
    tr(v, u);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dist[i][j] = inf;
        }
    }
    deque<pair<int, int> > s;
    s.push_front(v);
    s.push_front(u);
    dist[v.fi][v.se] = 0;
    visited[v.fi][v.se] = 1;
    dist[u.fi][u.se] = 0;
    visited[u.fi][u.se] = 1;
    while(!s.empty()){
        auto temp = s.front();
        s.pop_front();
        int a = temp.fi, b = temp.se;
        visited[a][b] = 1;
        if(inp[a][b] == '#'){
            inp[a][b] = '.';
        }
        int curr_dist = dist[a][b];
        if(valid(a + 1, b)){
            int cost = (inp[a + 1][b] == '#') + curr_dist;
            if(cost < dist[a + 1][b]){
                dist[a + 1][b] = cost;
                if(inp[a + 1][b] == '#'){
                    s.push_back(mp(a + 1, b));
                }
                else{
                    s.push_front(mp(a + 1, b));
                }
            }
        }
        if(valid(a - 1, b)){
            int cost = (inp[a - 1][b] == '#') + curr_dist;
            if(cost < dist[a - 1][b]){
                dist[a - 1][b] = cost;
                if(inp[a - 1][b] == '#'){
                    s.push_back(mp(a - 1, b));
                }
                else{
                    s.push_front(mp(a - 1, b));
                }
            }
        }
        if(valid(a, b + 1)){
            int cost = (inp[a][b + 1] == '#') + curr_dist;
            if(cost < dist[a][b + 1]){
                dist[a][b + 1] = cost;
                if(inp[a][b + 1] == '#'){
                    s.push_back(mp(a, b + 1));
                }
                else{
                    s.push_front(mp(a, b + 1));
                }
            }
        }
        if(valid(a, b - 1)){
            int cost = (inp[a][b - 1] == '#') + curr_dist;
            if(cost < dist[a][b - 1]){
                dist[a][b - 1] = cost;
                if(inp[a][b - 1] == '#'){
                    s.push_back(mp(a, b - 1));
                }
                else{
                    s.push_front(mp(a, b - 1));
                }
            }
        }
    }
}


void bfs2(pair<int, int> v){
    tr(v);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dist2[i][j] = inf;
        }
    }
    deque<pair<int, int> > s;
    s.push_front(v);
    dist2[v.fi][v.se] = 0;
    visited[v.fi][v.se] = 1;
    while(!s.empty()){
        auto temp = s.front();
        s.pop_front();
        int a = temp.fi, b = temp.se;
        visited[a][b] = 1;
        if(inp[a][b] == '#'){
            inp[a][b] = '.';
        }
        int curr_dist = dist2[a][b];
        if(valid(a + 1, b)){
            int cost = (inp[a + 1][b] == '#') + curr_dist;
            if(cost < dist2[a + 1][b]){
                dist2[a + 1][b] = cost;
                if(inp[a + 1][b] == '#'){
                    s.push_back(mp(a + 1, b));
                }
                else{
                    s.push_front(mp(a + 1, b));
                }
            }
        }
        if(valid(a - 1, b)){
            int cost = (inp[a - 1][b] == '#') + curr_dist;
            if(cost < dist2[a - 1][b]){
                dist2[a - 1][b] = cost;
                if(inp[a - 1][b] == '#'){
                    s.push_back(mp(a - 1, b));
                }
                else{
                    s.push_front(mp(a - 1, b));
                }
            }
        }
        if(valid(a, b + 1)){
            int cost = (inp[a][b + 1] == '#') + curr_dist;
            if(cost < dist2[a][b + 1]){
                dist2[a][b + 1] = cost;
                if(inp[a][b + 1] == '#'){
                    s.push_back(mp(a, b + 1));
                }
                else{
                    s.push_front(mp(a, b + 1));
                }
            }
        }
        if(valid(a, b - 1)){
            int cost = (inp[a][b - 1] == '#') + curr_dist;
            if(cost < dist2[a][b - 1]){
                dist2[a][b - 1] = cost;
                if(inp[a][b - 1] == '#'){
                    s.push_back(mp(a, b - 1));
                }
                else{
                    s.push_front(mp(a, b - 1));
                }
            }
        }
    }
}
void clear_all(){
    dist.clear();
    dist.resize(n, vector<int>(m));
    dist2.clear();
    dist2.resize(n, vector<int>(m));
    visited.clear();
    visited.resize(n, vector<int>(m));
}

int solve(){
    cin >> n >> m;
    clear_all();
    // tr(n, m);
    pair<int, int> s1, s2;
    s1.fi = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> inp[i][j];
            if(inp[i][j] == '$' and s1.fi == -1){
                s1.fi = i;
                s1.se = j;
            }
            else if(inp[i][j] == '$'){
                s2.fi = i;
                s2.se = j;
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << inp[i][j];
    //     }cout <<endl;
    // }
    bfs(s1, s2);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << dist[i][j]<< " ";
        }cout << endl;
    }
    return 0;
}

int32_t main(){ _
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}
