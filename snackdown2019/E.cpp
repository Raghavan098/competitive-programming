// g++ -std=c++14

/*

Today might be the chance to grasp the chance to let your talent bloom.
May be tomorrow, the day after, or next year...
May be even when you are 30. I'm not sure if physique has anything to do with it
but if you think that it will never come, it probably never will.

- Tooru Oikawa.

*/


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
#define all(c) c.begin(),c.end()
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

const int N = 1e6 + 100;
const int M = 1e9 + 7;
int n;
vector<int> v, arr;
map<int, int> cnt;

ll poww(ll a, ll p, ll M) {
	if (!p) return 1;
	ll ret = poww(a, p >> 1, M);
	ret = (ret * ret) % M;
	if (p & 1LL) ret = (ret * a) % M;
	return ret;
}


ll mult(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

int get(int x){
    int ans = 1;
    if(x % 2 == 1){
        x--;
    }
    int nn = 1;
    int curr = 1;
    while(x > 0){
        ans = mult(ans, ((x * (x - 1)) / 2), M);
        x -= 2;
        nn = (nn* curr) % M;
        curr++;
    }
    ans = (ans * poww(nn, M - 2, M)) % M;
    return ans % M;
}

void clear_all(){
    v.clear();
    v.resize(n);
    cnt.clear();
    arr.clear();
    arr.resize(0);
}

int solve(){
    cin >> n;
    clear_all();
    for(int i = 0; i < n; i++){
        cin >> v[i];
        cnt[v[i]]++;
        if(cnt[v[i]] == 1){
            arr.pb(v[i]);
        }
    }
    sort(all(arr));
    int start = -1;
    int ans  = 1;
    n = arr.size();
    for(int i = n-1; i >= 0; i--){
        if(start == -1 and cnt[arr[i]] > 1){
            ans = mult(ans, get(cnt[arr[i]]), M);
            if(cnt[arr[i]] % 2 == 1){
                ans = mult(ans, cnt[arr[i]], M);
                start = arr[i];
            }
            else{
                start = -1;
            }
        }
        else if(start == -1 and cnt[arr[i]] == 1){
            start = arr[i];
        }
        else{
            ans = mult(ans, cnt[arr[i]], M);
            cnt[arr[i]]--;
            if(cnt[arr[i]] > 1){
                ans = mult(ans, get(cnt[arr[i]]), M);
            }
            if(cnt[arr[i]] % 2 == 1){
                start = arr[i];
                ans = mult(ans, cnt[arr[i]], M);
            }
            else{
                start = -1;
            }
        }
    }
    cout << ans % M << endl;
    return 0;
}

int32_t main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
    return 0;
}
