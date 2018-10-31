// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%lld",&x)
#define sd2(x,y) scanf("%lld%lld",&x,&y)
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

#define int ll

const int N = 3e5 + 10;
int n,m;
int a[N],x[N];
vector< pair< int, int > > v;

int32_t main(){
    sd2(n, m);
    for(int i = 0; i < n; i++){
        sd(a[i]);
    }
    for(int i = 0; i < n; i++){
        int sz = (int)v.size();
        if(a[i] == 1){
            if(sz != 0 and v[sz-1].fi == 1){
                v[sz-1].se ++;
            }
            else{
                v.pb(mp(1,1));
            }
        }
        else{
            v.pb(mp(a[i],1));
        }
    }
    for(int i = 0; i < m; i++){
        int temp;
        sd(temp);
        int curr = 0;
        int ans = 0;
        for(int j = 0; j< (int)v.size(); j++){
            if(v[j].fi == 1){
                ans += temp*(v[j].se);
                curr += v[j].se;
            }
            else{
                ans += ceil((lld)temp/v[j].fi);
                temp = ceil((lld)temp/v[j].fi);
                curr ++;
            }
            if(temp == 1){
                printf("%lld\n", ans+n-curr);
                break;
            }
        }
    }
    return 0;
}
