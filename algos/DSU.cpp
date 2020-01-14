const int N = 100100;
int parent[N];
int size[N];
void make_set(int x) {
    parent[x] = x;
    size[x] = 1;
}
int find_set(int v) {
    if(v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(size[a] < size[b]) {
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}
