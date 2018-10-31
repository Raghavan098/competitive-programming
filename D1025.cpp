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

// #define int ll

const int N = 700;
int arr[N], n;
int dp[N][N][2];
int g[N][N];

bool check(int s, int curr, int e, int m);

bool f(int s, int e, int t){
    if(e == s - 1){
        return true;
    }
    if(dp[s][e][t] != 0){
        if(dp[s][e][t] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    if(t == 0){
        if(s == e){
            if(g[s][s+1] == 1){
                dp[s][e][t] = 1;
                return true;
            }
            else{
                dp[s][e][t] = 2;
                return false;
            }
        }
        for(int i = s; i <= e; i++){
            if(check(s, i, e, e + 1) == true){
                dp[s][e][t] = 1;
                return true;
            }
        }
        dp[s][e][t] = 2;
        return false;
    }
    else{
        if(s == e){
            if(g[s][s-1] == 1){
                dp[s][e][t] = 1;
                return true;
            }
            else{
                dp[s][e][t] = 2;
                return false;
            }
        }
        for(int i = s; i <= e; i++){
            if(check(s, i, e, s - 1) == true){
                dp[s][e][t] = 1;
                return true;
            }
        }
        dp[s][e][t] = 2;
        return false;
    }
}

bool check(int s, int curr, int e, int m){
    if((curr == s or f(s, curr-1, 0) == true) and (curr == e or f(curr + 1, e, 1) == true ) and g[m][curr] == 1){
        return true;
    }
    return false;
}


int32_t main(){
    sd(n);
    for(int i = 0; i < n; i++){
        sd(arr[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a, b;
            a = arr[i], b = arr[j];
            if(__gcd(a, b) > 1){
                g[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        int a = 0, b = 0;
        if(i == 0){
            a = 1;
        }
        else if(f(0, i - 1, 0) == true){
            a =  1;
        }
        if(i == n-1){
            b = 1;
        }
        else if(f(i + 1, n-1, 1) == true){
            b = 1;
        }
        if(a == 1 and b == 1){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
