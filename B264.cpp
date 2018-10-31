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

#define MAXN 100001
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

set<int> getFactorization(int x)
{
    set<int> ret;
    while (x != 1)
    {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}


int n;
int arr[200000];
unordered_map<int,int> ind;
unordered_map<int,queue<int> > prm;
int ans[200000];
int main(){
  sieve();
  cin>>n;
  set<int>  temp;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    ind[arr[i]] = i;
    temp = getFactorization(arr[i]);
    for(set<int> :: iterator j=temp.begin();j!=temp.end();j++){
      prm[*j].push(arr[i]);
    }
  }
  for(int i=0;i<n;i++){
    ans[i] = 1;
  }
  int tt,ti;
  for(int i=0;i<n;i++){
    if(arr[i]!=1){
      temp = getFactorization(arr[i]);
      for(set<int> :: iterator j=temp.begin();j!=temp.end();j++){
        while(!prm[*j].empty() and prm[*j].front()<=arr[i]){
          prm[*j].pop();
        }
        if(!prm[*j].empty()){
          tt = prm[*j].front();
          ti = ind[tt];
          ans[ti] = max(ans[ti],ans[i]+1);
          prm[*j].pop();
        }
      }
    }
  }
  int max_ans = -1;
  for(int i=0;i<n;i++){
    max_ans =  max(max_ans,ans[i]);
  }
  cout<<max_ans<<endl;
  return 0;
}
