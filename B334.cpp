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

map<int,int> x,y;
set<int> sx,sy;
set<pair<int,int> > tot;

int main(){
  int a,b;
  for(int i=0;i<8;i++){
    cin>>a>>b;
    sx.insert(a);
    sy.insert(b);
    tot.insert(mp(a,b));
  }
  if(sx.size()==3 and sy.size()==3){
    int cur1 =1,cur2 = 1;

    for(set<int> :: iterator it1 = sx.begin();it1!=sx.end();it1++,cur1++){
      for(set<int> :: iterator it2 = sy.begin();it2!=sy.end();it2++,cur2++){
        a = *it1;
        b = *it2;
        if(cur1==2 and cur2==2){
          if(tot.find(mp(a,b))!=tot.end()){
            cout<<"ugly\n";
            return 0;
          }
        }
        else if(tot.find(mp(a,b))==tot.end()){
          cout<<"ugly\n";
          return 0;
        }
      }
      cur2 = 1;
    }
  }
  else{
    cout<<"ugly\n";
    return 0;
  }
  cout<<"respectable\n";
  return 0;
}
