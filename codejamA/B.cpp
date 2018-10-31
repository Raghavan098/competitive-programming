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

ll arr[2000][4],r,b,c,temp[2000],r1,done,mid;

void solve(ll t){
  cin>>r1>>b>>c;
  for(ll i=0;i<c;i++){
    cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
  }
  ll sum =0;
  ll l = 1;
  ll r = 1000000000000000000;
  ll ans;
  ll fin_ans;
  while(l<=r){
    mid = (l+r)/2;
    for(int i=0;i<c;i++){
      temp[i] = max((ll)0,min((mid - arr[i][2])/arr[i][1],arr[i][0]));
    }
    sort(temp,temp+c);
    reverse(temp,temp+c);
    // for(int i=0;i<c;i++){
    //   cout<<temp[i]<<" ";
    // }cout<<endl;
    sum = 0;
    done = 0;
    for(int i=0;i<r1;i++){
      sum+=temp[i];
    }
    // tr(mid,done);
    if(done==0 and sum>=b){
      ans = mid;

      r = mid-1;
    }
    else{
      l = mid+1;
    }
  }
  cout<<"Case #"<<t<<": "<<ans<<endl;
}

int main(){
  int t;
  cin>>t;
  for(ll i=1;i<=t;i++){
    solve(i);
  }
  return 0;
}
