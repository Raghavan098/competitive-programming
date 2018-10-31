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

const int N = 3e5 + 6;
int dp[2][N][4];
int a[N],b[N],n;

// type 1: right
// type 2: left
// type 3: up
// type 4: down

int f(int r,int c,int t){
    if(r<0 or r==2 or c<0 or c==n){
        return -1;
    }
    int x = dp[r][c][t];
    if(x!=-1){
        return x;
    }
    int ans;
    if(t==1 and r==0){
        ans = f(r+1,c,3);
    }
    if(t==1 and r==1){
        ans = f(r-1,c,4);
    }
    if(t==4 and r==0){
        ans = f(r,)
    }
    return 0;
}


int main(){ _
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i0;i<n;i++){
        cin>>b[i];
    }
    MEMS(dp,-1);
    cout<<max(f(1,n-1,1),max(f(0,n-1,1),f(1,0,2)))<<endl;
    return 0;
}
