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

string s;

int arr[200000][2];

int main(){
  cin>>s;
  arr[0][0] = (s[0]=='B');
  arr[0][1] = (s[0]=='R');
  for(int i=1;i<s.size();i++){
    arr[i][0]=arr[i-1][0]+(s[i]=='B');
    arr[i][1]=arr[i-1][1]+(s[i]=='R');
  }
  int temp;
  int a,b;
  a = 0;
  b = 0;
  int j1 = -1;
  int j2 = -1;
  int ans1= -INT_MAX;
  int ans2 = -INT_MAX;
  // tr(ans1,ans2);
  pair<int,int> p1,p2;
  for(int i=0;i<s.size();i++){
    temp = arr[i][1] - arr[i][0] + a;
    // tr(temp,i,a,b);
    if(temp>ans1){
      ans1 = temp;
      p1 = mp(i+1,j1+2);
    }
    temp = arr[i][0] - arr[i][1] + b;
    // tr(temp);
    if(temp>ans2){
      ans2 = temp;
      p2 = mp(i+1,j2+2);
    }
    if(arr[i][0]- arr[i][1] > a){
      a = arr[i][0] - arr[i][1];
      j1 = i;
    }
    if(arr[i][1]- arr[i][0] > b){
      b = arr[i][1] - arr[i][0];
      j2 = i;
    }
  }
  if(ans1>ans2){
    cout<<p1.se<<" "<<p1.fi<<endl;
  }
  else if(ans2>ans1){
    cout<<p2.se<<" "<<p2.fi<<endl;
  }
  else{
    if(p1.se<p2.se){
      cout<<p1.se<<" "<<p1.fi<<endl;
    }
    else if(p1.se>p2.se){
      cout<<p2.se<<" "<<p2.fi<<endl;
    }
    else if(p1.fi<p2.fi){
      cout<<p1.se<<" "<<p1.fi<<endl;
    }
    else{
      cout<<p2.se<<" "<<p2.fi<<endl;
    }
  }
  return 0;
}
