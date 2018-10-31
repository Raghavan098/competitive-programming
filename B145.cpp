//  g++ -std=c++14

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

int a1,a2,a3,a4;
string ans;

pair<int,int> check(string ans1 = ans){
  int ca = 0;
  int cb = 0;
  for(auto i:ans1){
    if(i=='4'){
      ca++;
    }
    else{
      cb++;
    }
  }
  return mp(ca,cb);
}
bool try_this(string s){
  auto cnt = check(s);
  int a_rem = a1 - cnt.fi;
  int b_rem = a2 - cnt.se;

  if(cnt.fi>a1 or cnt.se>a2){
    return false;
  }
  string final_ans = "";
  int cur = 0;
  if(a_rem>0 and cnt.fi==0){
    return false;
  }
  if(b_rem>0 and cnt.se==0){
    return false;
  }
  while(s[cur]=='7'){
    cur++;
  }
  int curb = s.size()-1;
  while(s[curb]=='4'){
    curb--;
  }
  for(int i=0;i<s.size();i++){
    final_ans+=s[i];
    if(i==cur){
      for(int j=0;j<a_rem;j++){
        final_ans+='4';
      }
    }
    if(i==curb){
      for(int j=0;j<b_rem;j++){
        final_ans+='7';
      }
    }
  }
  cout<<final_ans<<endl;
  return true;
}
int main(){
  cin>>a1>>a2>>a3>>a4;
  if(abs(a3-a4)>1){
    cout<<-1<<endl;
    return 0;
  }
  ans = "";
  if(a3>a4){
    string temp = "47";
    for(int i=0;i<a3;i++){
      ans+=temp;
    }
  }
  else if(a3<a4){
    string temp = "74";
    for(int i=0;i<a4;i++){
      ans+=temp;
    }
  }
  else{
    string ans1 = "";
    string temp = "47";
    for(int i=0;i<a3;i++){
      ans1+=temp;
    }
    ans1+='4';
    string ans2 = "";
    temp = "74";
    for(int i=0;i<a3;i++){
      ans2+=temp;
    }
    ans2+='7';
    if(!try_this(ans1)){
      if(!try_this(ans2)){
        cout<<-1<<endl;
      }
    }
    return 0;
  }
  auto cnt = check();
  if(cnt.fi>a1 or cnt.se>a2){
    cout<<-1<<endl;
    return 0;
  }
  else{
    int a_rem = a1 - cnt.fi;
    int b_rem = a2 - cnt.se;
    string final_ans = "";
    int cur = 0;
    if(a_rem>0 and cnt.fi==0){
      cout<<-1<<endl;
      return 0;
    }
    if(b_rem>0 and cnt.se==0){
      cout<<-1<<endl;
      return 0;
    }
    while(ans[cur]=='7'){
      cur++;
    }
    int curb = ans.size()-1;
    while(ans[curb]=='4'){
      curb--;
    }
    for(int i=0;i<ans.size();i++){
      final_ans+=ans[i];
      if(i==cur){
        for(int j=0;j<a_rem;j++){
          final_ans+='4';
        }
      }
      if(i==curb){
        for(int j=0;j<b_rem;j++){
          final_ans+='7';
        }
      }
    }
    cout<<final_ans<<endl;
  }
  return 0;
}
