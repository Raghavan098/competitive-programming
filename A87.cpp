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

ll a,b;

int main(){
  cin>>a>>b;
  ll lc = (a*b/(__gcd(a,b)));
  ll i = a;
  ll j = b;
  ll pre_time = 0;
  ll cur_time = min(a,b);
  if(i<j){
    i+=a;
  }
  else{
    j+=b;
  }
  ll tot_a = 0,tot_b = 0;
  // tr(lc);
  while(true){
    // tr(cur_time,pre_time,i,j,tot_a,tot_b);
    if(cur_time%a==0){
      tot_a += cur_time - pre_time;
    }
    else if(cur_time%b==0){
      tot_b += cur_time - pre_time;
    }
    pre_time = cur_time;
    if(i<j){
      cur_time = i;
      i+=a;
    }
    else{
      cur_time = j;
      j+=b;
    }
    if(cur_time%a==0 and cur_time%b==0){
      // tr(cur_time,pre_time);
      if(a>b){
        tot_a += cur_time - pre_time;
      }
      else{
        tot_b += cur_time - pre_time;
      }
      break;
    }
  }
  // tr(tot_a,tot_b);
  if(tot_b<tot_a){
    cout<<"Dasha"<<endl;
  }
  else if(tot_a<tot_b){
    cout<<"Masha"<<endl;
  }
  else{
    cout<<"Equal"<<endl;
  }
  return 0;
}
