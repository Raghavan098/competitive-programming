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

int n,m,arr[5000][4],ans[2000];

int main(){
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    cin>>arr[i][1]>>arr[i][0]>>arr[i][2];
    arr[i][3] = i;
    ans[arr[i][0]]=m+1;
  }
  int a,b,c,d;
  for(int i=1;i<=m;i++){
    for(int j=i+1;j<=m;j++){
      if(arr[i][0]>arr[j][0]){
        a = arr[i][0];
        b = arr[i][1];
        c = arr[i][2];
        d = arr[i][3];
        arr[i][0] = arr[j][0];
        arr[i][1] = arr[j][1];
        arr[i][2] = arr[j][2];
        arr[i][3] = arr[j][3];
        arr[j][0] = a;
        arr[j][1] = b;
        arr[j][2] = c;
        arr[j][3] = d;
      }
    }
  }
  for(int j=1;j<=m;j++){
    int ct = arr[j][2];
    // tr(arr[j][1],arr[j][0],arr[j][2]);
    for(int i=arr[j][1];i<=arr[j][0];i++){
      if(ans[i]==0 and ct>0){
        ans[i] = arr[j][3];;
        ct--;
      }
    }
    if(ct>0){
      cout<<-1<<endl;
      return 0;
    }
  }
  for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
  }cout<<endl;
}
