// see UPDOTR.cpp

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

int level[N];

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    level[v] = level[p] + 1;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancetor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancetor(u, v))
        return u;
    if (is_ancetor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancetor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n + 1);
    tout.resize(n + 1);
    timer = 0;
    l = ceil(log2(n)) + 1;
    up.assign(n + 1, vector<int>(l + 2));
    dfs(root, root);
}

int dist(int u,int v)
{
	return level[u] + level[v] - 2*level[lca(u,v)];
}
