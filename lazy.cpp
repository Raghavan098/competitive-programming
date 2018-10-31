const int LOGN = 20;
const int N = 1 << LOGN;

struct node{
  ll sum;
  node(){
    sum = 0;
  }

  void add(ll x){
    sum += x;
  }

  void combine(node &l, node &r){
    sum = l.sum + r.sum;
  }
};

node tree[N];
ll lazy[N];
int n, m;

void push(int id, ll val, int l, int r){
  lazy[id] += val;
  tree[id].add(val * (r - l  +1));
}

void update(int x, int y, ll val, int id = 1, int l = 1, int r = n){
  if(y < l or x > r) return;
  if(x <= l and r <= y){
    lazy[id   ] += val;
    tree[id].add(val * (r-l+1));
    return;
  }

  int lft = 2 * id, right = lft + 1;
  int mid = (l + r) / 2;

  if(lazy[id]){
    push(lft, lazy[id], l, mid);
    push(right, lazy[id], mid+1, r);
    lazy[id] = 0;
  }

  update(x, y, val, lft, l, mid);
  update(x, y, val, right, mid+1, r);

  tree[id].combine(tree[lft], tree[right]);
  return;
}

ll query(int x, int y, int id = 1, int l = 1, int r = n){
  if(y < l or x > r) return 0;

  if(x <= l and r <= y) return tree[id].sum;

  int lft = 2 * id, right = lft + 1;
  int mid = (l + r) / 2;

  if(lazy[id]){
    push(lft, lazy[id], l, mid);
    push(right, lazy[id], mid+1, r);
    lazy[id] = 0;
  }

  return query(x, y, lft, l, mid) + query(x, y, right, mid+1, r);

}
