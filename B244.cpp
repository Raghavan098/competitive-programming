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

int n;
int get_no(int n,int j,int k,int len){
  int curr = 0;
  int ans = 0;
  for(int i =0;i<len;i++){
    if(n&1<<i){
      ans+=j*(pow(10,curr));
    }
    else{
      ans+=k*(pow(10,curr));
    }
    curr++;
  }
  return ans;
}
int get_val(int n){
  int ct =0;
  while(n){
    ct++;
    n/=10;
  }
  return ct;
}

int get_tru(int i){
  int cu = i%10;
  while(i){
    if(i%10!=cu){
      return 0;

    }
    i/=10;
  }
  return 1;
}

int main(){
  cin>>n;
  int ans =0;
  int temp;
  for(int i=2;i<=9;i++){
    for(int j=0;j<=9;j++){
      for(int k=j+1;k<=9;k++){
        for(int q = 0;q<1<<i;q++){
          temp = get_no(q,j,k,i);
          if(temp<=n and temp!=0 and get_val(temp)==i and get_tru(temp)==0){
            ans++;
          }
        }
      }
    }
    for(int j=1;j<=9;j++){
      if(get_no(0,j,j,i)<=n and get_val(get_no(0,j,j,i))==i){
        ans++;
      }
    }
  }
  if(n==1000000000){
    ans++;
  }
  for(int i=1;i<min(n+1,10);i++){
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}
