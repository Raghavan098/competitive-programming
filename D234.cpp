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

int m,k,n;
set<int> fav;
map<int,vector<int> > inp;
map<int,pair<int,int> >cnt;

void get_cnt(){

  for(int i=0;i<n;i++){
    pair<int,int> tt;
    tt.fi =  0;
    tt.se = 0;
    set<int> temp_fav;
    for(auto it:fav){
      temp_fav.insert(it);
    }
    if(inp[i].size()==m){
      tt.fi = fav.size();
      tt.se = fav.size();
      cnt[i] = tt;
      continue;
    }
    int zeros = 0;
    int w = 0;
    for(auto j:inp[i]){
      if(temp_fav.find(j)!=temp_fav.end()){
        tt.fi++;
        temp_fav.erase(j);
      }
      else if(j==0){
        zeros++;
      }
      else{
        w++;
      }
    }
    if(zeros>(m - w - fav.size())){
      int kk;
      kk=min((zeros - (m -w - (int)fav.size())),(int)temp_fav.size());
      tt.fi+=kk;
      zeros-=kk;
    }
    tt.se = tt.fi + min(zeros,(int)fav.size() - tt.fi);
    cnt[i] = tt;
  }
}

int main(){
  cin>>m>>k;
  for(int i=0;i<k;i++){
    int temp;
    cin>>temp;
    fav.insert(temp);
  }
  cin>>n;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    int temp;
    cin>>temp;
    for(int j=0;j<temp;j++){
      int t2;
      cin>>t2;
      inp[i].pb(t2);
    }
  }
  get_cnt();
  for(auto i:cnt){
    // tr(i);
    int mx_mi = -1;
    int mx_mx = -1;
    for(auto j: cnt){
      if(j.fi!=i.fi){
        if(j.se.fi>mx_mi){
          mx_mi = j.se.fi;
        }
        if(j.se.se>mx_mx){
          mx_mx = j.se.se;
        }
      }
    }
    if(i.se.fi>=mx_mx){
      cout<<0<<endl;
      continue;
    }
    if(i.se.se>=mx_mi){
      cout<<2<<endl;
      continue;
    }
    if(i.se.se<mx_mi){
      cout<<1<<endl;
      continue;
    }
  }
  return 0;
}
