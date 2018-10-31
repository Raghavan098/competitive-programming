// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

int n,m,k,w;
string inp[2000][200];
vector< pair<int,int> > answer;
int added[2000];
int dist[2000];

int grp[2000][2000];
int parent[2000];
int used_byte;

int add_to_tree(int added_node){
    used_byte += dist[added_node];
    added[added_node] = 1;
    answer.push_back(make_pair(added_node, parent[added_node]));

    // update the distance from each node to the tree.
    // In other words, compare the current distance from the tree to node
    // and the distance from the added_node to node.
    for (int node = 1; node <= k; node++)
        if (! added[node])
            if (grp[node][added_node] < dist[node])
            {
                dist[node] = grp[node][added_node];
                parent[node] = added_node;
            }

}
int find_closest_node_to_tree(){
    // Just iterate every node and find the closest one.
    int closest_node = -1;
    for (int node = 1; node <= k; node ++)
        if (! added[node])
            if (closest_node == -1 || dist[node] < dist[closest_node])
                closest_node = node;

    return closest_node;

}

void get_distance(int a,int b){
  int dist =0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(inp[a][i][j]!=inp[b][i][j]){
        dist++;
      }
    }
  }
  grp[a][b] = dist*w;
  grp[b][a] = dist*w;
}

int main(){ _
  cin>>n>>m>>k>>w;
  for(int i=1;i<=k;i++){
    for(int i1=0;i1<n;i1++){
      cin>>inp[i][i1];
    }
  }
  for(int i=1;i<=k;i++){
    for(int j=1;j<=k;j++){
      get_distance(i,j);
    }
  }
  for(int i=1;i<=k;i++){
    grp[0][i] = n*m;
    grp[i][0] = n*m;
    dist[i] = n*m;
  }
  // Just start from node 0.
    add_to_tree(0);

    // Now the tree only consists of node 0.

    // Add the closest node to tree K times.
    for (int step = 1; step <= k  ; step++)
    {
        int closest_node = find_closest_node_to_tree();
        add_to_tree(closest_node);
    }

    cout << used_byte << endl;

    for (int i = 1; i < answer.size(); i++)
        cout << answer[i].fi<< " " << answer[i].se<< endl;

    return 0;
}
