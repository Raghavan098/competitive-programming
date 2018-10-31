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

string s;
ll dp[100][20];

bool check(){
  ll curr = 0;
  for(ll i=0;i<s.size();i++){
    if(s[i]-'0'<curr){
      return false;
    }
    else{
      curr = s[i]-'0';
    }
  }
  return true;
}

void get_value(ll s,ll len){

  for(ll i= s;i<=9;i++){
    dp[1][i] = 1;
  }
  // cout<<"adsf"<<endl;
  for(ll i=2;i<len;i++){
    for(ll j=s;j<=9;j++){
      ll ans1 = 0;
      for(ll k = s;k<=j;k++){
        ans1+=dp[i-1][k];
      }
      dp[i][j] = ans1;
      // tr(dp[i][j],i,j);
    }
  }
}

ll get_value2(ll s,ll len){
  if(len==1){
    return 10 - s;
  }
  ll final_ans = 0;
  for(ll i=1;i<=10-s;i++){
    final_ans+=dp[len][i];
  }
  // for(ll i=s;i<=9;i++){
  //   final_ans+=dp[len][i];
  // }
  return final_ans;
}

ll solve(){
  cin>>s;
  if(!check()){
    cout<<-1<<endl;
    return 0;
  }
  ll length = s.size();
  ll final_ans = 0;
  for(ll i=1;i<length;i++){
    // tr(i,get_value2(1,i));
    final_ans+=get_value2(1,i);
  }
  // tr(final_ans);
  // tr(get_value2(7,2));
  ll curr = 1;
  ll prev = 1;
  for(ll i=1;i<length;i++){
    curr = s[i-1]-'0';
    for(ll j=prev;j<curr;j++){
      // tr(i,j,length - i,get_value(j,length-i));
      final_ans+=get_value2(j,length - i);
    }
    prev = curr;
  }
  // tr(final_ans);
  for(ll i=curr;i<s[length-1]-'0';i++){
    final_ans+=1;
  }
  cout<<final_ans+1<<endl;
}

int main(){
  ll t;
  cin>>t;
  // cout<<"adfaD"<<endl;
  get_value(1,90);
  while(t--){
    solve();
  }
}
