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

ll arr[100100][30];
ll brr[100100][30];
ll solve(){
  string s;
  cin>>s;
  ll n = s.size();
  MEMS(arr,0);
  ll ans = 0;
  for(ll i=n-1;i>=0;i--){
    arr[i][s[i] - 'a']++;
    for(ll j=0;j<26;j++){
      arr[i][j] += arr[i+1][j];
    }
    for(ll j = s[i]-'a'+1;j<26;j++){
      ans+=arr[i][j];
    }
  }
  MEMS(brr,0);
  brr[0][s[0]-'a']++;
  for(ll i=1;i<n;i++){
    brr[i][s[i]-'a']++;
    for(ll j=0;j<26;j++){
      brr[i][j] += brr[i-1][j];
    }
  }
  ll temp_ans = ans;
  // tr(ans);
  for(ll i=0;i<n;i++){
    ll temp =  temp_ans;
    brr[i][s[i]-'a']--;
    arr[i][s[i]-'a']--;
    for(ll j = 0;j<=(s[i]-'a') - 1;j++){
      temp -= brr[i][j];
    }
    for(ll j = s[i]-'a'+1;j<26;j++){
      temp -= arr[i][j];
    }
    // tr(temp);
    ll temp2 = temp;
    for(ll j=0;j<26;j++){
      for(ll k=0;k<j;k++){
        temp += brr[i][k];
      }
      for(ll k=j+1;k<26;k++){
        temp += arr[i][k];
      }
      // tr(temp,abs((s[i] - 'a')-j));
      ans = min(ans , temp + abs((s[i] - 'a')-j));
      // tr((temp + abs((s[i] - 'a')-j)),ans,j,temp);
      temp = temp2;
    }
    brr[i][s[i]-'a']++;
    arr[i][s[i]-'a']++;
  }
  cout<<ans<<endl;
}

int main(){
  ll t;
  cin>>t;
  for(ll i=0;i<t;i++){
    solve();
  }
}
