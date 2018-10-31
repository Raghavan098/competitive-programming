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

int n,l,x,y;
int arr[200000];
set<int> s;

int ans1,ans2;
vector<int> lis;

bool check(int no){
  for(int i=0;i<n;i++){
    if(s.find(no+arr[i])!=s.end()){
      ans1 = i;
      return true;
    }
  }
  return false;
}

bool check1(int no){
  for(int i=0;i<n;i++){
    if(s.find(no+arr[i])!=s.end()){
      lis.pb(i);
    }
  }
  if(lis.size()>0){
    return true;
  }
  return false;
}

int main(){
  cin>>n>>l>>x>>y;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    s.insert(arr[i]);
  }
  if(check(x) && check(y)){
    cout<<0<<endl;
    return 0;
  }
  if(check(x)){
    cout<<1<<endl;
    cout<<y<<endl;
    return 0;
  }
  if(check(y)){
    cout<<1<<endl;
    cout<<x<<endl;
    return 0;
  }
  else if(check1(y-x)){
    for(int i=0;i<lis.size();i++){
      ans1 = lis[i];
      if(arr[ans1]-x>0){
        cout<<1<<endl;
        cout<<arr[ans1]-x<<endl;
        return 0;
      }
      else if(arr[ans1]+y<l){
        cout<<1<<endl;
        cout<<arr[ans1]+y<<endl;
        return 0;
      }
    }
  }
  if(check(y+x)){
    cout<<1<<endl;
    cout<<arr[ans1]+x<<endl;
    return 0;
  }
  else{
    cout<<2<<endl;
    cout<<x<<" "<<y<<endl;
  }
  return 0;
}
