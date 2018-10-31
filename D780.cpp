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

int n,counter;
set<string> s;
int done[2000];
string words[2000][2],temp,temp2;
string ans[2000];
string f1[2000];
string f2[2000];
int ind[2000];


int main(){
  cin>>n;
  for(int i = 0; i < n; i++){
        string a, b; cin >> a >> b;
        f1[i] = a.substr(0, 3);
        f2[i] = a.substr(0, 2) + b.substr(0, 1);
        // tr(f1[i],f2[i]);
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(f1[i]==f1[j]){
        done[i] = 1;
        done[j] = 1;
      }
    }
  }
  for(int i=0;i<n;i++){
    if(done[i]==1){
      if(s.find(f2[i])!=s.end()){
        cout<<"NO\n";
        return 0;
      }
      else{
        s.insert(f2[i]);
        ans[i] = f2[i];
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(done[j]==1){
        continue;
      }
      else if(s.find(f1[j])!=s.end()){
        done[j]= 1;
        if(s.find(f2[j])!=s.end()){
          cout<<"NO\n";
          return 0;
        }
        else{
          s.insert(f2[j]);
          ans[j] = f2[j];
          break;
        }
      }
    }
  }
  cout<<"YES\n";
  for(int i=0;i<n;i++){
    if(done[i]==1){
      cout<<ans[i]<<endl;
    }
    else{
      cout<<f1[i]<<endl;
    }
  }
  return 0;
}
