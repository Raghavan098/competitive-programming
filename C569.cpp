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


// https://www.desmos.com/calculator/h4og8taivq -- graph

ll a,b;

ll pi[3000000],rub[3000000];
#define MAXN 2000006
#define maxinum 2000005
int n;
int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

int getFactorization(int x)
{
    vector<int> ret;
    int ans  =0;
    while (x != 1)
    {
        ans++;
        x = x / spf[x];
    }
    return ans;
}

bool pali(int x)
{
    vector <int> dig;
    while(x > 0)
    {
        dig.pb(x%10);
        x/=10;
    }
    int n = dig.size();
    int l = 0,r = n-1;
    while(l <= r)
    {
        if(dig[l] != dig[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

void solve(){
  rub[0]= 1;
  for(int i=1;i<maxinum;i++){
    if(pali(i)){
      rub[i] =1;
    }
  }
  sieve();
  for(int i=2;i<maxinum;i++){
    rub[i] = rub[i]+rub[i-1];
  }

  for(int i=2;i<maxinum;i++){
    if(getFactorization(i)==1){
      pi[i] = 1;
    }
  }
  for(int i=1;i<maxinum;i++){
    pi[i] = pi[i]+pi[i-1];
  }
}

int main(){
  cin>>a>>b;
  ll ans;
  solve();
  for(int i=1;i<=2000000;i++){
    if(b*pi[i]<=a*rub[i]){
      ans = i;
    }
  }
  cout<<ans<<endl;
}
