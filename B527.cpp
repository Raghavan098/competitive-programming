// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

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

int n,dist;
string a,b;
map<char,set<char> > mp;

int main(){
  cin>>n;
  dist = 0;
  cin>>a>>b;
  for(int i=0;i<n;i++){
    if(a[i]!=b[i]){
      dist++;
      mp[b[i]].insert(a[i]);
    }
  }
  int x,y;
  for(int i=0;i<n;i++){
    if(a[i]!=b[i]){
      if(mp.find(a[i])!=mp.end()){
        if(mp[a[i]].find(b[i])!=mp[a[i]].end()){
          dist-=2;
          x = i+1;
          for (int j=0;j<n;j++){
            if(b[j]==a[i] and b[i]==a[j] and b[j]!=a[j]){
              y = j+1;
              break;
            }
          }
          cout<<dist<<endl;
          cout<<x<<" "<<y<<endl;
          return 0;
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    if(a[i]!=b[i]){
      if(mp.find(a[i])!=mp.end()){
        dist-=1;
        x = i+1;
        for(int j=0;j<n;j++){
          if(b[j]==a[i] and b[j]!=a[j]){
            y = j+1;
            break;
          }
        }
        cout<<dist<<endl;
        cout<<x<<" "<<y<<endl;
        return 0;
      }
    }
  }
  cout<<dist<<endl;
  cout<<-1<<" "<<-1<<endl;
  // cout<<dist<<endl;
  return 0;
}
