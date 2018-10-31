// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
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
ld eps = 1e-10;
int s;
int a,b,c;
ld ans = -inf;
ld ansx,ansy,ansz;

ld fuc2(ld x,ld y,ld z){
  ld as = a*log(x) + b*log(y) + c*log(z);
  // tr(x,y,z,as);
  if(as>ans){
    ansx = x;
    ansy = y;
    ansz = z;
  }
  return as;
}


ld f(ld s_m){
  // tr(s_m);
  ld left = s - s_m;
  ld l = eps;
  ld r = left - eps;
  ld as = -inf;
  while (r - l > eps) {
    ld m1 = l + (r - l) / 3;
    ld m2 = r - (r - l) / 3;
    ld f1 = fuc2(m1,left - m1,s_m);
    ld f2 = fuc2(m2,left - m2,s_m);
    // tr(f1,f2);
    if (f1 >= f2)
      r = m2;
    else
      l = m1;
    as = max(as,max(f1,f2));
  }
  return as;
}

ld slove1(ld l, ld r) {
  while (r - l > eps) {
    ld m1 = l + (r - l) / 3;
    ld m2 = r - (r - l) / 3;
    ld f1 = f(m1);
    ld f2 = f(m2);
    // printf("%0.12Lf %0.12Lf\n",f1,f2);
    if (f1 >= f2)
      r = m2;
    else
      l = m1;
  }
}


int main(){
  cin>>s;
  cin>>a>>b>>c;
  if(a+b+c==0){
    cout<<"0 0 0\n";
    return 0;
  }
  else if(a==b and b==c){
    ansx = s/3.0;
    ansy = s/3.0;
    ansz = s/3.0;
  }
  else{
    slove1(eps,s - eps);
  }
  printf("%0.12Lf %0.12Lf %0.12Lf\n",ansx,ansy,ansz);
}
