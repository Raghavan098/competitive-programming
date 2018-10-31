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

int n,m,s,f,cur_hol,pass,to_pass,cp;
char curr,temp;
ll t,x,y,arr[100010][3];;

int main(){
  cin>>n>>m>>s>>f;
  cur_hol = s;
  if((f-s)>0)curr = 'R',pass = 1;
  else curr = 'L',pass = -1;
  to_pass = cur_hol+pass;
  for(int i=0;i<m;i++){
    for(int j=0;j<3;j++){
      cin>>arr[i][j];
    }
  }
  cp = 0;
  for(int i=1;;i++){
    // tr(arr[cp][0],arr[cp][1],arr[cp][2],i,cur_hol,to_pass,arr[cp][0]==i && ((arr[cp][1]<=cur_hol and arr[cp][2]>=cur_hol) || (arr[cp][1]<=to_pass and arr[cp][2]>=to_pass)));
    if(arr[cp][0]==i && ((arr[cp][1]<=cur_hol and arr[cp][2]>=cur_hol) || (arr[cp][1]<=to_pass and arr[cp][2]>=to_pass))){
      cout<<'X';
      cp++;
    }
    else if(arr[cp][0]==i){
      cp++;
      cout<<curr;
      cur_hol = to_pass;
      to_pass = cur_hol+pass;
    }
    else{
      cout<<curr;
      cur_hol = to_pass;
      to_pass = cur_hol+pass;
    }
    if(cur_hol==f){
      break;
    }
  }
  return 0;
}
