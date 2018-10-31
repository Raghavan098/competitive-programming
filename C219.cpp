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

int n,k;
char s[600000];

char get(char a,char b){
  if('A'!= a and 'A'!=b){
    return 'A';
  }
  if('B'!= a and 'B'!=b){
    return 'B';
  }
  if('C'!= a and 'C'!=b){
    return 'C';
  }
}

int main(){
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  if(k>=3){
    int ct = 0;
    for(int i=1;i<n-1;i++){
      if(s[i]==s[i-1]){
        s[i] = get(s[i-1],s[i+1]);
        ct++;
      }
    }
    if(s[n-1]==s[n-2]){
      ct++;
      if(s[n-2]!='A'){
        s[n-1] = 'A';
      }
      else{
        s[n-1] = 'B';
      }
    }
    cout<<ct<<endl;
    for(int i=0;i<n;i++){
      cout<<s[i];
    }cout<<endl;
  }
  else{
    char s1[600000],s2[600000];
    for(int i=0;i<n;i++){
      if(i%2==0){
        s1[i] = 'A';
        s2[i] = 'B';
      }
      else{
        s1[i] = 'B';
        s2[i] = 'A';
      }
    }
    int ct1 = 0;
    int ct2 = 0;
    for(int i=0;i<n;i++){
      if(s1[i]!=s[i]){
        ct1++;
      }
      if(s2[i]!=s[i]){
        ct2++;
      }
    }
    if(ct1<ct2){
      cout<<ct1<<endl;
      for(int i=0;i<n;i++){
        cout<<s1[i];
      }cout<<endl;
    }
    else{
      cout<<ct2<<endl;
      for(int i=0;i<n;i++){
        cout<<s2[i];
      }cout<<endl;
    }
  }
  return 0;
}
