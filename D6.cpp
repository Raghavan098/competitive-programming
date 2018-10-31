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
#define MEMS(a,b) memset(a,b,sizeof(a))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define inf 1000000000000000001

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

int n,a,b,h[300];
int temp[300];
vector<int> res;
int final_ans;
int temp_cost = 99999999;
vector<int> v;

void dfs(int curp,int cost){
  // tr(curp,cost,v);

  if(cost>temp_cost)return;

  if(curp==n-1){
    if(cost<temp_cost and h[curp]<0){
      temp_cost = cost;
      res = v;
    }
    return;
  }
  // tr(a,b);
  // tr(max((h[curp-1]/b +1),max((h[curp]/a + 1),(h[curp+1]/b +1))));
  int prev = v.size();
  for(int i=0;i<=max((h[curp-1]/b +1),max((h[curp]/a + 1),(h[curp+1]/b +1)));i++){
    if(i>0)
      v.pb(curp + 1);
    // tr(v,i,curp);
    if((h[curp - 1] - i*b)<0){
      // tr("asdf");
      h[curp-1] -= i*b;
      h[curp] -= i*a;
      h[curp + 1] -= i*b;
      // for(int j=0;j<i;j++){
      //   v.pb(curp + 1);
      // }
      dfs(curp + 1,cost +i);
      // for(int j=0;j<i;j++){
      //   v.pop_back();
      // }
      h[curp-1] += i*b;
      h[curp] += i*a;
      h[curp + 1] += i*b;
    }
    // v.pop_back();
  }
  while(v.size()>prev){
    v.pop_back();
  }
  // v.pop_back();
}

int main(){ _
  cin>>n>>a>>b;
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  dfs(1,0);
  printf("%d\n",temp_cost);
  for(auto i:res){
    printf("%d ",i);
  }printf("\n");
  return 0;
}
