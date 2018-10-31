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
char temp;

bool check(int i1,int j1,int i2,int j2){
  int tot = (i2 - i1 +1)*(j2 - j1 +1);
  // tr(tot,(cumu[i2][j2]), cumu[i1-1][j1-1] , cumu[i1-1][j2] , cumu[i1][j1-1]);
  if((cumu[i2][j2] + cumu[i1-1][j1-1] - cumu[i1-1][j2] - cumu[i2][j1-1])==tot){
    return true;
  }
  return false;
}

int main(){
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>temp;
      arr[i][j] = temp - '0';
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cumu[i][j] = arr[i][j] + cumu[i-1][j] + cumu[i][j-1] - cumu[i-1][j-1];
    }
  }
  // for(int i=1;i<=n;i++){
  //   for(int j=1;j<=m;j++){
  //     cout<<cumu[i][j]<<" ";
  //   }cout<<endl;
  // }
  int tot_max = 0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      pair<int,int> l,r,mid,ans,ans1,ans2;
      int mx = 0;
      if(arr[i][j]==1){
        if(i>=j){
          l = mp(i-j+1,1);
        }
        else{
          l = mp(1,j-i+1);
        }
        r = mp(i,j);
        // tr(l,r);
        while(l.fi<=r.fi){
          mid = mp((l.fi+r.fi)/2,(l.se+r.se)/2);
          // tr(mid);
          if(check(mid.fi,mid.se,i,j)){
            ans = mid;
            r = mp(mid.fi-1,mid.se-1);
          }
          else{
            l = mp(mid.fi+1,mid.se+1);
          }
        }
        // tr(ans);
        l = mp(i,1);
        r = ans;
        while(l.se<=r.se){
          mid = mp(l.fi,(l.se+r.se)/2);
          if(check(mid.fi,mid.se,i,j)){
            ans1 = mid;
            r = mp(mid.fi,mid.se-1);
          }
          else{
            l = mp(mid.fi,mid.se+1);
          }
        }
        // tr(ans1);
        mx = (i - ans1.fi +1)*(j - ans1.se +1);
        l = mp(1,j);
        r = ans;
        while(l.fi<=r.fi){
          mid = mp((l.fi+r.fi)/2,l.se);
          // tr(mid);
          if(check(mid.fi,mid.se,i,j)){
            ans1 = mid;
            r = mp(mid.fi-1,mid.se);
          }
          else{
            l = mp(mid.fi+1,mid.se);
          }
        }
        // tr(ans1);
        mx = max(mx,(i - ans1.fi +1)*(j - ans1.se +1));
        tot_max = max(tot_max,mx);
      }
    }
  }
  cout<<tot_max<<endl;
  return 0;
}
