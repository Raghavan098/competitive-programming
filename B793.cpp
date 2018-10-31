// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

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

int n,m,si,sj,visited[2000][2000],ans[2000][2000];
char arr[2000][2000];
map<pair<int,int> ,vector<pair<int,int> > > parent;

int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>arr[i][j];
      if(arr[i][j]=='S'){
        si = i;
        sj = j;
      }
    }
  }
  int i,j;
  queue<pair<int,int> > q;
  pair<int,int> temp,temp2;
  temp = mp(si,sj);
  temp2 = mp(-1,-1);
  int endi=-1,endj=-1;
  parent[temp].pb(temp2);
  visited[si][sj] = 1;
  q.push(mp(si,sj));
  ans[si][sj] = 0;
  while(!q.empty()){
    temp = q.front();
    q.pop();
    if(arr[temp.fi][temp.se]=='T'){
      endi = temp.fi;
      endj = temp.se;
      break;
    }
    for(int i1=-1;i1<=1;i1++){
      for(int j1=-1;j1<=1;j1++){
        if(abs(i1)!=abs(j1)){
          i = i1+temp.fi;
          j = j1+temp.se;
          if(i<n and i>=0 and j<m and j>=0 and (arr[i][j]=='.' or arr[i][j]=='T') and visited[i][j]==0){
            temp2 = mp(i,j);
            q.push(temp2);
            parent[temp2].pb(temp);
            visited[i][j] = 1;
            if(temp.fi==si and temp.se ==sj){
              ans[i][j] = 0;
            }
            else{
              int done = 0;
              for(int g=0;g<parent[temp].size();g++){
                if(parent[temp][g].fi==i || parent[temp][g].se==j){
                  ans[i][j] = ans[temp.fi][temp.se];
                  done=1;
                }
              }
              if(done==0){
                ans[i][j] = ans[temp.fi][temp.se]+1;
              }
            }
          }
          else if(i<n and i>=0 and j<m and j>=0 and (arr[i][j]=='.' or arr[i][j]=='T') and visited[i][j]==1){
            visited[i][j]=2;
            temp2 = mp(i,j);
            parent[temp2].pb(temp);
            if(temp.fi==si and temp.se ==sj){
              ans[i][j] = 0;
            }
            else{
              for(int g=0;g<parent[temp].size();g++){
                if(parent[temp][g].fi==i || parent[temp][g].se==j){
                  ans[i][j] = min(ans[temp.fi][temp.se],ans[i][j]);
                }
              }
            }
          }
        }
      }
    }
  }
  if(endi==-1){
    cout<<"NO\n";
    return 0;
  }
  if(ans[endi][endj]>2){
    cout<<"NO\n";
  }
  else{
    cout<<"YES\n";
  }
  return 0;
}
