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
#define inf INT_MAX

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

// #define int ll

#define no printf("NO\n");

const int N = 2010;

int parent[N];
int size[N];


int n, d[N][N];
vector<vector<pair<int, int> > > g(N);


void make_set(int x){
    parent[x] = x;
    size[x] = 1;
}

int find_set(int v){
    if(v==parent[v]){
        return v;
    }
    return parent[v] =find_set(parent[v]);
}

void union_sets(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

void validate(){
    for(int i = 1; i <= n; i++){
        if(d[i][i] != 0){
            no
            exit(0);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(d[i][j] != d[j][i]){
                no
                exit(0);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i != j and d[i][j] == 0){
                no
                exit(0);
            }
        }
    }
}

bool check(int s){
    vector<int> dist(n + 1, inf);
    priority_queue<pair<int, int>, vector<pair<int, int> > > q;
    dist[s] = 0;
    q.push(mp(-dist[s],s));
    while(!q.empty()){
        auto temp = q.top();
        int v = temp.se;
        int v_d = -temp.fi;
        q.pop();
        for(auto t:g[v]){
            int to = t.se;
            int weight = t.fi;
            int get_out = v_d + weight;
            if(get_out<dist[to]){
                dist[to] = get_out;
                q.push(mp(-get_out,to));
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(d[s][i] != dist[i]){
            return false;
        }
    }
    return true;
}

int32_t main(){
    sd(n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sd(d[i][j]);
        }
    }
    validate();
    for(int i = 1; i <= n; i++){
        make_set(i);
    }
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > > > s;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            s.push(mp(-d[i][j], mp(i, j)));
        }
    }
    int taken = 0;
    while(!s.empty() and taken < (n - 1)){
        auto top = s.top();
        s.pop();
        int dist = -top.fi;
        int u = top.se.fi, v = top.se.se;
        if(find_set(u) == find_set(v)){
            continue;
        }
        union_sets(u, v);
        g[u].pb(mp(dist, v));
        g[v].pb(mp(dist, u));
        taken++;
    }
    for(int i = 1; i <= n; i++){
        if(!check(i)){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
