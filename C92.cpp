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

string s1,s2;
set<char> s;
int arr[40000][30];

int main(){
  cin>>s1;
  cin>>s2;
  int n = s1.size();
  for(int i=0;i<s1.size();i++){
    s.insert(s1[i]);
  }
  for(int i=0;i<s2.size();i++){
    if(s.find(s2[i])==s.end()){
      cout<<-1<<endl;
      return 0;
    }
  }
  s1 = s1+s1;
  for(int i=s1.size()-2;i>=0;i--){
    for(int j=0;j<30;j++){

      arr[i][j] = arr[i+1][j];
    }
    char let = s1[i+1];
    arr[i][let - 'a'] = (i+1)%n;
    // tr(i,let - 'a',i%n);
    // tr(arr[i][let-'a']);
  }
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<26;j++){
  //     cout<<arr[i][j]<<" ";
  //   }cout<<endl;
  // }
  int ans = 1;
  int curp = arr[n-1][s2[0]-'a'];
  int temp;
  // tr(curp);
  for(int i=1;i<s2.size();i++){
    temp = arr[curp][s2[i]-'a'];
    if(temp<=curp){
      ans++;
      curp = temp;
    }
    else{
      curp = temp;
    }
  }
  cout<<ans<<endl;
}
