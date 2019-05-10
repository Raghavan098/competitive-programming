// call build in main function with v = 1, l = 0, r = n - 1

const int N = 2e5 + 100;


struct data{
    int val;
    int lev;
};

data seg_tree[4*N];
int arr[N], n, q;

data combine(data l, data r){
    data res;
    if(l.lev == 0){
        res.val = l.val|r.val;
        res.lev = 1;
    }
    else{
        res.val = l.val^r.val;
        res.lev =  0;
    }
    return res;
}

void build(int v, int l, int r){
    if(l == r){
        // base case
        seg_tree[v].val = arr[l];
        seg_tree[v].lev = 0;
        return;
    }
    int m = (l + r) / 2;
    build(2*v, l, m);
    build(2*v + 1, m + 1, r);
    seg_tree[v] = combine(seg_tree[2*v], seg_tree[2*v + 1]);
    return;
}

void update(int v, int l, int r, int pos, int new_val){
    if(l == r){
        seg_tree[v].val = new_val;
        return;
    }
    int m = (l + r) / 2;
    if(pos <= m){
        update(2*v, l, m, pos, new_val);
    }
    else{
        update(2*v + 1, m + 1, r, pos, new_val);
    }
    seg_tree[v] = combine(seg_tree[2*v], seg_tree[2*v + 1]);
}

data query(int v, int l, int r, int ql, int qr){
    if(ql > qr){
        data ans;
        ans.val = 0;
        ans.lev = seg_tree[v].lev;
        return ans;
    }
    if(ql == l and qr == r){
        return seg_tree[v];
    }
    int m = (l + r) / 2;
    return combine(query(2*v, l, m, ql, min(qr, m)), query(2*v + 1, m + 1, r, max(ql, m + 1), qr));
}
