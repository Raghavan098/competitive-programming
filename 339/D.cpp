#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
const int N = 1 << 17;
using namespace std;

int n,m,n1;
int arr[1<<17];

struct node{
  int cnt;
  void assign(int value){
    cnt = value;
  }
  void combine(node &left,node &right){
    cnt = left.cnt^right.cnt;
  }
};

int a[N];
node tree[2*N];


void build(int id = 1,int l =0,int r =n){
  if(l+1==r){
    tree[id].assign(a[l]);
    return;
  }
  int left = id<<1,right = left+1,mid = (l+r)>>1;
  build(left,l,mid);
  build(right,mid,r);
  tree[id].combine(tree[left],tree[right]);
  return;

}

void update(int index,int val,int id = 1,int l = 0,int r = n){
  if(l+1==r){
    tree[id].assign(val);
    return;
  }
  int left = id<<1,right = left+1,mid = (l+r)>>1;
  if(index<mid){
    update(index,val,left,l,mid);
  }
  else{
    update(index,val,right,mid,r);
  }
  tree[id].combine(tree[left],tree[right]);
}

int query(int x,int y,int id = 1,int l = 0,int r = n){
  if(x>=r or l>=y){
    return 0;
  }
  if(x<=l and r<=y){
    return tree[id].cnt;
  }

  int left = id<<1,right = left+1,mid = (l+r)>>1;
  return query(x,y,left,l,mid)^query(x,y,right,mid,r);
}

int main(){ _
  cin>>n1>>m;
  for(int i=0;i<(1<<n1);i++){
    cin>>arr[i];
  }
  for(int i = 0;i<(1<<n1)/2;i++){
    a[i] = arr[i*2]|arr[i*2+1];
  }
  build();
  int x,y,z;
  for(int i = 0;i<m;i++){
    cin>>x>>y;
    arr[x-1] = y;
    if(x%2==0){
      z = x-1;
    }
    else{
      z = x+1;
    }
    update(x/2,arr[x-1]|arr[z-1]);
    cout<<query(0,n)<<endl;
  }
  return 0;
}
