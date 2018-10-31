#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
#define mp make_pair
#define endl "\n"
using namespace std;

int n,m,q1;
int a,b;
char inp[2000][2000];
int visited[2000][2000];
int ans[2000][2000];
queue<pair<int,int> > q;
void do_bfs(int a,int b){
  q.push(mp(a-1,b-1));
  pair<int,int> p;
  ans[a-1][b-1] = 0;
  visited[a-1][b-1] = 1;
  int ti,tj;
  while(!q.empty()){
    p = q.front();
    q.pop();
    ti = p.first;
    tj = p.second;
    if(ti+1<n and visited[ti+1][tj]!=1 and inp[ti+1][tj]!='*'){
      q.push(mp(ti+1,tj));
      ans[ti+1][tj] = ans[ti][tj]+1;
      visited[ti+1][tj]= 1;
    }
    if(ti-1>=0  and visited[ti-1][tj]!=1 and inp[ti-1][tj]!='*'){
      q.push(mp(ti-1,tj));
      ans[ti-1][tj] = ans[ti][tj]+1;
      visited[ti-1][tj]= 1;
    }
    if(tj+1<m and visited[ti][tj+1]!=1 and inp[ti][tj+1]!='*'){
      q.push(mp(ti,tj+1));
      ans[ti][tj+1] = ans[ti][tj]+1;
      visited[ti][tj+1]= 1;
    }
    if(tj-1>=0 and visited[ti][tj-1]!=1 and inp[ti][tj-1]!='*'){
      q.push(mp(ti,tj-1));
      ans[ti][tj-1] = ans[ti][tj]+1;
      visited[ti][tj-1]= 1;
    }
  }
}

int main(){
  cin>>n>>m>>q1;
  int a1,b1;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>inp[i][j];
      visited[i][j]=0;
    }
  }
  cin>>a>>b;
  do_bfs(a,b);

  for(int i=0;i<q1;i++){
    cin>>a1>>b1;
    if(ans[a1-1][b1-1]!=0)
      cout<<ans[a1-1][b1-1]<<endl;
    else if(a1==a and b1==b){
      cout<<0<<endl;
    }
    else{
      cout<<-1<<endl;
    }
  }
  return 0;
}
