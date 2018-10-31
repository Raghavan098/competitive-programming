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

int n1,n2,v1;
string s1,s2,v;
int jump[200][30];

void get(){
  for(int i=0;i<v1;i++){
    for(int j = 0;j<26;j++){
      char temp = 'A' + j;
      int go = i+1;
      while(go>0){
        int flag = false;
        if(go>0 and v[go-1]!=temp){
          go--;
          continue;
        }
        for(int k=0;k<go-1;k++){
          if(v[go -2  -k]!=v[i - 1- k]){
            flag = true;
            break;
          }
        }
        if(flag==false){
          break;
        }
        go--;
      }
      jump[i][j] = go;
    }
  }
}

int dp[101][101][101];
int from[101][101][101];

string solve(){

  // for(int i=0;i<v1;i++){
  //   for(int j=0;j<26;j++){
  //     cout<<jump[i][j]<<" ";
  //   }cout<<endl;
  // }

  for(int i=0;i<=n1;i++){
    for(int j=0;j<=n2;j++){
      for(int k=0;k<=v1;k++){
        dp[i][j][k] = -1;
      }
    }
  }
  dp[0][0][0] = 0;
  for(int i=0;i<=n1;i++){
    for(int j=0;j<=n2;j++){
      for(int k=0;k<v1;k++){
        // if(dp[i][j][k]==-1){
        //   continue;
        // }
        if(i<n1 and dp[i][j][k]>dp[i+1][j][k]){
          dp[i+1][j][k] = dp[i][j][k];
          from[i+1][j][k] = -1;
        }
        if(j<n2 and dp[i][j][k]>dp[i][j+1][k]){
          dp[i][j+1][k] = dp[i][j][k];
          from[i][j+1][k] = -2;
        }
        if(i<n1 and j<n2 and s1[i]==s2[j]){
          int temp = jump[k][s1[i] - 'A'];
          if(temp<v1 and dp[i+1][j+1][temp]<(dp[i][j][k] + 1)){
            dp[i+1][j+1][temp] = dp[i][j][k] + 1;
            from[i+1][j+1][temp] = k;
          }
        }
      }
    }
  }
  int mx = 0;
  int prev = 0;
  for(int i=0;i<=v1;i++){
    if(dp[n1][n2][i]>mx){
      mx = dp[n1][n2][i];
      prev = i;
    }
  }
  // tr(mx,prev);
  if(mx==0){
    return "0";
  }
  string ans = "";
  for(int i=n1,j=n2;i>0 and j>0;){
    int val = from[i][j][prev];
    if(val==-1){
      i--;
    }
    if(val==-2){
      j--;
    }
    if(val>=0){
      i--;
      j--;
      ans = s1[i] + ans;
      prev = val;
    }
  }
  return ans;
}


int main(){
  cin>>s1>>s2>>v;
  n1 = s1.size();
  n2 = s2.size();
  v1 = v.size();
  get(); // for getting the k value if s1[i] and s2[j] matches
  cout<<solve()<<endl;
  return 0;
}
