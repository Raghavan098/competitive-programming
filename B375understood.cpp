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

int n,m;
int arr[5003][5003];
int cumu[5003][5003];
char temp[5003];


int main(){
  sd2(n,m);
  for(int i=0;i<n;i++){
    scanf("%s",temp);
    for(int j=0;j<m;j++){
      arr[i][j] = temp[j]=='1';
    }
  }
  for(int i=0;i<n;i++){
    for(int j=m-1;j>=0;j--){
      if(arr[i][j]==1){
        cumu[i][j] = cumu[i][j+1]+1;
      }
      else{
        cumu[i][j] = 0;
      }
    }
  }
  int ans = 0;
  for(int j=0;j<m;j++){
    static int a[5002];
    for(int i=0;i<n;i++){
      a[i] = cumu[i][j];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
      ans = max(ans,a[i]*(n-i));
    }
  }
  printf("%d\n",ans );
  return 0;
}
