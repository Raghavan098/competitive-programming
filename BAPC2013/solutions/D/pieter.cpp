// Solution to Destination Unknown
// Author: Pieter Bootsma

// Time complexity: O(m log n + t*n*log n)
// Memory: O(n + m + t*n*log n)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: store visits of G and H on shortest paths between S and destinations

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

#define MAX_VER 2005
#define INFINITE 0x3fffffff // 7*f ~ 1.000.000.000

struct edge
{
	int to;
	int length;
	edge(int to, int length) : to(to), length(length) {}
};

struct vertex
{
	vector<edge> edges;
	int dis;
	int prev;
	set<int> visits;
};

vertex vertices[MAX_VER];

typedef pair<int, int> pp;
void dijkstra(int source)
{
	priority_queue<pp, vector<pp>, greater<pp> > q;
	vertices[source].dis = 0;
	q.push(make_pair(0, source));
	
	while (!q.empty())
	{
		int u = q.top().second;
		int dis = q.top().first;
		q.pop();
		if (dis > vertices[u].dis)
			continue;
		for (size_t i = 0; i < vertices[u].edges.size(); i++)
		{
			edge &e = vertices[u].edges[i];
			if (dis + e.length < vertices[e.to].dis)
			{
				vertices[e.to].dis = dis + e.length;
				vertices[e.to].prev = u;
				q.push(make_pair(vertices[e.to].dis, e.to));
			}
		}
	}
}

void trace(int source, int cur, int mark)
{
	auto ok = vertices[cur].visits.insert(mark);
	if (!ok.second || (cur == source))
	{
		return;
	}
	for (size_t i = 0; i < vertices[cur].edges.size(); i++)
	{
		edge &e = vertices[cur].edges[i];
		if (vertices[cur].dis - e.length == vertices[e.to].dis)
			trace(source, e.to, mark);
	}
}

void dostep()
{
	int n,m,t;
	cin >> n >> m >> t;
	
	for (int i = 1; i <= n; i++)
	{
		vertices[i].edges.clear();
		vertices[i].dis = INFINITE;
		vertices[i].prev = -1;
		vertices[i].visits.clear();
	}
	
	int s,g,h;
	cin >> s >> g >> h;
	
	for (int i = 0; i < m; i++)
	{
		int a,b,d;
		cin >> a >> b >> d;
		
		vertices[a].edges.push_back(edge(b, d));
		vertices[b].edges.push_back(edge(a, d));
	}
	
	dijkstra(s);
	
	for (int i = 0; i < t; i++)
	{
		int x;
		cin >> x;
		trace(s, x, x);
	}
	
	vector<int> destinations;
	back_insert_iterator< vector<int> > back_it(destinations);
	auto &G = vertices[g].visits;
	auto &H = vertices[h].visits;
	set_intersection(G.begin(), G.end(), H.begin(), H.end(), back_it);
	for (size_t i = 0; i < destinations.size(); i++)
	{
		if (i > 0)
			cout << ' ';
		cout << destinations[i];
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	return 0;
}
