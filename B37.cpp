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

int n,mx,reg,p,dmg;
int visited[2000];
int per[2000],damage[2000];
int curh,ans;
vector<pair<int,int> >v;

int main(){
  cin>>n>>mx>>reg;
  for(int i =0;i<n;i++){
    cin>>per[i]>>damage[i];
  }
  curh = mx;
  dmg = 0;
  while(true){
    // tr(curh,dmg);
    curh-=dmg;
    curh = min(mx,curh+reg);

    int found = -1,ind = -1;
    if(curh<=0){
      break;
    }
    for(int i=0;i<n;i++){
      if(visited[i]==0 and curh*100<=per[i]*mx){
        if(damage[i]>found){
          found = damage[i];
          ind = i;
        }
      }
    }
    if(ind!=-1){
      visited[ind] =1;
      dmg+=damage[ind];
      v.pb(mp(ans,ind+1));
    }
    else if(ind==-1 and dmg<=reg){
      cout<<"NO\n"<<endl;
      return 0;
    }
    ans++;
  }
  cout<<"YES\n";
  cout<<ans<<" "<<v.size()<<endl;
  for(int i=0;i<v.size();i++){
    cout<<v[i].fi<<" "<<v[i].se<<endl;
  }
  return 0;
}
