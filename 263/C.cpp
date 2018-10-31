#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mp make_pair
#define pb push_back
typedef long long llt;
typedef long double lld;
using namespace std;

int n,a,b;
map<int, vector<int> > graph;
vector<int> ans;
int visited[500005];

bool do_dfs(int cur){
  // cout<<"this is cur "<<cur<<endl;
  visited[cur] =1;
  ans.pb(cur);
  int done =0;
  int this_node;
  int count;
  for(int i=0;i<graph[cur].size();i++){
    this_node = graph[cur][i];
    count = 0;
    for(int j=0;j<graph[this_node].size();j++){
      for(int k = 0;k<graph[cur].size();k++){
        if(graph[this_node][j]==graph[cur][k]){
          // cout<<graph[this_node][j]<<endl;
          count++;
        }
      }
    }
    // cout<<count<<" "<<this_node<<"hello"<<endl;
    if(count==2 and visited[this_node]==0){
      done = 1;
      // cout<<this_node<<endl;
      if(do_dfs(this_node)){
        return true;
      }
      else{
        // cout<<"hell"<<this_node<<endl;
        return false;
      }
    }
  }
  if(done==0){
    return false;
  }
  else{
    return true;
  }
}
vector<int> get_remainig(int a,int b,int c){
  vector<int> ans;
  for(int i=1;i<=6;i++){
    if(i!=a and i!=b and i!=c){
      ans.pb(i);
    }
  }
  return ans;
}
bool check(vector<int> ans){
  vector<int > curr;
  for(int i = 2;i<2+6;i++){
    curr.clear();
    curr.pb(ans[i-2]);
    curr.pb(ans[i-1]);
    curr.pb(ans[i+1]);
    curr.pb(ans[i+2]);
    sort(curr.begin(),curr.end());
    sort(graph[ans[i]].begin(),graph[ans[i]].end());
    for(int j=0;j<4;j++){
      if(graph[ans[i]][j]!=curr[j]){
        return false;
      }
    }
  }
  return true;
}
int main(){ _
  cin>>n;
  int count_arr[n+1];
  for(int i=0;i<=n;i++){
    count_arr[i] = 0;
  }
  for(int i=0;i<2*n;i++){
    cin>>a>>b;
    count_arr[a]++;
    count_arr[b]++;
    visited[i/2]=0;
    graph[a].pb(b);
    graph[b].pb(a);
  }
  for(int i=1;i<=n;i++){
    if(count_arr[i]!=4){
      cout<<-1<<endl;
      return 0;
    }
  }
  if(n==5){
    cout<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<endl;
    return 0;
  }
  if(n==6){
    vector<int> ans_for_6,remaining;
    for(int i=0;i<graph[1].size()-1;i++){
      for(int j =i+1;j<graph[1].size();j++){
        remaining = get_remainig(1,graph[1][i],graph[1][j]);
        // for(int w=0;w<3;w++){
        //   cout<<remaining[w]<<" ";
        // }cout<<endl;
        for(int k = 0;k<3;k++){
          for(int k2 =0;k2<3;k2++){
            for(int k3 = 0;k3<3;k3++){
              if(k!=k2 and k!=k3 and k2!=k3){
                ans_for_6.clear();
                ans_for_6.pb(remaining[k2]);
                ans_for_6.pb(remaining[k3]);
                ans_for_6.pb(1);
                ans_for_6.pb(graph[1][i]);
                ans_for_6.pb(graph[1][j]);
                ans_for_6.pb(remaining[k]);
                ans_for_6.pb(remaining[k2]);
                ans_for_6.pb(remaining[k3]);
                ans_for_6.pb(1);
                ans_for_6.pb(graph[1][i]);
                // for(int w=2;w<8;w++){
                //   cout<<ans_for_6[w]<<" ";
                // }cout<<endl;
                if(check(ans_for_6)){
                  for(int q=2;q<6+2;q++){
                    cout<<ans_for_6[q]<<" ";
                  }cout<<endl;
                  return 0;
                }
              }
            }
          }
        }
      }
    }
    cout<<-1<<endl;
    return 0;
  }
  visited[n] = 0;
  do_dfs(1);
  if(ans.size()==n){
    for(int i=0;i<n;i++){
      cout<<ans[i]<<" ";
    }cout<<endl;
  }
  else{
    cout<<-1<<endl;
  }

  return 0;
}
