//Works for negative costs, but does not work for negative cycles
//Complexity: O(min(E^2 *V log V, E logV * flow))

struct edge
{
	ll to, flow, cap, cost, rev;
};

struct MinCostMaxFlow
{
	ll nodes;
	vector<ll> prio, curflow, prevedge, prevnode, q, pot;
	vector<bool> inqueue;
	vector<vector<edge> > graph;
	MinCostMaxFlow() {}

	MinCostMaxFlow(ll n): nodes(n), prio(n, 0), curflow(n, 0),
	prevedge(n, 0), prevnode(n, 0), q(n, 0), pot(n, 0), inqueue(n, 0), graph(n) {}

	void addEdge(ll source, ll to, ll capacity, ll cost)
	{
		edge a = {to, 0, capacity, cost, (ll)graph[to].size()};
		edge b = {source, 0, 0, -cost, (ll)graph[source].size()};
		graph[source].push_back(a);
		graph[to].push_back(b);
	}

	void bellman_ford(ll source, vector<ll> &dist)
	{
		fill(dist.begin(), dist.end(), INT_MAX);
		dist[source] = 0;
		ll qt=0;
		q[qt++] = source;
		for(ll qh=0;(qh-qt)%nodes!=0;qh++)
		{
			ll u = q[qh%nodes];
			inqueue[u] = false;
			for(auto &e : graph[u])
			{
				if(e.flow >= e.cap)
					continue;
				ll v = e.to;
				ll newDist = dist[u] + e.cost;
				if(dist[v] > newDist)
				{
					dist[v] = newDist;
					if(!inqueue[v])
					{
						inqueue[v] = true;
						q[qt++ % nodes] = v;
					}
				}
			}
		}
	}

	pair<ll, ll> minCostFlow(ll source, ll dest, ll maxflow)
	{
		bellman_ford(source, pot);
		ll flow = 0;
		ll flow_cost = 0;
		while(flow < maxflow)
		{
			priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > q;
			q.push({0, source});
			fill(prio.begin(), prio.end(), INT_MAX);
			prio[source] = 0;
			curflow[source] = INT_MAX;
			while(!q.empty())
			{
				ll d = q.top().first;
				ll u = q.top().second;
				q.pop();
				if(d != prio[u])
					continue;
				for(ll i=0;i<graph[u].size();i++)
				{
					edge &e=graph[u][i];
					ll v = e.to;
					if(e.flow >= e.cap)
						continue;
					ll newPrio = prio[u] + e.cost + pot[u] - pot[v];
					if(prio[v] > newPrio)
					{
						prio[v] = newPrio;
						q.push({newPrio, v});
						prevnode[v] = u;
						prevedge[v] = i;
						curflow[v] = min(curflow[u], e.cap - e.flow);
					}
				}
			}
			if(prio[dest] == INT_MAX)
				break;
			for(ll i=0;i<nodes;i++)
				pot[i]+=prio[i];
			ll df = min(curflow[dest], maxflow - flow);
			flow += df;
			for(ll v=dest;v!=source;v=prevnode[v])
			{
				edge &e = graph[prevnode[v]][prevedge[v]];
				e.flow += df;
				graph[v][e.rev].flow -= df;
				flow_cost += df * e.cost;
			}
		}
		return {flow, flow_cost};
	}
};
