#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;
struct node{
  llt to_up,ans_this;
  vector<llt> child;
};
llt n,k,a,b,arr[500000];
map<llt,node> tree;
llt visited[500000];


void do_dfs(llt i){
  vector<llt> ch;
  visited[i]=1;
  if(arr[i]%k==0){
    tree[i].ans_this =1;
    tree[i].to_up = 1;
  }
  else{
    tree[i].ans_this = 0;
    tree[i].to_up = 0;
  }
  llt temp;
  for(llt j=0;j<tree[i].child.size();j++){
    temp = tree[i].child[j];
    if(visited[temp]==0){
      do_dfs(temp);
      ch.push_back(tree[temp].to_up);
    }
  }
  if(arr[i]%k==0){
    sort(ch.begin(),ch.end());
    reverse(ch.begin(),ch.end());
    if(ch.size()==1){
      tree[i].ans_this = 1+ch[0];
      tree[i].to_up = 1+ch[0];
    }
    else if(ch.size()>1){
      tree[i].ans_this = 1+ch[0]+ch[1];
      tree[i].to_up = 1+ch[0];
    }
  }
}

int main(){
  cin>>n>>k;
  for(llt i=1;i<=n;i++){
    cin>>arr[i];
    visited[i] = 0;
  }
  tree[0].to_up = 0;
  tree[0].ans_this = 0;
  for(llt i=0;i<n-1;i++){
    cin>>a>>b;
    tree[a].to_up = 0;
    tree[b].to_up = 0;
    tree[a].ans_this = 0;
    tree[b].ans_this = 0;
    tree[a].child.push_back(b);
    tree[b].child.push_back(a);
  }
  for(llt i=1;i<=n;i++){
    if(visited[i]==0){
      do_dfs(i);
    }
  }
  llt max_ans = -1;
  for(llt i=1;i<=n;i++){
    if(tree[i].ans_this>max_ans){
      max_ans = tree[i].ans_this;
    }
  }
  if(max_ans!=0)
    cout<<max_ans-1<<endl;
  else{
    cout<<0<<endl;
  }
  return 0;
}
