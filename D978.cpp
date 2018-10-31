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

ll arr[200000],original[200000];
ll n;

bool check(){
  ll d = arr[1] - arr[0];
  // tr(d,arr[0],arr[1]);
  for(ll i=2;i<n;i++){
    // tr(arr[i],arr[i]-arr[i-1]);
    if((arr[i] - arr[i-1])!=d){
      if(arr[i]+1 - arr[i-1]==d){
        arr[i] = arr[i]+1;
      }
      else if(arr[i]-1 - arr[i-1]==d){
        arr[i] = arr[i]-1;
      }
      else{
        return false;
      }
    }
  }
  return true;
}

int main(){
  ll temp;
  cin>>n;
  for(ll i=0;i<n;i++){
    cin>>arr[i];
    original[i] = arr[i];
  }
  ll ct = 300000;
  for(ll i=-1;i<=1;i++){
    for(ll j=-1;j<=1;j++){
      arr[0]+=i;
      arr[1]+=j;
      temp =0;
      // tr(check(),i ,j);
      if(check()==true){
        for(ll i=0;i<n;i++){
          if(arr[i]!=original[i]){
            temp++;
          }
        }
        ct = min(ct,temp);
      }
      for(int i=0;i<n;i++){

        arr[i] = original[i];
      }
    }
  }
  if(ct!=300000)
    cout<<ct<<endl;
  else{
    cout<<-1<<endl;
  }
  return 0;
}
