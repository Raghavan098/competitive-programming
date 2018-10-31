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

int n;
vector<vector<int> > arr,row;

void swapc(int c1,int c2){
  vector<int> temp(n);
  for(int i=0;i<n;i++){
    temp[i] = arr[i][c1];
  }
  for(int i=0;i<n;i++){
    arr[i][c1] = arr[i][c2];
  }
  for(int i=0;i<n;i++){
    arr[i][c2] = temp[i];
  }
}

void swapr(int r1,int r2){
  swap(arr[r1],arr[r2]);
}
void swaprr(int r1,int r2){
  swap(row[r1],row[r2]);
}

int main(){
  cin>>n;
  arr.resize(n,vector<int>(n));
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    arr[a][b] = 1;
  }
  int col[2000];
  MEMS(col,0);
  for(int j=0;j<n;j++){
    for(int i=0;i<n;i++){
      col[j]+=arr[i][j];
    }
  }
  vector<pair<int,int> > ans;
  for(int i=0;i<n;i++){
    int mx = -1;
    int mi;
    for(int j=i;j<n;j++){
      if(col[j]>mx){
        mx = col[j];
        mi = j;
      }
    }
    if(mi!=i){
      swapc(i,mi);
      swap(col[i],col[mi]);
      ans.pb(mp(i,mi));
    }
  }
  row.resize(n,vector<int>(n));
  for(int i=0;i<n;i++){
    row[i][n-1] += arr[i][n-1];
  }
  for(int i=0;i<n;i++){
    for(int j=n-2;j>=0;j--){
      row[i][j] = row[i][j+1] + arr[i][j];
    }
  }
  vector<pair<int,int> > ans2;
  for(int j=0;j<n;j++){
    for(int i=j+1;i<n;i++){
      if(row[i][j]==0){
        swapr(i,j);
        swaprr(i,j);
        ans2.pb(mp(i,j));
        break;
      }
    }
  }
  cout<<ans.size() + ans2.size()<<endl;
  for(auto i:ans){
    cout<<2<<" "<<i.fi+1<<" "<<i.se+1<<endl;
  }
  for(auto i:ans2){
    cout<<1<<" "<<i.fi+1<<" "<<i.se+1<<endl;
  }
  return 0;
}
