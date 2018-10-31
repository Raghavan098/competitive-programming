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

const int N = 31;

int a, b, c, n, bit_a, bit_b;

int dp[N][N][N][2];

int f(int pos, int a, int b, int carry){
    if(a < 0 or b < 0){
        return 0;
    }
    if(dp[pos][a][b][carry] != -1){
        return dp[pos][a][b][carry];
    }
    if(pos == n){
        if(a == 0 and b == 0 and carry == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    int ans = 0;
    if(c & (1 << pos)){
        if(carry == 1){
            ans += f(pos + 1, a - 1, b - 1, 1);
            ans += f(pos + 1, a, b, 0);
        }
        else{
            ans += f(pos + 1, a - 1, b, 0);
            ans += f(pos + 1, a, b - 1, 0);
        }
    }
    else{
        if(carry == 1){
            ans += f(pos + 1, a - 1, b, 1);
            ans += f(pos + 1, a, b - 1, 1);
        }
        else{
            ans += f(pos + 1, a - 1, b - 1, 1);
            ans += f(pos + 1, a, b, 0);
        }
    }
    return dp[pos][a][b][carry] = ans;
}

void clear_all(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                for(int q = 0; q < 2; q++){
                    dp[i][j][k][q] = -1;
                }
            }
        }
    }
}

int solve(){
    clear_all();
    sd3(a, b, c);
    n = log2(c) + 1;
    bit_a = __builtin_popcount(a);
    bit_b = __builtin_popcount(b);
    int ans = 0;
    if(c % 2 == 0){
        ans = f(1, bit_a, bit_b, 0);
        ans += f(1, bit_a - 1, bit_b - 1, 1);
    }
    else{
        ans = f(1, bit_a - 1, bit_b, 0);
        ans += f(1, bit_a, bit_b - 1, 0);
    }
    printf("%d\n", ans);
    return 0;
}

int32_t main(){
    int t;
    sd(t);
    for(int i = 0; i < t; i++){
        solve();
    }
    return 0;
}
