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

struct node{
  int a;
  string s[15];
  int k[15];
  int start[15];
};

int n,m,k1;
node arr[200][200];

int main(){
  cin>>n>>m>>k1;
  k1++;
  for(int i=0;i<n;i++){
    string temp;
    cin>>temp;
    for(int j=0;j<m;j++){
      int x = temp[j] - '0';
      arr[i][j].a = x;
      arr[i][j].k[0] = -1;
      for(int z = 0;z<=k1;z++){
        arr[i][j].s[z] = "";
        arr[i][j].k[z] = -1;
      }
      for(int z=0;z<k1;z++){
        if(x%k1==z){
          arr[i][j].k[z] = x;
          arr[i][j].start[z] = j+1;
        }
      }
    }
  }
  for(int i=n-2;i>=0;i--){
    for(int j = 0;j<m;j++){
      int a = arr[i][j].a;
      for(int z = 0;z<=k1;z++){
        arr[i][j].k[z] = -1;
        arr[i][j].s[z] = "";
        arr[i][j].start[z] = 0;
      }
      // tr(a);
      if(j-1>=0){
        for(int z=0;z<k1;z++){
          if(arr[i+1][j-1].k[z]!=-1){
            int b = arr[i+1][j-1].k[z] + a;
            // tr(b,a);
            for(int q = 0;q<k1;q++){
              if(b%k1==q and arr[i][j].k[q]<b){
                arr[i][j].k[q] = b;
                arr[i][j].s[q] = arr[i+1][j-1].s[z] + 'R';
                arr[i][j].start[q] = arr[i+1][j-1].start[z];
              }
            }
          }
        }
      }
      if(j+1<m){
        for(int z=0;z<k1;z++){
          if(arr[i+1][j+1].k[z]!=-1){
            int b = arr[i+1][j+1].k[z] + a;
            // tr(b,a);
            for(int q = 0;q<k1;q++){
              if(b%k1==q and arr[i][j].k[q]<b){
                arr[i][j].k[q] = b;
                arr[i][j].s[q] = arr[i+1][j+1].s[z] + 'L';
                arr[i][j].start[q] = arr[i+1][j+1].start[z];
              }
            }
          }
        }
      }
      // for(int rr = 0;rr<=k1;rr++){
      //   tr(arr[i][j].k[rr],arr[i][j].s[rr]);
      // }
    }
  }
  int ans = -1,stt;
  string ans_s;
  for(int i=0;i<m;i++){
    if(arr[0][i].k[0]>ans){
      ans = arr[0][i].k[0];
      ans_s = arr[0][i].s[0];
      stt = arr[0][i].start[0];
    }
  }
  if(ans!=-1){
    cout<<ans<<endl;
    cout<<stt<<endl;
    cout<<ans_s<<endl;
  }
  else{
    cout<<-1<<endl;
  }
  return 0;
}
