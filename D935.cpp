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

ll n,m;
ll s1[200000];
ll s2[200000];
ll p,q,ans;
ll z_s1[200000],z_s2[200000];

const ll M = 1e9 + 7;

ll pow(ll a, ll p) {
	if (!p) return 1;
	ll ret = pow(a, p >> 1);
	ret = (ret * ret) % M;
	if (p & 1LL) ret = (ret * a) % M;
	return ret;
}


ll modular_inverse(ll p,ll q){
  ll den = pow(q, M - 2);
  ll ans = (p*den)%M;
  while(ans<0){
    ans+=M;
  }
  return ans;
}

ll get_p(){
  for(int i=n-1;i>=0;i--){
    z_s1[i] = z_s1[i+1] + (s1[i]==0);
    z_s2[i] = z_s2[i+1] + (s2[i]==0);
  }
  int done = 0;
  ll ans =0;
  ll temp,temp2;
  ll states = 1LL;
  for(int i=0;i<n;i++){
    if(s1[i]==0 and s2[i]!=0){
      temp = m - s2[i];
      temp2 = (pow(m,z_s1[i+1]+z_s2[i+1]))%M;
      ans+=(((temp*temp2)%M)*states);
      done=1;
      ans%=M;
    }
    else if(s1[i]!=0 and s2[i]==0 ){
      temp = s1[i] -1LL;
      temp2 = pow(m,z_s1[i+1]+z_s2[i+1])%M;
      ans+=(((temp*temp2)%M)*states);
      ans%=M;
    }
    else if(s1[i]!=0 and s2[i]!=0){
      if(s1[i]>s2[i]){
        temp = 1LL;
        temp2 = pow(m,z_s1[i+1]+z_s2[i+1])%M;
        ans+=(((temp*temp2)%M)*states);
        ans%=M;
        break;
      }
      else if(s2[i]>s1[i]){
        break;
      }
    }
    else{
      temp2 = ((m*(m-1LL))/2LL)%M;
      temp = (pow(m,z_s1[i+1]+z_s2[i+1]));
      temp*=states;
      temp%=M;
      ans= (ans+temp*temp2)%M;
      states*=m;
      states%=M;
    }
  }
  return ans;
}

ll get_q(){
  return pow(m,z_s1[0]+z_s2[0]);
}


int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>s1[i];
  }
  for(int i=0;i<n;i++){
    cin>>s2[i];
  }
  p = get_p();
  q = get_q();
  cout<<modular_inverse(p,q)<<endl;
  return 0;
}
