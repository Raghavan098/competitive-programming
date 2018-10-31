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

int n,m;

int main(){
  cin>>n>>m;
  if(n>1 and m>1){
    if(n%2==0){
      cout<<0<<endl;
      cout<<1<<" "<<1<<endl;
      for(int i=2;i<=n;i++){
        if(i%2==0){
          for(int j=1;j<m;j++){
            cout<<i<<" "<<j<<endl;
          }
        }
        else{
          for(int j=m-1;j>=1;j--){
            cout<<i<<" "<<j<<endl;
          }
        }
      }
      for(int i=n;i>=1;i--){
        cout<<i<<" "<<m<<endl;
      }
      for(int i=m-1;i>=1;i--){
        cout<<1<<" "<<i<<endl;
      }
    }
    else if(m%2==0){
      cout<<0<<endl;
      cout<<1<<" "<<1<<endl;
      for(int j=1;j<m;j++){
        if(j%2==1){
          for(int i=2;i<=n;i++){
            cout<<i<<" "<<j<<endl;
          }
        }
        else{
          for(int i=n;i>=2;i--){
            cout<<i<<" "<<j<<endl;
          }
        }

      }
      for(int i=n;i>=1;i--){
        cout<<i<<" "<<m<<endl;
      }
      for(int i=m-1;i>=1;i--){
        cout<<1<<" "<<i<<endl;
      }
    }
    else{
      cout<<1<<endl;
      cout<<n<<" "<<m<<" "<<1<<" "<<1<<" "<<endl;
      for(int i=1;i<=n;i++){
        if(i%2==1){
          for(int j=1;j<=m;j++){
            cout<<i<<" "<<j<<endl;
          }
        }
        else{
          for(int j=m;j>=1;j--){
            cout<<i<<" "<<j<<endl;
          }
        }
      }
      cout<<1<<" "<<1<<endl;
    }
  }
  else{
    if(n==1 and m==2){
      cout<<0<<endl;
      cout<<1<<" "<<1<<endl;
      cout<<1<<" "<<2<<endl;
      cout<<1<<" "<<1<<endl;
    }
    else if(m==1 and n==2){
      cout<<0<<endl;
      cout<<1<<" "<<1<<endl;
      cout<<2<<" "<<1<<endl;
      cout<<1<<" "<<1<<endl;
    }
    else if(n==1){
      cout<<1<<endl;
      cout<<1<<" "<<m<<" "<<1<<" "<<1<<endl;
      for(int i=1;i<=m;i++){
        cout<<1<<" "<<i<<endl;
      }
      cout<<1<<" "<<1<<endl;
    }
    else{
      cout<<1<<endl;
      cout<<n<<" "<<1<<" "<<1<<" "<<1<<endl;
      for(int i=1;i<=n;i++){
        cout<<i<<" "<<1<<endl;
      }
      cout<<1<<" "<<1<<endl;
    }
  }
  return 0;
}
