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

#define MAXN 400000
#define LOG 25

int n;
int arr[400000];
vector<pair<pair<int,int> ,int> > ans;
int st[MAXN][LOG];

void pre_process(){
  for(int i=0;i<n;i++){
    st[i][0] = arr[i];
  }
  for(int j=1;j<LOG;j++){
    for(int i=0;i + (1<<j) <= n;i++){
      st[i][j] = __gcd(st[i][j-1],st[i+(1 <<(j-1))][j-1]);
    }
  }
}

int query(int a,int b){
  int k = log2(b-a+1);
  return __gcd(st[a][k],st[b - (1<<k) +1][k]);
}


int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  pre_process();
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<4;j++){
  //     cout<<st[i][j]<<" ";
  //   }cout<<endl;
  // }
  for(int i=0;i<n;i++){
    int l = 0;
    int r = i;
    int mid;
    int al;
    while(l<=r){
      mid = (l + r)/2;
      if(query(mid,i)%arr[i]==0){
        al = mid;
        r = mid - 1;
      }
      else{
        l = mid + 1;
      }
    }

    l = i;
    r = n-1;
    int ar;
    while(l<=r){
      mid = (l+r)/2;
      if(query(i,mid)%arr[i]==0){
        ar = mid;
        l = mid + 1;
      }
      else{
        r = mid - 1;
      }
    }
    // tr(al,ar,i,arr[i]);
    ans.pb(mp(mp(ar - al + 1,al),i));
  }
  sort(ans.begin(),ans.end());
  reverse(ans.begin(),ans.end());
  // cout<<ans<<endl;
  set<int>final_ans;
  int mm = ans[0].fi.fi;
  for(int i=0;i<n;i++){
    if(ans[i].fi.fi==mm){
      final_ans.insert(ans[i].fi.se);
    }
    else{
      break;
    }
  }
  cout<<final_ans.size()<<" "<<ans[0].fi.fi-1<<endl;
  for(auto i: final_ans){
    cout<<i+1<<" ";
  }cout<<endl;
  // for(int i=0;i<n;i++){
  //   cout<<ans[i]<<" ";
  // }cout<<endl;

  return 0;
}
