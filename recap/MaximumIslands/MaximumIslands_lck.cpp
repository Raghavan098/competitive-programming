#include <iostream>
#include <vector>
#include <cstring>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

const ll MAXN = (55*55)+10;
struct edge {
	ll a, b, cap, flow;
};
/*
Set
dinic_numnodes: number of nodes
dinic_src: Source vertex
dinic_dest: Target vertex
No need to initialize anything else. Run ge.clear() and dinic_graph.clear() between runs.
*/
ll dinic_numnodes, dinic_src, dinic_dest, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> dinic_edge;
vector<ll> dinic_graph[MAXN];
 
void add_edge (ll a, ll b, ll cap) {
	//printf("%lld->%lld:%lld\n",a,b,cap);
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	dinic_graph[a].push_back ((ll) dinic_edge.size());
	dinic_edge.push_back (e1);
	dinic_graph[b].push_back ((ll) dinic_edge.size());
	dinic_edge.push_back (e2);
}

bool bfs() {
	ll qh=0, qt=0;
	q[qt++] = dinic_src;
	memset (d, -1, dinic_numnodes * sizeof d[0]);
	d[dinic_src] = 0;
	while (qh < qt && d[dinic_dest] == -1) {
		ll v = q[qh++];
		for (size_t i=0; i<dinic_graph[v].size(); ++i) {
			ll id = dinic_graph[v][i],
				to = dinic_edge[id].b;
			if (d[to] == -1 && dinic_edge[id].flow < dinic_edge[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[dinic_dest] != -1;
}
 
ll dfs (ll v, ll flow) {
	if (!flow)  return 0;
	if (v == dinic_dest)  return flow;
	for (; ptr[v]<(ll)dinic_graph[v].size(); ++ptr[v]) {
		ll id = dinic_graph[v][ptr[v]],
			to = dinic_edge[id].b;
		if (d[to] != d[v] + 1)  continue;
		ll pushed = dfs (to, min (flow, dinic_edge[id].cap - dinic_edge[id].flow));
		if (pushed) {
			dinic_edge[id].flow += pushed;
			dinic_edge[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
ll dinic(ll src, ll dest, ll numnodes) {
	dinic_src = src;
	dinic_dest = dest;
	dinic_numnodes = numnodes;
	ll flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, dinic_numnodes * sizeof ptr[0]);
		while (ll pushed = dfs (dinic_src, INF))
			flow += pushed;
	}
	return flow;
}
void dinic_clear(ll numnodes) {
	dinic_edge.clear();
	for (ll v=0;v<numnodes;v++) dinic_graph[v].clear();	
}



char b[55][55];
char c[55][55];
bool seen[55][55];
void dfs_land(ll x, ll y) {
	if (b[x][y]!='L') return;
	if (seen[x][y]) return;
	seen[x][y]=true;
	dfs_land(x+1,y);
	dfs_land(x-1,y);
	dfs_land(x,y+1);
	dfs_land(x,y-1);
}
ll getnode(ll x,ll y) {
	return x*55+y;
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,m; cin>>n>>m;
	for (ll x=0;x<=n+1;x++) for (ll y=0;y<=m+1;y++) b[x][y]='W';
	for (ll x=0;x<n;x++) for (ll y=0;y<m;y++) {
		cin>>b[x+1][y+1];
	}
	ll ans=0;
	memset(seen,0,sizeof seen);
	for (ll x=1;x<=n;x++) for (ll y=1;y<=m;y++) {
		if (b[x][y]=='L'&&!seen[x][y]) {dfs_land(x,y);ans++;}
	}
	for (ll x=0;x<=n+1;x++) for (ll y=0;y<=m+1;y++) c[x][y]=b[x][y];
	for (ll x=1;x<=n;x++) for (ll y=1;y<=m;y++) {
		if (c[x][y]=='L') {
			b[x+1][y]='W';
			b[x-1][y]='W';
			b[x][y+1]='W';
			b[x][y-1]='W';
		}
	}
	ll src=MAXN-2;
	ll dest=MAXN-1;
	ll all=0;
	for (ll x=1;x<=n;x++) for (ll y=1;y<=m;y++) {
		if (b[x][y]=='C') {
			//printf("%lld %lld\n",x,y);
			all++;
			if ((x+y)&1) {
				add_edge(src,getnode(x,y),1);
				if (b[x+1][y]=='C') add_edge(getnode(x,y),getnode(x+1,y),1);
				if (b[x][y+1]=='C') add_edge(getnode(x,y),getnode(x,y+1),1);
				if (b[x-1][y]=='C') add_edge(getnode(x,y),getnode(x-1,y),1);
				if (b[x][y-1]=='C') add_edge(getnode(x,y),getnode(x,y-1),1);
			}
			else add_edge(getnode(x,y),dest,1);
		}
	}
	ll flow=dinic(src,dest,MAXN);
	ll additional=all-flow;
	ll final=ans+additional;
	//printf("%lld %lld %lld\n",ans,additional,flow);
	cout<<final<<endl;
}
