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
char arr[500][500];

int indi[4] = {0,-1,1};
int indj[4] = {-1,1,0};

bool check_row(int k){
  return (k>=0 and k<n);
}
bool check_column(int k){
  return (k>=0 and k<m);
}
bool check_number(int i,int j){
  int x = arr[i][j]-'1'+1;
  for(int k=0;k<3;k++){
    for(int q =0;q<3;q++){
      if(check_row(i+indi[k]) and check_column(j+indj[q])){
        if(arr[i+indi[k]][j+indj[q]]=='*'){
          x--;
        }
      }
    }
  }
  if(x==0){
    return true;
  }
  else{
    return false;
  }
}

bool check_empty(int i,int j){
  for(int k=0;k<3;k++){
    for(int q =0;q<3;q++){
      if(check_row(i+indi[k]) and check_column(j+indj[q])){
        if(arr[i+indi[k]][j+indj[q]]=='*'){
          return false;
        }
      }
    }
  }
  return true;
}


int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>arr[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]>='1' and arr[i][j]<='8'){
        // tr(i,j,check_number(i,j),check_empty(i,j));
        if(!check_number(i,j)){
          cout<<"NO\n";
          return 0;
        };
      }
      else if(arr[i][j]=='.'){
        // tr(i,j,check_number(i,j),check_empty(i,j));
        if(!check_empty(i,j)){
          cout<<"NO\n";
          return 0;
        }
      }
    }
  }
  cout<<"YES\n";
  return 0;
}
