#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
typedef long long int lli;
using namespace std;

/*
    x
  /  \
lc   rc
/\    /\
.........

*/

/*
  1 L R x
  2 L R
*/

const int N = 100100;
vector<vector<lli> >gr;
lli n,m;
vector<lli> start;
vector<pair<lli,lli> > arr;
vector<lli> brr,vis;
vector<lli>ind;
struct node{
  int min_val;
  int lazy;

  node(){
    lazy = 0;
  }
};

node tree[2 * N];
int array[N];
void dfsVisit(lli node){
	vis[node]=1;
	arr.push_back(make_pair(node,start[node]));
	ind[node]=arr.size();
	lli i;
	for(i=0;i<gr[node].size();i++){
		if(vis[gr[node][i]]==0){
			dfsVisit(gr[node][i]);
		}
	}
	brr[node]=arr.size();
}
void dfs(){
	lli i;
	for(i=1;i<=n;i++){
		if(vis[i]==0){
			dfsVisit(i);
		}
	}
}
void combine(int root, int lc, int rc){
  //tree[root].min_val = min(tree[lc].min_val, tree[rc].min_val);
  tree[root].min_val = tree[lc].min_val+ tree[rc].min_val;
}

void build(int id, int l, int r){
  if(l == r){
    tree[id].min_val = array[l];
    return;
  }

  int mid = (l + r) >> 1;
  int lc = 2 * id;
  int rc = lc + 1;

  build(lc, l, mid);
  build(rc, mid+1, r);
  combine(id, lc, rc);
}

void push_down(int child, int l, int r, int parent){
  tree[child].min_val += tree[parent].lazy;
  tree[child].lazy += tree[parent].lazy;
}

void propagate(int id, int l, int r){
  int mid = (l + r) >> 1;
  int lc = 2 * id;
  int rc = lc + 1;

  push_down(lc, l, mid, id);
  push_down(rc, mid+1, r, id);

  tree[id].lazy = 0;
}

// query interval = [x,y]
// node interval = [l,r]
void range_update(int x, int y, int val, int id, int l, int r){
  if(y < l) return;
  if(x > r) return;

  // [x...[l...r]...y]
  if(x <= l and r <= y){
    tree[id].min_val += val;
    tree[id].lazy += val;
    return;
  }

  int mid = (l + r) >> 1;
  int lc = 2 * id;
  int rc = lc + 1;

  if(tree[id].lazy > 0){
    propagate(id, l, r);
  }

  range_update(x, y, val, lc, l, mid);
  range_update(x, y, val, rc, mid+1, r);

  combine(id, lc, rc);
}

const int INF = 1e9 + 1;

int range_query(int x, int y, int id, int l, int r){
  if(y < l or x > r) return INF;

  if(x <= l and y <= r){
    return tree[id].min_val;
  }

  int mid = (l + r) >> 1;
  int lc = 2 * id;
  int rc = lc + 1;

  if(tree[id].lazy > 0){
    propagate(x, l, r);
  }

  int left_min = range_query(x, y, val, l, mid);
  int right_min = range_query(x, y, val, mid+1, r);

  combine(lc, rc, id);

  return left_min+ right_min;
}

void answer(){
  char type;
  cin >> type;

  if(type == 'U'){
    int l, r, x;
    cin >> l >> x;
    r=l;
    range_update(l, r, x, 1, 1, n);
  }
  else{
    int l, r;
    cin >> l ;
    cout << range_query(ind[l]-1, brr[arr[ind[l]-1].first]-1, 1, 1, n) << endl;
  }
}
int main(){
	cin >> n >> m;
	ind.resize(n+1);
	start.resize(n+1);
	vis.resize(n+1);
	gr.resize(n+1);
	brr.resize(n+1);
	start[0]=0;
	vis[0]=0;
	lli i;
	for(i=1;i<=n;i++){include<iostream>
#include<vector>
#include<algorithm>
#include<map>
typedef long long int lli;
using namespace std;

/*
    x
  /  \
lc   rc
/\    /\
.........

*/

/*
  1 L R x
  2 L R
*/

const int N = 100100;
vector<vector<lli> >gr;
lli n,m;
vector<lli> start;
vector<pair<lli,lli> > arr;
vector<lli> brr,vis;
vector<lli>ind;
struct node{
  int min_val;
  int lazy;

  node(){
    lazy = 0;
  }
};

node tree[2 * N];
int array[N];
void dfsVisit(lli node){
	vis[node]=1;
	arr.push_back(make_pair(node,start[node]));
	ind[node]=arr.size();
	lli i;
	for(i=0;i<gr[node].size();i++){
		if(vis[gr[node][i]]==0){
			dfsVisit(gr[node][i]);
		}
	}
	brr[node]=arr.size();
}
void dfs(){
	lli i;
	for(i=1;i<=n;i++){
		if(vis[i]==0){
			dfsVisit(i);
		}
	}
}
void combine(int root, int lc, int rc){
  //tree[root].min_val = min(tree[lc].min_val, tree[rc].min_val);
  tree[root].min_val = tree[lc].min_val+ tree[rc].min_val;
}

void build(int id, int l, int r){
  if(l == r){
    tree[id].min_val = array[l];
    return;
  }

  int mid = (l + r) >> 1;
  int lc = 2 * id;
  int rc = lc + 1;

  build(lc, l, mid);
  build(rc, mid+1, r);
  combine(id, lc, rc);
}

void push_down(int child, int l, int r, int parent){
  tree[child].min_val += tree[parent].lazy;
  tree[child].lazy += tree[parent].lazy;
}

void propagate(int id, int l, int r){
  int mid = (l + r) >> 1;
  int lc = 2 * id;
  int rc = lc + 1;

  push_down(lc, l, mid, id);
  push_down(rc, mid+1, r, id);

  tree[id].lazy = 0;
}

// query interval = [x,y]
// node interval = [l,r]
void range_update(int x, int y, int val, int id, int l, int r){
  if(y < l) return;
  if(x > r) return;

  // [x...[l...r]...y]
  if(x <= l and r <= y){
    tree[id].min_val += val;
    tree[id].lazy += val;
    return;
  }

  int mid = (l + r) >> 1;
  int lc = 2 * id;
  int rc = lc + 1;

  if(tree[id].lazy > 0){
    propagate(id, l, r);
  }

  range_update(x, y, val, lc, l, mid);
  range_update(x, y, val, rc, mid+1, r);

  combine(id, lc, rc);
}

const int INF = 1e9 + 1;

int range_query(int x, int y, int id, int l, int r){
  if(y < l or x > r) return INF;

  if(x <= l and y <= r){
    return tree[id].min_val;
  }

  int mid = (l + r) >> 1;
  int lc = 2 * id;
  int rc = lc + 1;

  if(tree[id].lazy > 0){
    propagate(x, l, r);
  }

  int left_min = range_query(x, y, val, l, mid);
  int right_min = range_query(x, y, val, mid+1, r);

  combine(lc, rc, id);

  return left_min+ right_min;
}

void answer(){
  char type;
  cin >> type;

  if(type == 'U'){
    int l, r, x;
    cin >> l >> x;
    r=l;
    range_update(l, r, x, 1, 1, n);
  }
  else{
    int l, r;
    cin >> l ;
    cout << range_query(ind[l]-1, brr[arr[ind[l]-1].first]-1, 1, 1, n) << endl;
  }
}
int main(){
	cin >> n >> m;
	ind.resize(n+1);
	start.resize(n+1);
	vis.resize(n+1);
	gr.resize(n+1);
	brr.resize(n+1);
	start[0]=0;
	vis[0]=0;
	lli i;
	for(i=1;i<=n;i++){
		cin >> start[i];
		vis[i]=0;
	}
	for(i=0;i<n-1;i++){
		lli x,y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	dfs();
	for(i=0;i<arr.size();i++){
		array[i+1]=arr[i].second;
	}
	for(i=1;i<=n;i++){
		cout<<array[i]<<" ";
	}cout<<endl;
	build(1,1,arr.size());
	while(m--){
		answer();
	}
	return 0;
}
		cin >> start[i];
		vis[i]=0;
	}
	for(i=0;i<n-1;i++){
		lli x,y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	dfs();
	for(i=0;i<arr.size();i++){
		array[i+1]=arr[i].second;
	}
	for(i=1;i<=n;i++){
		cout<<array[i]<<" ";
	}cout<<endl;
	build(1,1,arr.size());
	while(m--){
		answer();
	}
	return 0;
}
