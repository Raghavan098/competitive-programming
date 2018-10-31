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

struct slope{
  int x,y;
};

int n;
int arr[2000];

bool check(slope s){
  int ck[2000] = {0};
  int x,y;
  // tr(s.x,s.y);
  ck[0] = 1;
  for(int i=0;i<1;i++){
    for(int j=i+1;j<n;j++){
      y = arr[j] - arr[i];
      x = j - i;
      if(s.y*x==y*s.x){
        ck[i] = 1;
        ck[j] = 1;
      }
    }
  }
  int coun = 0;
  for(int i=0;i<n;i++){
    if(ck[i]==0){
      coun++;
    }
  }
  // tr(coun);
  if(coun==0 or coun==n){
    return false;
  }
  for(int i=0;i<n;i++){
    if(ck[i]==0){
      for(int j=i+1;j<n;j++){
        if(ck[j]==0){
          y = arr[j] - arr[i];
          x = j - i;
          // tr(x,y);
          if(s.y*x!=y*s.x){
            return false;
          }
        }
      }
    }
  }
  return true;
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  slope s1,s2,s3;
  s1.x = 1;
  s1.y = arr[1]-arr[0];
  s2.x = 2;
  s2.y = arr[2]-arr[0];
  if((arr[2]-arr[0])%2==0){
    s2.y/=2;
    s2.x/=2;
  }
  s3.x = 1;
  s3.y = arr[2]-arr[1];
  // tr(s1.x,s1.y,s2.x,s2.y,s3.x,s3.y);
  if(check(s1)){
    cout<<"Yes\n";
    return 0;
  }
  if(check(s2)){
    cout<<"Yes\n";
    return 0;
  }
  if(check(s3)){
    cout<<"Yes\n";
    return 0;
  }
  cout<<"No\n";
  return 0;
}
