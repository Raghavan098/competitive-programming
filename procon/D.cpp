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

int solve(){
    int n;
    cin >> n;
    int arr[202];
    cin >> arr[0];
    int typ[202];
    typ[0] = 1;
    string temp;
    for(int i = 1; i < n; i++){
        cin >> temp;
        if(temp == "+"){
            typ[i - 1] = 1;
        }
        else{
            typ[i - 1] = -1;
        }
        cin >> arr[i];
    }
    int dp[202][202][2];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j][0] =  -9999999999999;
            dp[i][j][1] =  9999999999999;
        }
        dp[i][i][0] = arr[i];
        dp[i][i][1] = arr[i];
    }
    for(int l = 2; l <= n; l ++){
        for(int i = 0;(i < n) && (i + l - 1 < n); i++){
            for(int j = i; j < max(n, i + l) -1; j++){
                if(typ[j] == 1){
                    dp[i][i + l - 1][0] = max(dp[i][i + l - 1][0], dp[i][j][0] + dp[j+1][i + l - 1][0]);
                    dp[i][i + l - 1][1] = min(dp[i][i + l - 1][1], dp[i][j][1] + dp[j+1][i + l - 1][1]);
                }
                else{
                    dp[i][i + l -1][0] = max(dp[i][i + l -1][0], dp[i][j][0] - dp[j+1][i + l - 1][1]);
                    dp[i][i + l -1][1] = min(dp[i][i + l -1][1], dp[i][j][1] - dp[j+1][i + l - 1][0]);
                }
            }
        }
    }
    cout << dp[0][n-1][0] << endl;
    return 0;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
