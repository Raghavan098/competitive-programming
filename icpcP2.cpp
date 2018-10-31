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

bool check(vector<vector<char> > arr){
  int n = arr.size();
  int m = arr[0].size();
  // tr(n,m);
  for(int i=1;i<=n-1;i++){
    for(int j=1;j<=m-1;j++){
      if(arr[i][j]=='.'){
        return false;
      }
    }
  }
  return true;
}
void correct(vector<vector<char> > &arr,vector<vector<char> > &ori){
  int n = arr.size();
  int m = arr[0].size();
  for(int i=1;i<=n-1;i++){
    for(int j=1;j<=m-1;j++){
      arr[i][j] = ori[i][j];
    }
  }
}
bool check_horizontal(vector<vector<char> > arr,vector<vector<char> > ori,bool rev){
  int n = arr.size()-1;
  int m = arr[0].size()-1;
  int done = 0;
  // tr(n,m);
  for(int i=1;i<=n/2;i++){
    done  = 0;
    int j=i;
    while(j>0){
      // tr(j);
      for(int k=1;k<=m;k++){
        // tr(i,j,2*i-j+1,k);
        if(arr[j][k]=='.' and arr[i-j+1+i][k]=='#'){
          arr[j][k] = '#';
        }
        else if(arr[j][k]=='#' and arr[i-j+1+i][k]=='.'){
          arr[i-j+1+i][k] = '#';
        }
        else if(arr[j][k]=='#' and arr[i-j+1+i][k]=='#'){
          done = 1;
          break;
        }
        else if(arr[j][k]=='.' and arr[i-j+1+i][k]=='.'){
          done = 1;
          break;
        }
      }
      if(done==1){
        break;
      }
      // tr(done,j);
      j--;
    }
    // tr(check(arr));
    if(check(arr)){
      correct(arr,ori);
      if(!rev)
        cout<<i<<" "<<1<<" "<<i<<" "<<m<<endl;
      else
        cout<<1<<" "<<n-i<<" "<<m<<" "<<n-i<<endl;
      return true;
    }
    else{
      correct(arr,ori);
    }
  }
  return false;
}
bool check45(vector<vector<char> > arr,vector<vector<char> > ori,int orn){
  int n = arr.size()-1;
  int m = arr[0].size()-1;
  int done = 0;
  // tr(n,m);

  // cout<<"Asdf"<<endl;

  for(int i=1;i<=n;i++){
    cout<<arr[i]<<endl;
  }

  for(int i=2;i<=min(n,m);i++){
    done = 0;
    // cout<<arr[2][2]<<endl;
    for(int j=1;j<i;j++){
      for(int k=1;k<i-j+1;k++){
        // tr(i,j,k,i-k+1,i-j+1,arr[j][k],arr[i-k+1][i-j+1]);
        if(arr[j][k]=='.' and arr[i-k+1][i-j+1]=='#'){
          arr[j][k] = '#';
        }
        else if(arr[j][k]=='#' and arr[i-k+1][i-j+1]=='.'){
          arr[i-k+1][i-j+1] = '#';
        }
        else if(arr[j][k]=='#' and arr[i-k+1][i-j+1]=='#' and !(j==i-k+1 and k==i-j+1)){
          done =1;
          break;
        }
        else if(arr[j][k]=='.' and arr[i-k+1][i-j+1]=='.'){
          done =1;
          break;
        }
      }
      if(done==1){
        break;
      }
    }
    if(check(arr) and done==0){
      correct(arr,ori);
      if(orn==0)
        cout<<i<<" "<<1<<" "<<1<<" "<<i<<endl;
      else if(orn==1){
        cout<<1<<" "<<n-i+1<<" "<<i<<" "<<n<<endl;
      }
      else if(orn==2){
        cout<<i<<" "<<m<<" "<<1<<" "<<m-i+1<<endl;
      }
      else{
        cout<<n<<" "<<m-i+1<<" "<<n-i+1<<" "<<m<<endl;
      }
      return true;
    }
    else{
      correct(arr,ori);
    }

  }
  return false;
}
int solve(){
  int n,m;
  cin>>n>>m;
  vector<vector<char> > v(n+1,vector<char>(m+1));
  vector<vector<char> > v2(n+1,vector<char>(m+1));
  vector<vector<char> > v3(m+1,vector<char>(n+1));
  vector<vector<char> > v4(m+1,vector<char>(n+1));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>v[i][j];
      v2[i][j] = v[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      v3[m-j+1][i] = v[i][j];
      v4[m-j+1][i] = v[i][j];
    }
  }

  for(int i=1;i<=m;i++){
    cout<<v3[i]<<endl;
  }
  tr("1");
  if(check_horizontal(v,v2,false)){
    return 0;
  }
  tr("2");
  if(check_horizontal(v3,v4,true)){
    return 0;
  }
  tr("3");
  if(check45(v,v2,0)){
    return 0;
  }
  tr("4");
  if(check45(v3,v4,1)){
    return 0;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      v[i][j] = v2[i][n-j+1];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      v2[i][j] = v[i][j];
    }
  }
  tr("5");
  if(check45(v,v2,2)){
    return 0;
  }
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      v3[i][j] = v4[i][n-j+1];
    }
  }
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      v4[i][j] = v3[i][j];
    }
  }
  tr("6");
  if(check45(v3,v4,3)){
    return 0;
  }
}


int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
