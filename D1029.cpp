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
const int P = 1e9 + 7;

const int N = 2e5 + 5;
int n, arr[N], k;
map<pair<int,int> , int > cnt;
int lli[N], rr[N];

int32_t main(){
    sd2(n, k);
    for(int i = 0; i < n; i++){
        sd(arr[i]);
        int r = arr[i]%k, len = 0;
        int temp = arr[i];
        while(temp){
            len ++;
            temp/=10;
        }
        cnt[mp(r, len)] ++;
        lli[i] = len;
        rr[i] = r;
    }
    // for(int i = 0; i < n; i++){
    //     tr(lli[i], rr[i]);
    // }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int r = (rr[i]*10)%k;
        int rem = (k - r)%k;
        int len = lli[i];
        int thi = rr[i];
        for(int j = 1; j < 11; j++){
            if(cnt.find(mp(rem, j))!=cnt.end()){
                ans += cnt[mp(rem, j)];
                if(rem == thi and len == j){
                    ans --;
                }
            }
            r *=10;
            r%=k;
            rem = (k - r)%k;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
