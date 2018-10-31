/*
This program implements a segTree to enable Range Queries and Update
Queries. The prop of segTree is the function that implements the property i.e
sum, minimum, gcd etc,. The def is the default value e.g 0 for sum and INT_MAX
for minimum.
*/

#include<iostream>
#include<math.h>
#include<limits>
using namespace std;

class SegTree{
	int *tree, leaf, (*prop)(int, int), def, size;

	void update(int rt, int st, int ed, int pos, int val);
	int rangeQuery(int rt, int st, int ed, int l, int r);
	void construct(int *arr, int st, int ed, int curr);


	int parent(int i){
		return (i-1)/2;
	}

	int left(int i){
		return 2*i + 1;
	}

	int right(int i){
		return 2*i + 2;
	}

public:

	SegTree(int *arr, int d, int n, int (*f)(int, int));
	int rangeQuery(int l, int r);
	void update(int pos, int val);
	void print(int rt = 0, int ind = 0);
};

SegTree::SegTree(int *arr, int d, int n, int (*f)(int, int)){
	size = n;
	leaf = pow(2, ceil(log2(size)));
	tree = new int[2*leaf - 1]; //Can also be approximated to 4n
	prop = f;
	def = d;

	construct(arr, 0, leaf, 0);
}

void SegTree::construct(int *arr, int st, int ed, int curr){
	if(st + 1 == ed){
		tree[curr] = (st < size) ? arr[st] : def;
		return;
	}

	int mid = (st+ed)/2;

	construct(arr, st, mid, left(curr));
	construct(arr, mid, ed, right(curr));

	tree[curr] = prop(tree[left(curr)], tree[right(curr)]);
}

//Returns query result from [l, r)
//Wrapper function for rangeQuery(int rt, int st, int ed, int l, int r)
int SegTree::rangeQuery(int l, int r){
	return rangeQuery(0, 0, leaf, l, r);
}

int SegTree::rangeQuery(int rt, int st, int ed, int l, int r){
	if(l >= ed || r <= st){
		return def;
	}

	if(l <= st && r >= ed){
		return tree[rt];
	}

	int mid = (st + ed)/2;
	return prop(
		rangeQuery(left(rt), st, mid, l, r),
		rangeQuery(right(rt), mid, ed, l, r)
	);
}

//Wrapper for update(int rt, int st, int ed, int pos, int val)
void SegTree::update(int pos, int val){
	update(0, 0, leaf, pos, val);
}

void SegTree::update(int rt, int st, int ed, int pos, int val){
	if(pos == st && st+1 == ed){
		tree[rt] = val;
		return;
	}

	int mid = (st+ed)/2;

	if(mid > pos){
		update(left(rt), st, mid, pos, val);
	}
	else{
		update(right(rt), mid, ed, pos, val);
	}

	tree[rt] = prop(tree[left(rt)], tree[right(rt)]);
}

void SegTree::print(int rt, int ind){
	if(rt >= 2*leaf - 1){
		return;
	}

	for(int i = 0; i < ind; ++i){
		cout<<"\t";
	}

	cout<<tree[rt]<<endl;
	print(left(rt), ind + 1);
	print(right(rt), ind + 1);
}

//Tester code

int min(int a, int b){
	return (a<b) ? a : b;
}

int main(){
	int a[] = {1, 3, 5, 7, 9, 11, 3, -11};
	int n = sizeof(a)/sizeof(int);

	SegTree s(a, 100, n, min);
	s.update(2, -10);
	s.print();
	return 0;
}
