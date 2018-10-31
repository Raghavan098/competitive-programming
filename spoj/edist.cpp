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

const int N = 2002;
int dp[N][N];
string s1,s2;
int n,m;

int f(int i,int j){
    // tr(i,j);
    int x = dp[i][j];
    if(x!=-1){
        return x;
    }
    if(i==n and j==m){
        return dp[i][j] = 0;
    }
    if(i==n){
        return dp[i][j] = (m - j);
    }
    if(j==m){
        return dp[i][j] = (n - i);
    }
    int ans;
    if(s1[i]==s2[j]){
        ans = f(i+1,j+1);
    }
    else{
        ans = f(i+1,j+1) + 1;
        ans = min(ans,f(i+1,j)+1);
        ans = min(ans,f(i,j+1)+1);
    }
    return dp[i][j] = ans;
}

int solve(){
    cin>>s1>>s2;
    if(s2.size()>s1.size()){
        swap(s1,s2);
    }
    n = s1.size();
    m = s2.size();
    MEMS(dp,-1);
    cout<<f(0,0)<<endl;
    return 0;
}

int main(){ _
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
    return 0;
}
