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

int n;
int arr[200001];
int pre[2000000];
int ans[200001];
int maxele;
int done[1000001];
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    pre[arr[i]] = arr[i];
    maxele = max(maxele,arr[i]);
  }
  int present_ele = 0;
  for(int i=0;i<= 2*maxele;i++){
    if(pre[i]!=0){
      present_ele = i;
    }
    else{
      pre[i] = present_ele;
    }
  }
  int max_this;
  for(int i=0;i<n;i++){
    present_ele = arr[i];
    max_this = 0;
    if(present_ele!=1 and done[present_ele]==0){
      for(int j =present_ele*2;j<2*maxele;j+=present_ele){
        max_this = max(max_this,pre[j-1]%present_ele);
      }
      ans[i] = max_this;
      done[present_ele] = 1;
    }
  }
  int final_ans = 0;
  for(int i=0;i<n;i++){
    final_ans = max(final_ans,ans[i]);
  }
  cout<<final_ans<<endl;
  return 0;
}
