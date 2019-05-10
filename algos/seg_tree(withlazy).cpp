// call build in main function with v = 1, l = 0, r = n - 1

const int N = 2e5 + 100;
const int M = 400;

int t[4 * N];
int lazy[4 * N];

void build(int v, int l, int r){
    if(l == r){
        t[v] = arr[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m + 1, r);
    t[v] = min(t[2 * v], t[2 * v + 1]);
    return;
}

void push(int v) {
    t[v * 2] += lazy[v];
    lazy[v * 2] += lazy[v];
    t[v * 2 + 1] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    }
    else {
        if(lazy[v] != 0){
            push(v);
        }
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), addend);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return inf;
    if (l <= tl && tr <= r)
        return t[v];
    if(lazy[v] != 0){
        push(v);
    }
    int tm = (tl + tr) / 2;
    return min(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
