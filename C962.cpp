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

ll no,l;
ll op,temp;

ll get_len(ll no){
  ll c = 0;
  while(no>0){
    no/=10;
    c++;
  }
  return c;
}
ll get_zeros(ll n,ll l){
  ll c = 0;
  while(l--){
    if(n%2==0){
      c++;
    }
    n/=2;
  }
  return c;
}
ll get_number(ll i){
  ll temp = no;
  vector<ll> v;
  ll curr = no%10;
  while(temp){
    if(i%2==1){
      v.pb(curr);
    }
    i/=2;
    temp/=10;
    curr = temp%10;
  }
  ll ans = 0;
  ll sd = 0;
  for(ll i=0;i<v.size();i++){
    ans+=v[i]*pow(10,i);
  }
  for(int i=v.size()-1;i>=0;i--){
    if(v[i]==0){
      op++;
    }else{
      break;
    }
  }
  return ans;
}

int main(){
  cin>>no;
  l= get_len(no);

  ll m = INT_MAX;
  for(ll i = 1;i<pow(2,l);i++){
    op = get_zeros(i,l);
    temp = get_number(i);
    lld s = sqrtl(temp);
    // tr(i,op,temp,s,m);
    if(s==(ll)s and s!=0){
      if(op<m){
        m = op;
      }
    }
  }
  if(m==INT_MAX){
    cout<<-1<<endl;
  }else{
    cout<<m<<endl;
  }
  return 0;
}
