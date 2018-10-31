// Solution for Chase
// Author: Thijs
// @EXPECTED_RESULTS@: CORRECT
//
// Runs dijkstra only once

#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

#define MAX_VER 2000
#define INFINITE 0xffffffffffll

struct edge {
    int to;
    int length;
    edge(int to, int length) : to(to), length(length) {}
};

struct vertex {
    vector<edge> edges;
    ll dis;
};

vertex vertices[MAX_VER];

void reset() {
    for (int i=0; i < MAX_VER; i++) {
        vertices[i].edges.clear();
        vertices[i].dis = INFINITE;
    }
}
void resetDis() {
    for (int i=0; i < MAX_VER; i++) {
        vertices[i].dis = INFINITE;
    }
}

void addedge(int from, int to, int length=-1, bool directed=true) {
    vertices[from].edges.push_back(edge(to, length));
    if (!directed) vertices[to].edges.push_back(edge(from, length));
}

typedef pair<ll, int> pp;
void dijkstra(int source) {
    //distance, vertex
    priority_queue<pp, vector<pp>, greater<pp> > q;
    vertices[source].dis = 0;
    q.push(make_pair(0, source));
    
    while (!q.empty()) {
        int u = q.top().second;
        ll dis = q.top().first;
        q.pop();
        if (dis > vertices[u].dis) continue;
        for (size_t i = 0; i < vertices[u].edges.size(); i++) {
            edge &e = vertices[u].edges[i];
            if (dis + e.length < vertices[e.to].dis) {
                vertices[e.to].dis = dis + e.length;
                q.push(make_pair(vertices[e.to].dis, e.to));
            }
        }
    }
}


void doStep()
{
	reset();
	int n,m,t;
	cin>>n>>m>>t;
	int s,g,h;
	vector<int> dests(t);
	cin>>s>>g>>h;
	s--;g--;h--;
	for(int i=0;i<m;i++)
	{
		int a,b,d;
		cin>>a>>b>>d;
		a--;b--;
		d *= 2;
		if((a==g&&b==h) || (a==h&&b==g))
			d--;
		addedge(a,b,d,false);
	}
	for(int i=0;i<t;i++)
	{
		cin>>dests[i];
		dests[i]--;
	}

	dijkstra(s);

	vector<int> ans;
	for(int i=0; i<t; i++)
	{
		if (vertices[dests[i]].dis!=INFINITE && vertices[dests[i]].dis%2 == 1)
			ans.push_back(dests[i]+1);
	}
	if (ans.size() == 0)
	{
		cout<<"NO PATH FOUND VIA G<>H"<<endl;
	} else {
		sort(ans.begin(), ans.end());
		cout<<ans[0];
		for(int i=1; i<(int)ans.size();i++)
			cout<<" "<<ans[i];
		cout<<endl;
	}
}

int main()
{
	int n;
	cin >> n;
	while (n--) doStep();
	return 0;
}
