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

string s[2000];
int n,m;
int hori[2000][2000];
int vert[2000][2000];
vector<pair<char,int> > inst;

int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  for(int i=0;i<n;i++){
    for(int j=1;j<m;j++){
      if(s[i][j]!='#'){
        hori[i][j] = hori[i][j-1] + 1;
      }
    }
  }
  for(int j=0;j<m;j++){
    for(int i=1;i<n;i++){
      if(s[i][j]!='#'){
        vert[i][j] = vert[i-1][j] + 1;
      }
    }
  }

  vector<pair<int,int> > v;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(s[i][j]>='A' and s[i][j]<='Z'){
        v.pb(mp(i,j));
      }
      if(hori[i][j]==0){
        hori[i][j] = -1;
      }
      if(vert[i][j]==0){
        vert[i][j] = -1;
      }
    }
  }
  int no_inst;
  cin>>no_inst;
  while(no_inst--){
    char a;
    int b;
    cin>>a>>b;
    inst.pb(mp(a,b));
  }
  vector<char> final_ans;
  for(auto pt: v){
    int cur_r = pt.fi;
    int cur_c = pt.se;
    int done = 0;
    // tr(cur_r,cur_c);
    for(auto in: inst){
      if(in.fi=='N'){
        if((cur_r - in.se)>=0 and (vert[cur_r][cur_c] - vert[cur_r - in.se][cur_c])==in.se){
          cur_r -= in.se;
        }
        else{
          done=1;
          break;
        }
      }
      else if(in.fi=='S'){
        if((cur_r + in.se)<n and (vert[cur_r + in.se][cur_c] - vert[cur_r][cur_c])==in.se){
          cur_r+=in.se;
        }
        else{
          done=1;
          break;
        }
      }
      else if(in.fi=='E'){
        if((cur_c + in.se)<m and (hori[cur_r][cur_c + in.se] - hori[cur_r][cur_c])==in.se){
          cur_c += in.se;
        }
        else{
          done=1;
          break;
        }
      }
      else{
        if((cur_c - in.se)>=0 and (hori[cur_r][cur_c] - hori[cur_r][cur_c - in.se])==in.se){
          cur_c -= in.se;
        }
        else{
          done=1;
          break;
        }
      }
    }
    if(done==0){
      final_ans.pb(s[pt.fi][pt.se]);
    }
  }
  if(final_ans.size()>0){
    sort(final_ans.begin(),final_ans.end());
    for(auto c:final_ans){
      cout<<c;
    }cout<<endl;
  }
  else{
    cout<<"no solution\n";
  }
  return 0;
}
