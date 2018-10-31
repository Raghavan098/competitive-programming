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

int n,m;
char arr[50][50];
char rearr[50][50];
char original[50][50];
char arr_mirr[50][50];
char rev_arr_mirr[50][50];

char rev_original[50][50];
bool check(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(arr[i][j]=='.'){
        return false;
      }
    }
  }
  return true;
}

void correct(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      arr[i][j] = original[i][j];
    }
  }
}

bool recheck(){
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if(rearr[i][j]=='.'){
        return false;
      }
    }
  }
  return true;
}

void recorrect(){
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      rearr[i][j] = rev_original[i][j];
    }
  }
}

void solve(){
  cin>>n>>m;
  int done;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>arr[i][j];
      rearr[m -j+1][i] = arr[i][j];
      original[i][j] = arr[i][j];
      rev_original[m-j+1][i] = rearr[m-j+1][i];
      arr_mirr[i][m-j+1] = arr[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cout<<arr_mirr[i][j];
    }cout<<endl;
  }
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      rev_arr_mirr[i][n-j+1] = rev_arr_mirr[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    done  = 0;
    int j=i+1;
    while(j--){
      for(int k=1;k<=m;k++){
        // tr(i,j,2*i-j+1,k,arr[j][k],arr[2*i-j+1][k],done);
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
    }
    // tr(check());
    if(check()){
      cout<<i<<" "<<1<<" "<<i<<" "<<m<<endl;
      return;
    }
    else{
      correct();
    }
  }
  for(int i=1;i<=m;i++){
    done = 0;
    for(int j=i;j>0;j--){
      for(int k=1;k<=n;k++){
        // tr(i,j,2*i-j+1,k,rearr[j][k],rearr[2*i-j+1][k]);
        if(rearr[j][k]=='.' and rearr[2*i-j+1][k]=='#'){
          rearr[j][k] = '#';
        }
        else if(rearr[j][k]=='#' and rearr[2*i-j+1][k]=='.'){
          rearr[2*i-j+1][k] = '#';
        }
        else if(rearr[j][k]=='#' and rearr[2*i-j+1][k]=='#'){
          done =1 ;
          break;
        }
        else if(rearr[j][k]=='.' and rearr[2*i-j+1][k]=='.'){
          done =1 ;
          break;
        }
      }
      if(done==1){
        break;
      }
    }
    // tr(recheck(),i);
    if(recheck()){
      cout<<1<<" "<<m-i<<" "<<n<<" "<<m-i<<endl;
      return;
    }
    else{
      recorrect();
    }
  }
  for(int i=2;i<=min(n,m);i++){
    done = 0;
    for(int j=1;j<=i;j++){
      for(int k=1;k<m - j+1;k++){
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
    // tr(check(),i);
    if(check()){
      cout<<i<<" "<<1<<" "<<1<<" "<<i<<endl;
      return;
    }
    else{
      correct();
    }

  }
  for(int i=2;i<=min(n,m);i++){
    done = 0;
    for(int j=1;j<=i;j++){
      for(int k=1;k<m - j;k++){
        tr(i,j,k,i-k+1,i-j+1,arr_mirr[j][k],arr_mirr[i-k+1][i-j+1]);
        if(arr_mirr[j][k]=='.' and arr_mirr[i-k+1][i-j+1]=='#'){
          arr_mirr[j][k] = '#';
        }
        else if(arr_mirr[j][k]=='#' and arr_mirr[i-k+1][i-j+1]=='.'){
          arr_mirr[i-k+1][i-j+1] = '#';
        }
        else if(arr_mirr[j][k]=='#' and arr_mirr[i-k+1][i-j+1]=='#' and !(j==i-k+1 and k==i-j+1)){
          done =1;
          break;
        }
        else if(arr_mirr[j][k]=='.' and arr_mirr[i-k+1][i-j+1]=='.'){
          done =1;
          break;
        }
      }
      if(done==1){
        break;
      }
    }
    tr(check(),i);
    if(check()){
      cout<<i<<" "<<1<<" "<<1<<" "<<i<<endl;
      return;
    }
    else{
      correct();
    }

  }



}

int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
