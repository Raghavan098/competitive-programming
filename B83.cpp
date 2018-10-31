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

ll n,k;
vector<pair<ll,ll> >a(100100);
map<ll,ll> ct;
ll tot;
set<ll> st;

int main(){ _
  cin>>n>>k;
  for(ll i=0;i<n;i++){
    ll temp;
    cin>>temp;
    tot+=temp;
    st.insert(temp);
    a[i] = mp(temp,i+1);
    ct[temp]++;
  }
  if(tot<k){
    cout<<-1<<endl;
    return 0;
  }
  else if(tot==k){
    cout<<endl;
    return 0;
  }
  else{

    ll curr = n;
    ll pre = *(st.begin());
    st.erase(st.begin());
    ll p = 0;
    ll cu = 0;
    while(k>=(n*(pre - cu))){
      k-=(n*(pre - cu));
      n-=ct[pre];
      p++;
      cu = pre;
      pre = *(st.begin());
      st.erase(st.begin());
    }
    queue<pair<ll,ll> > ans;
    vector<pair<ll,ll> > temp;
    for(ll i=0;i<curr;i++){
      if(a[i].fi>=pre){
        a[i].fi -= (cu);
        temp.pb(a[i]);
      }
    }
    ll red = k/n;
    for(int i=0;i<temp.size();i++){
      temp[i].fi -= red;
    }
    k-=(red*n);
    for(auto i: temp){
      if(i.fi>0){
        ans.push(i);
      }
    }
    for(ll i=0;i<k;i++){
      auto temp = ans.front();
      ans.pop();
      temp.fi-=1;
      if(temp.fi!=0)
        ans.push(temp);
    }
    vector<ll> final_ans;
    while(!ans.empty()){
      if(ans.front().fi>0)
        final_ans.pb(ans.front().se);
      ans.pop();
    }
    cout<<final_ans<<endl;
    // cout<<ans<<endl;
  }
  return 0;
}
