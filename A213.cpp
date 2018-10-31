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

int n,temp1,temp2;
map<int,vector<int> > grp;
int c[500];
int req[500],req2[500];

int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>c[i];
  }
  for(int i=1;i<=n;i++){
    cin>>temp1;
    req[i] = temp1;
    req2[i] = temp1;
    for(int j=0;j<temp1;j++){
      cin>>temp2;
      grp[temp2].pb(i);
    }
  }
  int ans = 99999999;
  for(int i=1;i<=3;i++){
    int cur = i;
    stack<int> s[4];
    for(int i=1;i<=n;i++){
      req[i] = req2[i];
    }
    for(int i=1;i<=n;i++){
      if(req[i]==0){
        s[c[i]].push(i);
      }
    }
    if(s[cur].empty()){
      continue;
    }
    int total = n;
    int moves = -1;
    int x,y;
    // tr(cur);
    while(total){
      moves++;
      while(!s[cur].empty()){
        x = s[cur].top();
        s[cur].pop();
        total-=1;
        moves++;
        // tr(x,cur,moves,total);
        for(int j=0;j<grp[x].size();j++){
          y = grp[x][j];
          req[y]--;
          if(req[y]==0){
            s[c[y]].push(y);
          }
        }
      }
      cur+=1;
      if(cur==4){
        cur=1;
      }
    }
    ans = min(moves,ans);
  }
  cout<<ans<<endl;
  return 0;
}
