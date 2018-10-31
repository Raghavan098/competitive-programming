#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
typedef long long int lli;
using namespace std;
const int N = 4*100100;
vector<vector<lli> >gr;
lli n,m;
vector<lli> start;
vector<pair<lli,lli> > arr;
vector<lli> brr,vis;
vector<lli>ind;
int tree[N];
int A[N];

void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        A[idx] = val;
        tree[node] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}
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
		A[i+1]=arr[i].second;
	}
  build(1,1,arr.size());
	// for(i=1;i<=n;i++){
	// 	cout<<A[i]<<" ";
	// }cout<<endl;
  // for(i=0;i<n;i++){
	// 	cout<<arr[i].first<<" ";
	// }cout<<endl;
  // for(i=1;i<=n;i++){
	// 	cout<<brr[i]<<" ";
	// }cout<<endl;
  char type;
  int st,va;
	while(m--){
    cin>>type;
    if(type=='U'){
      cin>>st>>va;
      update(1,1,arr.size(),ind[st],va);
    }
    else{
      cin>>st;
      cout<<query(1,1,arr.size(),ind[st],brr[arr[ind[st]-1].first])<<endl;
    }
	}
	return 0;
}
