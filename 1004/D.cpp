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

int t;
map<int,int> mp;
vector<int> a;
int b;


bool check(int n,int m,int x,int y){
  vector<int> v;
  v.resize(b+1);
  // tr(a,b);
  for(auto i: a){
    v[i]++;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      int dist = abs(x - i) + abs(y - j);
      if(dist>b){
        return false;
      }
      v[dist]--;
      if(v[dist]<0){
        return false;
      }
    }
  }
  for(auto i:v){
    if(i>0){
      return false;
    }
  }
  return true;
}

int main(){ _
  cin>>t;
  b = -1;
  for(int i=0;i<t;i++){
    int temp;
    cin>>temp;
    a.pb(temp);
    mp[temp]++;
    b = max(temp,b);
  }
  if(t==1 and a[0]==0){
    cout<<1<<" "<<1<<endl;
    cout<<1<<" "<<1<<endl;
    return 0;
  }
  else if(t==1){
    cout<<-1<<endl;
    return 0;
  }
  int st;
  for(auto i:mp){
    if(i.fi!=0 and i.fi*4!=i.se){
      st = i.fi;
      break;
    }
  }

  for(int i = 1;i*i<=t;i++){
    if(t%i==0){
      int x = st;
      int n = t/i;
      int m = i;
      int y = n + m  - b - x;
      bool d = check(n,m,x,y);
      if(d==true){
        cout<<n<<" "<<m<<endl;
        cout<<x<<" "<<y<<endl;
        return 0;
      }
      x = st;
      n = i;
      m = t/i;
      y = n + m  - b - x;
      d = check(n,m,x,y);
      if(d==true){
        cout<<n<<" "<<m<<endl;
        cout<<x<<" "<<y<<endl;
        return 0;
      }
    }
  }
  cout<<-1<<endl;
}
