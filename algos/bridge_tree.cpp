const int N = 1e5 + 100;

vector<vector<int> > edg(N), tree(N);


int V[N], U[N];
int isBridge[N];

int visited[N];

int arr[N], t;
int cmp_no = 1;
int cnt[N];
queue<int> Q[N];

map<int, int> cmp_id;

int n, m;

int adj(int u,int e){
    return U[e] == u ? V[e] : U[e];
}

int dfs0(int u, int edge){
    visited[u] = 1;
    arr[u] = t++;
    int dbe = arr[u];
    for(auto e: edg[u]){
        int w = adj(u, e);
        if(visited[w] == 0){
            dbe = min(dbe, dfs0(w, e));
        }
        else if(e != edge){
            dbe = min(dbe, arr[w]);
        }
    }
    if(dbe == arr[u] and edge != -1){
        // tr(edge);
        isBridge[edge] = 1;
    }
    return dbe;
}

void dfs1(int v){
    int currcmp = cmp_no;
    Q[currcmp].push(v);
    visited[v] = 1;
    while(!Q[currcmp].empty()){
        int u = Q[currcmp].front();
        Q[currcmp].pop();
        cnt[currcmp]++;
        cmp_id[u] = currcmp;
        for(auto e: edg[u]){
            int w = adj(u, e);
            if(visited[w] == 1){
                continue;
            }
            if(isBridge[e] == 1){
                cmp_no++;
                tree[currcmp].pb(cmp_no);
                tree[cmp_no].pb(currcmp);
                dfs1(w);
            }
            else{
                Q[currcmp].push(w);
                visited[w] = 1;
            }
        }
    }
}
