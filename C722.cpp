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

ll n,a[100010],b[100010],sum,cumu[100010],s,sum1,sum2,l1,u1;
multiset<ll> :: iterator l,u;
multiset<ll> s1,s2;

ll get(ll l,ll u){
  if(l<=0){
    return cumu[u];
  }
  else{
    // tr(cumu[l-1],cumu[u]);
    return cumu[u] - cumu[l-1];
  }
}

int main(){
  cin>>n;
  sum=0;
  for(ll i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
    cumu[i+1]=sum;
  }
  cumu[n+1] = cumu[n];
  for(ll i=0;i<n;i++){
    cin>>b[i];
    b[i]--;
  }
  s1.insert(-1);
  s1.insert(n);
  s2.insert(sum);
  // set<ll> :: iterator temp;
  // temp = s1.lower_bound(2);
  // temp--;
  // tr(*temp);
  for(ll i=0;i<n;i++){
    l = s1.lower_bound(b[i]);
    u = s1.upper_bound(b[i]);
    l--;
    l1 = *l;
    u1 = *(u);
    s = cumu[u1] - cumu[l1+1];
    s2.erase(s2.find(s));
    sum1 = cumu[u1] - cumu[b[i]+1];
    sum2 = cumu[b[i]] - cumu[l1+1];
    // tr(s,l1,u1,sum1,sum2,b[i]);
    s1.insert(b[i]);
    s2.insert(sum1);
    s2.insert(sum2);
    cout<<*s2.rbegin()<<endl;
  }
  return 0;
}
