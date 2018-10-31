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

vector<vector<int> > graph, shortest_path;
int n, m;

void floyd_warshall(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      shortest_path[i][j] = graph[i][j];
    }
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(shortest_path[i][k]+shortest_path[k][j]<shortest_path[i][j]){
          shortest_path[i][j] = shortest_path[i][k]+shortest_path[k][j];
        }
      }
    }
  }
  for(int i = 1; i <= n; i++){
      shortest_path[i][i] = 0;
  }
}

void clear_all(){
    graph.clear();
    graph.resize(n + 1, vector<int>(n + 1, INT_MAX));
    shortest_path.clear();
    shortest_path.resize(n + 1, vector<int>(n + 1, INT_MAX));
}

int solve(int ts){
    cin >> n >> m;
    clear_all();
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    floyd_warshall();
    int min_cost = inf;
    int cnt = 0;
    for(int i = 1; i < (1 << n) - 1; i++){
        int cost = 0;
        for(int j = 1; j <= n; j++){
            int to_find = 0;
            if((i&(1 << (j-1))) == 0){
                to_find = 1;
            }
            int mi = inf;
            for(int k = 1; k <= n; k++){
                if(((i&(1 << (k-1))) == 0) and to_find == 0){
                    if(mi > shortest_path[j][k]){
                        mi = shortest_path[j][k];
                    }
                }
                if((i&(1 << (k-1)))){
                    if(to_find == 1){
                        if(mi > shortest_path[j][k]){
                            mi = shortest_path[j][k];
                        }
                    }
                }
            }
            cost += mi;
        }
        if(cost < min_cost){
            min_cost = cost;
            cnt = 1;
        }
        else if(cost == min_cost){
            cnt += 1;
        }
    }
    cout << "Case #" << ts << ": " << cnt << endl;
    return 0;
}

int32_t main(){ __
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(i);
    }
}
