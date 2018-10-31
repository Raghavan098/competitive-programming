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

const int N = 1500;

int n, m;
int visited[N][N][2];
string arr[N];

int gor[4] = {0, 0, -1, 1};
int goc[4] = {1, -1, 0, 0};

bool valid(int a, int b){
    return (a >= 0 and a < n and b >= 0 and b < m and arr[a][b] != '#');
}

int getr(int a){
    a = a % n;
    if(a < 0) a += n;
    return a;
}

int getc(int a){
    a = a % m;
    if(a < 0) a += m;
    return a;
}

void dfs(int r, int c){
    int a = getr(r);
    int b = getc(c);
    if(arr[a][b] == '#') return;
    if(visited[a][b][0] == r and visited[a][b][1] == c){
        return;
    }
    if(!(visited[a][b][0] == -1 and visited[a][b][1] == -1) and (visited[a][b][0] != r or visited[a][b][1] != c)){
        cout << "Yes\n";
        exit(0);
    }
    visited[a][b][0] = r;
    visited[a][b][1] = c;
    for(int i = 0; i < 4; i++){
        dfs(r + gor[i], c + goc[i]);
    }
}

int32_t main(){ _
    cin >> n >> m;
    int sr, sc;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 'S'){
                sr = i;
                sc = j;
                break;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visited[i][j][0] = -1;
            visited[i][j][1] = -1;
        }
    }
    dfs(sr, sc);
    cout << "No\n" << endl;
    return 0;
}
