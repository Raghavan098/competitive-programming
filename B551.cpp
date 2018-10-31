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

map<char, int> inp,inpb,inpc;
string a,b,c;

int get_number(map<char ,int> test){
  int done = 0;
  int ans =0;
  int sum = 1000000;
  for(char i='a';i<='z';i++){
    if(test[i]){
      sum = min(sum,inp[i]/test[i]);
    }
  }
  return sum;
}

pair<int,int> get_answer(string b,string c){
  inp.clear();
  inpb.clear();
  inpc.clear();
  for(int i=0;i<a.size();i++){
    inp[a[i]]++;
  }
  for(int i=0;i<b.size();i++){
    inpb[b[i]]++;
  }
  for(int i=0;i<c.size();i++){
    inpc[c[i]]++;
  }
  int x = get_number(inpb);
  // tr(x);
  int x1 = 0;
  int y1 = 0;
  for(int i=0;i<=x;i++){
    int res = 1000000;
    for(char j = 'a';j<='z';j++){
      // tr(res,j,inpc[j],i);
      if(inpc[j]){
        res = min(res,((inp[j] - inpb[j]*i))/inpc[j]);
      }
    }
      if(i+res>x1+y1){
        x1 = i;
        y1 = res;
      }
  }
  return mp(x1,y1);
}

int main(){
  cin>>a>>b>>c;
  pair<int,int> temp1,temp2;
  temp1 = get_answer(b,c);
  // tr(te  mp1);
  inp.clear();
  inpb.clear();
  inpc.clear();
  for(int i=0;i<a.size();i++){
    inp[a[i]]++;
  }
  for(int i=0;i<b.size();i++){
    inpb[b[i]]++;
  }
  for(int i=0;i<c.size();i++){
    inpc[c[i]]++;
  }
  for(int i=0;i<temp1.fi;i++){
    cout<<b;
  }
  for(int i=0;i<temp1.se;i++){
    cout<<c;
  }
  for(char i='a';i<='z';i++){
    inp[i]-=inpb[i]*temp1.fi;
  }
  for(char i='a';i<='z';i++){
    inp[i]-=inpc[i]*temp1.se;
  }
  for(char i='a';i<='z';i++){
    for(int j=0;j<inp[i];j++){
      cout<<i;
    }
  }
  cout<<endl;
  return 0;
}
