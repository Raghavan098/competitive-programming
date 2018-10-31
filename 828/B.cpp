// g++ -std=c++14
#include<bits/stdc++.h>
typedef long long int lli;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int main(){
  _
  int n,m;
  cin >> n >> m;
  vector<string>arr(n);
  int flg = 0;
  vector<pair<int,int> >ind(4);
  for(int i=0;i<n;i++){
    cin >> arr[i];
    for(int j=0;j<m;j++){
      if(arr[i][j]=='B'){
        for(int k=0;k<4;k++){
          ind[k] = mp(i,j);
        }
        flg++;
      }
    }
  }
  if(flg==0){
    cout << "1\n";
    return 0;
  }
  if(flg==1){
    cout << "0\n";
    return 0;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]=='B'){
        if(j<ind[0].se){
          ind[0] = mp(i,j);
        }
        if(j>ind[1].se){
          ind[1] = mp(i,j);
        }
        if(i<ind[2].fi){
          ind[2] = mp(i,j);
        }
        if(i>ind[3].fi){
          ind[3] = mp(i,j);
        }
      }
    }
  }
  // cout << ind[1].se << " " << ind[0].se << "\n";
  // cout << ind[3].fi << " " << ind[2].fi << "\n";
  int len = max(ind[1].se-ind[0].se,ind[3].fi-ind[2].fi)+1;
  if(len>n or len>m){
    cout << "-1\n";
    return 0;
  }
  int ans = 0;
  for(int i=ind[2].fi;i<=ind[3].fi;i++){
    for(int j=ind[0].se;j<=ind[1].se;j++){
      if(arr[i][j]=='W'){
        ans++;
      }
    }
  }
  if(ind[1].se-ind[0].se<ind[3].fi-ind[2].fi){
    ans+= len*(ind[3].fi-ind[2].fi-(ind[1].se-ind[0].se));
  }
  if(ind[1].se-ind[0].se>ind[3].fi-ind[2].fi){
    ans+= len*((ind[1].se-ind[0].se)-(ind[3].fi-ind[2].fi));
  }
  cout << ans << "\n";
  return 0;
}
