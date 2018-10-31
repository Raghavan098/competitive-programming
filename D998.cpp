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

ll n;

int main(){
  /*
  let us first fill with n with all 1's. Now some one's can be replaced with 5,10,50 so the total changes will be +0 or +4 or +9 or +49
  so now the problem reduces to adding 0,4,9,49 to some of these ones. ie filling with (0,4,9,49)
  We need to find (x, y, z) such that x + y + z ≤ n, while counting those (x, y, z) only which result in distinct values of 49 × x + 9 × y + 4 × z.
  Let's count only tuples (x, y, z) with highest values of x, y, z in the order x then y then z.
  1. If z ≥ 9, we can always replace atleast 9 4s with 4 9s, therefore z is restricted to z < 9. Note that for z < 9, we can also never replace z no. of 4s with any number of 49s or with any combination of 49s and 9s.

  2. If y ≥ 49, we can always replace atleast 49 9s with 9 49s, therefore y is restricted to y < 49.

  3. If y ≥ 9, we can always replace atleast 9 9s with 1 49 and 8 4s, therefore y gets further restricted to y < 9.

  4. If simultaneously y ≥ 5 and z ≥ 1, we can always replace atleast 5 9s and 1 1 with 1 49, therefore (y, z) gets further restricted to

    {(0-4,0-8)} U {(5-8,0)}
  let the remaining places after filling with y and z be p
  now the remaining places can be filled with 0 - p x's

  */
  cin>>n;
  ll ans = 0;
  for(ll y = (ll)0;y<=min(n,ll(4));y++){       // 1st  part
    for(ll z = (ll)0;z<=min(n-y,ll(8));z++){
      ans += n - y - z + 1LL;
    }
  }
  for(ll y = 5LL;y <= min(n,8LL);y++){       // second part
    ans += n - y + 1LL;
  }
  cout<<ans<<endl;
}
