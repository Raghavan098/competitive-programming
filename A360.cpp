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
#define _ ios_base::sync_with_stdio(false);cin.tie(NUint);cout.tie(NUint);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

#define siz 17

int n,m;
map<int,int> mp;
int v[5001][5001];
// ti,li,ri,(d,max)
bool cmp(vector<int> &v1,vector<int> &v2){
  if(v1[0]==0){
    return false;
  }
  return v1[3]>v2[3];
}

int main(){
  cin>>n>>m;
  vector<vector<int> > inp(m,vector<int>(5));
  // vector<vector<int> > v(n,vector<int>(n));
  for(int i=0;i<m;i++){
    cin>>inp[i][0]>>inp[i][1]>>inp[i][2]>>inp[i][3];
    inp[i][4] = i;
  }
  int curr = 1;
  for(int i=0;i<m;i++){
    if(inp[i][0]==1){
      for(int j=0;j<n;j++){
        v[curr][j] = v[curr-1][j];
      }
      for(int j=inp[i][1]-1;j<=inp[i][2]-1;j++){
        v[curr][j]+=inp[i][3];
      }
      curr++;
    }
    else{
      mp[i] = curr;
    }
  }
  sort(inp.begin(),inp.end(),cmp);
  cout<<endl;
  int final_ans[n];
  for(int i=0;i<n;i++){
    final_ans[i] = 1000000000;
  }
  int temp,ind;
  for(int i=0;i<m;i++){
    if(inp[i][0]==2){
      temp = inp[i][3];
      ind = inp[i][4];
      for(int j=inp[i][1]-1;j<=inp[i][2]-1;j++){
        if(final_ans[j]+v[mp[ind]-1][j]>temp){
          final_ans[j] = temp - v[mp[ind]-1][j];
        }
      }
    }
  }
  int mx;
  for(int i=0;i<m;i++){
    if(inp[i][0]==2){
      temp = inp[i][3];
      ind = inp[i][4];
      mx = -1000000001;
      for(int j=inp[i][1]-1;j<=inp[i][2]-1;j++){
        if(final_ans[j]+v[mp[ind]-1][j]>mx){
          mx = final_ans[j]+v[mp[ind]-1][j];
        }
      }
      if(mx!=temp){
        cout<<"NO\n";
        return 0;
      }
    }
  }
  cout<<"YES\n";
  for(int i=0;i<n;i++){
    cout<<final_ans[i]<<" ";
  }cout<<endl;
  return 0;
}
