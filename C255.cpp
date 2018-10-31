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
int arr[5000];
unordered_map<int,int> mp;
int cnt[2000000];

int main(){ 
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    cnt[arr[i]]++;
  }
  int final_ans = -1;
  for(int i=0;i<n;i++){
    int a = arr[i];
    mp.clear();
    int ans[4001];
    MEMS(ans,0);
    ans[i] = 1;
    int mx = 0;
    int last = i;
    int u;
    int mx_ti= -1;
    for(int j= i+1;j<n;j++){
      if(arr[j]==a){
        ans[j] = mx+1;
        last = j;
      }
      else{
        if(mp.find(arr[j])==mp.end()){
          ans[j] = 2;
          mp[arr[j]] = j;
          mx = max(mx,ans[j]);
        }
        else{
          u = mp[arr[j]];
          if(last>u){
            ans[j] = ans[u]+2;
          }
          else{
            ans[j] = ans[u];
          }
          mp[arr[j]] = j;
          mx = max(mx,ans[j]);
        }
      }
      if(ans[j]>mx_ti){
        mx_ti = ans[j];
      }
    }
    final_ans = max(final_ans,mx_ti);
  }
  int lol = -1;
  for(int i=1;i<=1000000;i++){
    lol = max(lol,cnt[i]);
  }
  if(lol>final_ans){
    cout<<lol<<endl;
    return 0;
  }
  cout<<final_ans<<endl;
}
