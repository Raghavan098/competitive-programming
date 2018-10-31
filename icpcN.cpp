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


int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    map<int,int> ct;
    cin>>n;
    int no;
    for(int i=0;i<n;i++){
      cin>>no;
      if(ct.find(no)==ct.end()){
        ct[no] = 1;
      }
      else{
        ct[no]++;
      }
    }
    pair<int,int> temp;
    int poll = -1;
    no =-1;

    for(map<int,int> :: iterator it = ct.begin();it!=ct.end();it++){
      temp = *it;
      if(temp.se>poll){
        poll  = temp.se;
        no = temp.fi;
      }
      else if(temp.se==poll and no>temp.fi){
        no = temp.fi;
      }
    }
    cout<<no<<endl;
  }
  return 0;
}
