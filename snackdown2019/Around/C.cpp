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

const int N = 60;

int edg[N][N];
int n, arr[N], g[N][N], visited[N];

void clear_all(){
    MEMS(arr, 0);
    MEMS(g, 0);
    MEMS(visited, 0);
}

void dfs(int v){
    visited[v] = 1;
    for(int i = 0; i < n; i++){
        if(g[v][i] == 1 and visited[i] == 0){
            dfs(i);
        }
    }
}

int solve(){
    clear_all();
    int check = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] != 47){
            check = 1;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(edg[arr[i]][arr[j]] == 1 or edg[arr[j]][arr[i]] == 1){
                g[i][j] = 1;
            }
        }
    }
    int cmp = 0;
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            cmp++;
            dfs(i);
        }
    }
    if(cmp == 1){
        cout << 0 << endl;
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }cout << endl;
    }
    else{
        cout << 1 << endl;
        if(check == 0){
            arr[0] = 43;
        }
        else{
            arr[0] = 47;
        }
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }cout << endl;
    }
    return 0;
}

int32_t main(){ _
    for(int i = 1; i < N; i++){
        for(int j = 1; j < N; j++){
            if(__gcd(i, j) == 1){
                edg[i][j] = 1;
            }
        }
    }
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
    return 0;
}
