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

int poww10[19];
int dp[19][200];

int f(int prefix, int digits, int sum, int no){
    // tr(prefix, digits, sum, no);
    if(sum < 0 or digits < 0){
        return 0;
    }
    if(prefix > no){
        return 0;
    }
    if((prefix + poww10[digits] - 1) <= no and dp[digits][sum] != -1){
        // tr(prefix, digits, sum, dp[digits][sum]);
        return dp[digits][sum];
    }
    if(prefix >= 0 and prefix <= no and sum==0 and digits==0){
        // tr(prefix);
        return 1;
    }
    int ans = 0;
    if(digits>0){
        for(int i = 0; i < 10; i++){
            ans = (ans + f(prefix + poww10[digits -1]*i, digits - 1, sum - i, no))%mod;
        }
    }
    // tr(ans, prefix, digits, sum);
    ans = ans%mod;
    return dp[digits][sum] = ans;
}

int solve(){
    int a, b;
    int temp = b;
    cin >> a >> b;
    // MEMS(dp, -1);
    // cout << f(0, 18, a, b) << endl;
    int ans1[201], ans2[201], ans[201];
    for(int i = 1; i <= 163; i++){
        MEMS(dp, -1);
        ans1[i] = f(0, 18, i, b)%mod;
    }
    for(int i = 1; i <= 163; i++){
        MEMS(dp, -1);
        ans2[i] = f(0, 18, i, a-1)%mod;
    }
    for(int i = 1; i <=163; i++){
        ans[i] = (ans2[i] - ans1[i])%mod;
        while(ans[i] < 0){
            ans[i] += mod;
        }
    }
    int final_ans = 0;
    for(int i = 1; i <= 163; i++){
        for(int j = i + 1; j <= 163 ; j++){
            final_ans =( final_ans +  (__gcd(i,j) == 1)*((ans[i]*ans[j])%mod))%mod;
        }
    }
    cout << final_ans%mod << endl;
}

int32_t main(){
    poww10[0] = 1;
    for(int i = 1; i <= 18; i++){
        poww10[i] = poww10[i-1]*10;
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
