int nn;

void dfs1(int u, int p){
    sub[u] = 1;
    nn++;
    for(auto v: g[u]){
        if(v != p){
            dfs1(v, u);
            sub[u] += sub[v];
        }
    }
}

int dfs2(int u, int p){
    for(auto v: g[u]){
        if(v != p and sub[v] > nn / 2){
            return dfs2(v, u);
        }
    }
    return u;
}

void decompose(int v, int p){
    nn = 0;
    dfs1(v, v);
    int centroid = dfs2(v, v);
    if(p == -1){
        p = centroid;
    }
    par[centroid] = p;
    for(auto u: g[centroid]){
        g[u].erase(centroid);
        decompose(u, centroid);
    }
    g[centroid].clear();
}
