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

int n,k;
vector<int> q,s,pre;
bool cmp(vector<int> r){
  for(int i=0;i<n;i++){
    if(r[i]!=s[i]){
      return false;
    }
  }
  return true;
}

void apply(){
  vector<int> temp(n);
  for(int i=0;i<n;i++){
    temp[i] = pre[q[i]-1];
  }
  pre = temp;
}

void apply_rev(){
  vector<int> temp(n);
  for(int i=0;i<n;i++){
    temp[q[i]-1] = pre[i];
  }
  pre = temp;
}

int main(){ _
  cin>>n>>k;
  q.resize(n);
  s.resize(n);
  pre.resize(n);
  for(int i=0;i<n;i++){
    cin>>q[i];
  }
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  // if(k>=n){
  //   cout<<"NO\n";
  //   return 0;
  // }
  for(int i=0;i<n;i++){
    pre[i] = i+1;
  }
  if(cmp(pre)){
    cout<<"NO\n";
    return 0;
  }
  int f = -1,b = -1;
  for(int i=0;i<k;i++){
    apply();
    // tr(pre);
    if(cmp(pre)){
      f = i+1;
      break;
    }
  }
  for(int i=0;i<n;i++){
    pre[i] = i+1;
  }
  for(int i=0;i<k;i++){
    apply_rev();
    // tr(pre);
    if(cmp(pre)){
      b = i+1;
      break;
    }
  }
  // tr(f,b);
  if(f==-1 and b==-1){
    cout<<"NO\n";
    return 0;
  }
  if((f==1 and b==1)){
    if(k==1){
      cout<<"YES\n";
      return 0;
    }
    else{
      cout<<"NO\n";
      return 0;
    }
  }
  if(f!=-1){
    if((k-f)%2==0){
      cout<<"YES\n";
      return 0;
    }
  }
  if(b!=-1){
    if((k - b)%2==0){
      cout<<"YES\n";
      return 0;
    }
  }
  cout<<"NO\n";
  return 0;
}
