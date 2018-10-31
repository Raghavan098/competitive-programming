// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

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
int x[100000],v[100000];

ld f(ld xi){
  ld maxt = -1.0;
  for(int i=0;i<n;i++){
    maxt = max(maxt,abs(x[i]-xi)/v[i]);
  }
  return maxt;
}

ld ternary_search(ld l, ld r) {
    ld eps = 1e-9;
    while (r - l > eps) {
        ld m1 = l + (r - l) / 3;
        ld m2 = r - (r - l) / 3;
        ld f1 = f(m1);
        ld f2 = f(m2);
        // tr(f1,f2);
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);
}

int main(){
  cin>>n;
  ld maxx = INT_MIN;
  ld minx = INT_MAX;
  for(int i=0;i<n;i++){
    cin>>x[i];
    if(x[i]>maxx){
      maxx = x[i];
    }
    if(x[i]<minx){
      minx = x[i];
    }
  }
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  // tr(maxx,minx,f(maxx),f(minx));
  printf("%.20Lf\n",ternary_search(minx,maxx));
  return 0;
}
