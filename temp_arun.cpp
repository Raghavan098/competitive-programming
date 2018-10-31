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

const int N = 1e5 + 100;
const int MAXN = 1005;
const int MOD = 1e9 + 7;
const int tot_primes = 200;


int arr[N], n, q;
int pre_arr[N][tot_primes];
int primes[MAXN];
map<int, int> m;
int spf[MAXN];


void sieve(){
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
    for (int i=3; i*i<MAXN; i++){
        if (spf[i] == i){
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

vector<int> getFactorization(int x){
    vector<int> ret;
    while (x != 1){
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int get_ans(int l, int r){
    vector<int> temp(tot_primes);
    for(int i = 0; i < tot_primes; i++){
        temp[i] = pre_arr[r][i];
    }
    if(l != 0){
        for(int i = 0; i < tot_primes; i++){
            temp[i] -= pre_arr[l-1][i];
        }
    }
    int ans = 1;
    for(int i = 0; i < tot_primes; i++){
        ans = (ans * (temp[i] + 1)) % MOD;
    }
    return ans;
}

int32_t main(){ _
    sieve();
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 2; i < MAXN; i++){
        for(int j = 2*i; j < MAXN; j+=i){
            primes[j] = 1;
        }
    }
    int curr = 0;
    for(int i = 2; i < MAXN; i++){
        if(primes[i] == 0){
            m[i] = curr;
            curr++;
        }
    }
    for(int i = 0; i < n; i++){
        auto temp = getFactorization(arr[i]);
        for(auto j: temp){
            pre_arr[i][m[j]]++;
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < tot_primes; j++){
            pre_arr[i][j] += pre_arr[i-1][j];
        }
    }
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << get_ans(l, r) << endl;
    }
    return 0;
}
