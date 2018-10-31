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

#define int ll

const int mod = 1e9 + 7;
int t;
int arr[7];

const ll M = 1e9 + 7;

ll mult(ll a, ll b)
{
    ll res = 0;
    a %= mod;
    while (b){
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res;
}


ll pow(ll a, ll p) {
	if (!p) return 1;
	ll ret = pow(a, p >> 1);
	ret = (ret * ret) % M;
	if (p & 1LL) ret = (ret * a) % M;
	return ret;
}

int modinv(int x){
    return pow(x, mod - 2);
}

int get(int a, int b, int c, int d){
    if(a == c){
        return abs(b - d);
    }
    if(b == d){
        return abs(a - c);
    }
    return (__gcd(abs(a - c), abs(b - d)));
}


int tri(int tot){
    if(tot <= 2){
        return 0;
    }
    int temp = mult(tot, tot - 1) % mod;
    temp = mult(temp, tot - 2) % mod;
    return mult(temp, modinv(6)) % mod;
}

int32_t main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        for(int j = 0; j < 6; j++){
            cin >> arr[j];
        }
        int p1 = get(arr[0], arr[1], arr[2], arr[3]);
        int p2 = get(arr[2], arr[3], arr[4], arr[5]);
        int p3 = get(arr[4], arr[5], arr[0], arr[1]);
        int tot = (p1 + p2 + p3)%mod;
        while(tot < 0){
            tot += mod;
        }
        int ans = tri(tot) - tri(p1 + 1) - tri(p2 + 1) - tri(p3 + 1);
        while(ans < 0){
            ans += mod;
        }
        cout << ans << endl;
    }
    return 0;
}
