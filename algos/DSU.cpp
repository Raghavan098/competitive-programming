const ll N = 100100;
ll parent[N];
ll size[N];

void make_set(ll x){
    parent[x] = x;
    size[x] = 1;
}

ll find_set(ll v){
    if(v==parent[v]){
        return v;
    }
    return parent[v] =find_set(parent[v]);
}

void union_sets(ll a,ll b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}
