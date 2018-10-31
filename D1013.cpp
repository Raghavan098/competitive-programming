// g++ -std=c++14

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
const int N = 2e5 + 5;
int n, m, q;
map<int, vector<int> > g1,g2;
int visited1[N],visited2[N];

void dfs(int u, int t){
    if(t == 1){
        visited1[u] = 1;
        for(auto i: g1[u]){
            if(visited2[i] == 0){
                dfs(i, 2);
            }
        }
    }
    else{
        visited2[u] = 1;
        for(auto i: g2[u]){
            if(visited1[i] == 0){
                dfs(i, 1);
            }
        }
    }

}

int main(){ _
    cin >> n >> m >> q;
    for(int i = 0; i < q; i++){
        int r, c;
        cin >> r >> c;
        g1[r].pb(c);
        g2[c].pb(r);
    }
    int c = 0;
    for(int i = 1; i <= n; i++){
        if(visited1[i] == 0){
            c ++;
            dfs(i, 1);
        }
    }
    for(int i = 1; i <= m; i++){
        if(visited2[i] == 0){
            c ++;
            dfs(i, 2);
        }
    }
    cout << c-1 <<endl;
    return 0;
}
