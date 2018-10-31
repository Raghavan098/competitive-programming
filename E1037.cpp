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
const int N = 2e5 + 10;

int n, m, k, deg[N], visited[N];
vector<set<int> > g(N);
set<int> s;
vector<pair<int, int > > edg;
vector<int> ans;
void insert_node(int v){
    s.insert(v);
}
void delete_node(int v){
    queue<int> q;
    q.push(v);
    visited[v] = 1;
    if(s.find(v) != s.end()){
        s.erase(v);
    }
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(auto u: g[temp]){
            deg[u]--; deg[temp]--;
			g[u].erase(temp);
            if(deg[u] < k and visited[u] != 1){
                q.push(u);
                visited[u] = 1;
                if(s.find(u) != s.end()){
                    s.erase(u);
                }
            }
        }
		g[temp].clear();
    }
}


int32_t main(){
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[a].insert(b), g[b].insert(a);
		deg[a]++, deg[b]++;
		edg.pb(mp(a, b));
	}
	for(int i = 1; i <= n; i++){
		if(deg[i] >= k){
			insert_node(i);
		}
		else{
			delete_node(i);
		}
	}
	for(int i = m - 1; i >= 0; i--){
		ans.pb((int)s.size());
		auto temp = edg[i];
		if(visited[temp.fi] == 1 or visited[temp.se] == 1) continue;
		deg[temp.fi]--, deg[temp.se]--;
		g[temp.fi].erase(temp.se);
		g[temp.se].erase(temp.fi);
		if(deg[temp.fi] < k){
			delete_node(temp.fi);
		}
		if(deg[temp.se] < k){
			delete_node(temp.se);
		}
	}
	reverse(all(ans));
	for(auto i: ans){
		cout << i << endl;
	}
	return 0;
}
