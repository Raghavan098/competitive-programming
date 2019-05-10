const ll inf = 1e18;

struct edge {
    ll x, y, cap, flow;
};

struct DinicFlow {
    vector <edge> e;
    vector <ll> cur, d;
    vector < vector <ll> > adj;
    ll source, sink, n;

    DinicFlow() {}

    DinicFlow(ll v, ll s, ll t) {
        n = v, source = s, sink = t;
        cur = vector <ll> (n + 1);
        d = vector <ll> (n + 1);
        adj = vector < vector <ll> > (n + 1);
    }

    void addEdge(ll from, ll to, ll cap) {
        edge e1 = {from, to, cap, 0};
        edge e2 = {to, from, 0, 0};
        adj[from].push_back(e.size()); e.push_back(e1);
        adj[to].push_back(e.size()); e.push_back(e2);
    }

    ll bfs() {
        queue <ll> q;
        for(ll i = 0; i <= n; ++i) d[i] = -1;
        q.push(source); d[source] = 0;
        while(!q.empty() and d[sink] < 0) {
            ll x = q.front(); q.pop();
            for(ll i = 0; i < (ll)adj[x].size(); ++i) {
                ll id = adj[x][i], y = e[id].y;
                if(d[y] < 0 and e[id].flow < e[id].cap) {
                    q.push(y); d[y] = d[x] + 1;
                }
            }
        }
        return d[sink] >= 0;
    }

    ll dfs(ll x, ll flow) {
        if(!flow) return 0;
        if(x == sink) return flow;
        for(;cur[x] < (ll)adj[x].size(); ++cur[x]) {
            ll id = adj[x][cur[x]], y = e[id].y;
            if(d[y] != d[x] + 1) continue;
            ll pushed = dfs(y, min(flow, e[id].cap - e[id].flow));
            if(pushed) {
                e[id].flow += pushed;
                e[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    ll maxFlow() {
        ll flow = 0;
        while(bfs()) {
            for(ll i = 0; i <= n; ++i) cur[i] = 0;
            while(ll pushed = dfs(source, inf)) {
                flow += 1ll*pushed;
            }
        }
        return flow;
    }
};
