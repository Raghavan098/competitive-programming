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

const int N = 2002;

int n, m, r, c, x, y;
char inp[N][N];
int arr[N][N][2], visited[N][N], dist[N][N];

bool valid(int a, int b){
    if(a >= 0 and a < n and b >= 0 and b < m){
        if(inp[a][b] != '*'){
            return true;
        }
    }
    return false;
}

void bfs(){
    deque<pair<int, int> > q;
    q.push_front(mp(r, c));
    visited[r][c] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dist[i][j] = inf;
        }
    }
    dist[r][c] = 0;
    while(!q.empty()){
        auto node = q.front();
        q.pop_front();
        int a = node.fi;
        int b = node.se;
        visited[a][b] = 1;
        int curr_dist = dist[a][b];
        // tr(a, b, curr_dist);
        if(valid(a + 1, b) and curr_dist < dist[a + 1][b]){
            dist[a + 1][b] = curr_dist;
            arr[a + 1][b][1] = arr[a][b][1];
            arr[a + 1][b][0] = arr[a][b][0];
            q.push_front(mp(a + 1, b));
        }
        if(valid(a - 1, b) and curr_dist < dist[a - 1][b]){
            dist[a - 1][b] = curr_dist;
            arr[a - 1][b][1] = arr[a][b][1];
            arr[a - 1][b][0] = arr[a][b][0];
            q.push_front(mp(a - 1, b));
        }
        if(valid(a, b + 1) and curr_dist + 1 < dist[a][b + 1]){
            dist[a][b + 1] = curr_dist + 1;
            arr[a][b + 1][1] = arr[a][b][1] + 1;
            arr[a][b + 1][0] = arr[a][b][0];
            q.push_back(mp(a, b + 1));
        }
        if(valid(a, b - 1) and curr_dist + 1 < dist[a][b - 1]){
            dist[a][b - 1] = curr_dist + 1;
            arr[a][b - 1][1] = arr[a][b][1];
            arr[a][b - 1][0] = arr[a][b][0] + 1;
            q.push_back(mp(a, b - 1));
        }
    }
}


int32_t main(){ _
    cin >> n >> m;
    cin >> r >> c;
    r--, c--;
    cin >> x >> y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> inp[i][j];
        }
    }
    bfs();
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j][0] <= x and arr[i][j][1] <= y and inp[i][j] != '*' and visited[i][j] == 1){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
