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

ll n,arr[300000],ans[300000][2],visited[300000][2],cycle[300000][2];
set<pair<ll,ll> > s;
ll dfs(ll no,ll type){
  ll temp;
  if(no==1){
    return -1;
  }
  else if(no<=0 or no>n){
    return 0;
  }
  if(visited[no][type]!=0){
    return ans[no][type];
  }
  ans[no][type] = -1;
  visited[no][type] = 1;
  if(type==0){


    temp = dfs(no - arr[no],1-type);
    if(temp!=-1)
      ans[no][0] = arr[no] + temp;
    else{
      ans[no][0] = -1;
    }
    return ans[no][0];

  }
  else{
    temp =dfs(no + arr[no],1-type);
    if(temp!=-1)
      ans[no][1] = arr[no] + temp;
    else{
      ans[no][1] = -1;
    }
    return ans[no][1];
  }
}


int main(){
  cin>>n;
  for(ll i=2;i<=n;i++){
    cin>>arr[i];
  }
  for(ll i=2;i<=n;i++){

    dfs(i,0);


    dfs(i,1);
  }
  for(ll i=1;i<n;i++){
    if(ans[i+1][0]==-1){
      cout<<-1<<endl;
    }
    else{
      cout<<ans[i+1][0] + i<<endl;
    }
  }
  return 0;
}
