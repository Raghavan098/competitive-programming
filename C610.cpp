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


int n;
int p;
int matrix[1000][1000];

int main(){
  cin>>n;
  p= pow(2,n);
  matrix[1][1] = 1;
  matrix[2][1] = -1;
  for(int i=0;i<=8;i++){
    p = pow(2,i);
    for(int j=1;j<=p;j++){
      for(int k=1;k<=p;k++){
        matrix[j][p+k] = matrix[j][k];
      }
    }
    for(int j=1;j<=p;j++){
      for(int k=1;k<=p;k++){
        matrix[p+j][k] = matrix[j][k];
      }
    }
    for(int j=1;j<=p;j++){
      for(int k=1;k<=p;k++){
        matrix[p+j][p+k] = -matrix[j][k];
      }
    }
  }
  p = pow(2,n);
  for(int i=1;i<=p;i++){
    for(int j=1;j<=p;j++){
      if(matrix[i][j]==1){
        cout<<"+";
      }
      else{
        cout<<"*";
      }
    }
    cout<<endl;
  }
  return 0;
}
