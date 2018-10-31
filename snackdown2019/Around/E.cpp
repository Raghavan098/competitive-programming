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

const int N = 330;

const int LOL = 610;

int n, m, arr[N][N];
int dp[N][N][LOL];
int ans[LOL];

void clear_all(){
    MEMS(dp, 0);
    MEMS(arr, 0);
    MEMS(ans, 0);
}

int solve(){
    clear_all();
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        for(int j = 0; j < m; j++){
            if(temp[j] == '1'){
                arr[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dp[i][j][0] = arr[i][j];
            if(!(i == 0 or j == 0)){
                for(int k = 0; k < LOL - 5; k++){
                    dp[i][j][k + 2] += dp[i - 1][j - 1][k];
                }
            }
            for(int k = 0; k < j; k++){
                if(arr[i][k] == 1){
                    dp[i][j][j - k]++;
                }
            }
            for(int k = 0; k < i; k++){
                if(arr[k][j] == 1){
                    dp[i][j][i - k]++;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 1){
                for(int k = 0; k < LOL; k++){
                    ans[k] += dp[i][j][k];
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (m/2); j++){
            swap(arr[i][j], arr[i][m - j -1]);
        }
    }
    MEMS(dp, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dp[i][j][0] = arr[i][j];
            if(!(i == 0 or j == 0)){
                for(int k = 0; k < LOL - 5; k++){
                    dp[i][j][k + 2] += dp[i - 1][j - 1][k];
                }
            }
            for(int k = 0; k < j; k++){
                if(arr[i][k] == 1){
                    dp[i][j][j - k]++;
                }
            }
            for(int k = 0; k < i; k++){
                if(arr[k][j] == 1){
                    dp[i][j][i - k]++;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 1){
                for(int k = 0; k < LOL; k++){
                    ans[k] += dp[i][j][k];
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = j; k < m; k++){
                if(arr[i][j] == 1 and arr[i][k] == 1){
                    ans[k - j]--;
                }
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(arr[j][i] == 1 and arr[k][i] == 1){
                    ans[k - j]--;
                }
            }
        }
    }
    for(int i = 1; i <= (n + m - 2); i++){
        cout << ans[i] << " ";
    }cout << endl;
    return 0;
}

int32_t main(){ _
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
    return 0;
}
