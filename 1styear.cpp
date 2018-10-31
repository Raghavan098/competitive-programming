#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

const int N = 1 << 17;
int temp;

struct node{
	int ans,lvalue,rvalue,lcount,rcount,ans2,isdef;
  void assign(int val){
    ans = 1;
    ans2 = val;
    lvalue = val;
    rvalue = val;
    lcount = 1;
    rcount = 1;
    isdef = 0;
  }
	void combine(node &left, node &right){
    temp = 0;
    if(left.isdef==1){
      ans = right.ans;
      ans2 = right.ans2;
      rvalue = right.rvalue;
      lvalue = right.lvalue;
      rcount = right.rcount;
      lcount = right.lcount;
      isdef = 0;
      return;
    }
    else if(right.isdef==1){
      isdef = 0;
      ans = left.ans;
      ans2 = left.ans2;
      rvalue = left.rvalue;
      lvalue = left.lvalue;
      rcount = left.rcount;
      lcount = left.lcount;
      return;
    }
    if(left.rvalue==right.lvalue){
      temp = left.rcount+right.lcount;
    }
    else{
      temp = 0;
    }
    rvalue = right.rvalue;
    lvalue = left.lvalue;
    ans = max(max(left.ans,right.ans),temp);
    if(ans==temp){
      ans2 = left.rvalue;
    }
    else if(ans==left.ans){
      ans2 = left.ans2;
    }
    else{
      ans2 = right.ans2;
    }
    if(left.lvalue==left.rvalue && right.lvalue==left.rvalue){
      lcount = left.lcount+right.rcount;
    }
    else{
      lcount = left.lcount;
    }
    if(right.rvalue==right.lvalue && left.rvalue==right.lvalue){
      rcount = right.rcount+left.rcount;
    }
    else{
      rcount= right.rcount;
    }
		// cnt = left.cnt + right.cnt;
	}
};

int n, a[N];
node tree[2*N];
node default1(){
  node temp1;
  int ans,rvalue,lvalue,rcount,lcount,ans2,isdef;
  isdef = 1;
  ans = 0;
  ans2 =-1;
  lvalue = 0;
  rvalue = 0;
  lcount = 0;
  rcount = 0;
  temp1.ans = ans;
  temp1.rvalue = rvalue;
  temp1.lvalue = lvalue;
  temp1.rcount = rcount;
  temp1.lcount = lcount;
  temp1.ans2 = ans2;
  temp1.isdef = 1;
  return temp1;
}
node combi(node left,node right){
  node temp1;
  int ans,rvalue,lvalue,rcount,lcount,ans2,isdef;
  temp = 0;
  if(left.rvalue==right.lvalue){
    temp = left.rcount+right.lcount;
  }
  else{
    temp = 0;
  }
  if(left.isdef==1){
    ans = right.ans;
    ans2 = right.ans2;
    rvalue = right.rvalue;
    lvalue = right.lvalue;
    rcount = right.rcount;
    lcount = right.lcount;
    isdef = 0;
  }
  else if(right.isdef==1){
    isdef = 0;
    ans = left.ans;
    ans2 = left.ans2;
    rvalue = left.rvalue;
    lvalue = left.lvalue;
    rcount = left.rcount;
    lcount = left.lcount;
  }
  rvalue = right.rvalue;
  lvalue = left.lvalue;
  ans = max(max(left.ans,right.ans),temp);
  if(ans==temp){
    ans2 = left.rvalue;
  }
  else if(ans==left.ans){
    ans2 = left.ans2;
  }
  else{
    ans2 = right.ans2;
  }

  if(left.lvalue==left.rvalue && right.lvalue==left.rvalue){
    lcount = left.lcount+right.rcount;
  }
  else{
    lcount = left.lcount;
  }
  if(right.rvalue==right.lvalue && left.rvalue==right.lvalue){
    rcount = right.rcount+left.rcount;
  }
  else{
    rcount= right.rcount;
  }
  if(left.isdef==1){
    ans = right.ans;
    ans2 = right.ans2;
    rvalue = right.rvalue;
    lvalue = right.lvalue;
    rcount = right.rcount;
    lcount = right.lcount;
    isdef = 0;
  }
  else if(right.isdef==1){
    isdef = 0;
    ans = left.ans;
    ans2 = left.ans2;
    rvalue = left.rvalue;
    lvalue = left.lvalue;
    rcount = left.rcount;
    lcount = left.lcount;
  }
  temp1.ans = ans;
  temp1.rvalue = rvalue;
  temp1.lvalue = lvalue;
  temp1.rcount = rcount;
  temp1.lcount = lcount;
  temp1.ans2 = ans2;
  temp1.isdef = 0;
  return temp1;
}
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



// range query -> query(x, y);
// for point query, traverse like in point update
node query(int x, int y, int id = 1, int l = 0, int r = n){
  // cout<<l<<" "<<r<<endl;
	if(x >= r or l >= y) return default1();
	if(x <= l && r <= y){
     return tree[id];
  }

	int left = id<<1, right = left+1, mid = (l+r)>>1;
  // cout<<mid<<endl;
	return combi(query(x, y, left, l, mid) , query(x, y, right, mid, r));
}

int main(){
  int m;
  cin>>n>>m;
  int a1,b;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  build();
  for(int i=0;i<m;i++){
    cin>>a1>>b;
    node tree1 = query(a1-1,b);
    // tr6(tree1.ans,tree1.lvalue,tree1.lcount,tree1.rvalue,tree1.rcount,tree1.ans2);
    cout<<tree1.ans2<<endl;
  }
	return 0;
}
