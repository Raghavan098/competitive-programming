#include<bits/stdc++.h>

using namespace std;

const int N = 1 << 17;

struct node{
	int cnt;
	void assign(int value){
		cnt = value;
	}
	void update(int value){
		cnt += value;
	}
	void combine(node &left, node &right){
		cnt = left.cnt + right.cnt;
	}
};

int n, a[N], lazy[N];
node tree[2*N];

// [l, r)
void build(int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(a[l]);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;

	build(left, l, mid); build(right, mid, r);

	tree[id].combine(tree[left], tree[right]);
	return;
}

// point update -> update(index, value);
void update(int index, int val, int id = 1, int l = 0, int r = n){
	if(l+1 == r){
		tree[id].assign(val);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;

	if(index < mid) update(index, val, left, l, mid);
	else update(index, val, right, mid, r);

	tree[id].combine(tree[left], tree[right]);
}


// range update and  utility functions
void upd(int id,int l,int r,int x){ //	update the current node and its index in the lazy array
	lazy[id] += x;
	tree[id].update((r - l) * x);
}

void shift(int id,int l,int r){ //propogate update information to the children
	if(lazy[id] and l+1 < r){
		int mid = (l+r)/2;
		upd(id * 2, l, mid, lazy[id]);
		upd(id * 2 + 1, mid, r, lazy[id]);
		lazy[id] = 0; // passing is done, reset the index in the lazy array
	}
}

// range update -> update(x, y, val);
void update(int x, int y, int val, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		upd(id, l, r, val);
		return;
	}

	shift(id, l, r); // pass the updates to the children

	int left = id<<1, right = left+1, mid = (l+r)>>1;

	update(x, y, val, left, l, mid);
	update(x, y, val, right, mid, r);

	tree[id].combine(tree[left], tree[right]);
	return;
}

// range query -> query(x, y);
// for point query, traverse like in point update
int query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y) return tree[id].cnt;

	shift(id, l, r);	//use this with lazy propogation

	int left = id<<1, right = left+1, mid = (l+r)>>1;

	return query(x, y, left, l, mid) + query(x, y, right, mid, r);
}

int main(){
	return 0;
