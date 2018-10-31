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

const ll N = 2000;
ll a[N],b[N],k,n;
ll power[19];
lld p[N];
lld dp[N][N];

ll get(ll no){
    if(no==0){
        return 0;
    }
    ll len = 0;
    ll temp = no;
    ll ans = 0;
    while(temp){
        len++;
        temp/=10;
    }
    for(int i=0;i<len-1;i++){
        ans += power[i];
    }
    temp = no;
    if((temp/power[len-1])==1){
        ans += temp - power[len - 1] +1;
    }
    else{
        ans += power[len-1];
    }
    return ans;
}

lld f(int ind,int k){
    if(ind==-1){
        return 1.00;
    }
    lld x = dp[ind][k];
    lld ans;
    if(x!=-1){
        return x;
    }
    if(ind==0){
        if(k==1){
            ans = p[ind];
        }
        else if(k==0){
            ans = (1 - p[ind]);
        }
        else{
            ans = 0.00;
        }
    }
    else if(k==0){
        ans = (1 - p[ind])*f(ind-1,k);
    }
    else{
        ans = (1 - p[ind])*f(ind-1,k) + (p[ind])*f(ind-1,k-1);
    }
    // tr(ind,k,ans);
    return dp[ind][k] = ans;
}

int main(){ _
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    cin>>k;
    power[0] = 1;
    for(int i=1;i<19;i++){
        power[i] = power[i-1]*10;
    }
    for(int i=0;i<n;i++){
        p[i] = ((get(b[i]) - get(a[i]-1))*1.0/(b[i] - a[i] +1));
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j] = -1;
        }
    }
    for(int i=1;i<=n;i++){
        f(n-1,i);
    }
    int start = ceil((n*k)*(1.0)/100);
    if(start==0){
        cout<<1<<endl;
        return 0;
    }
    lld final_ans = 0;
    for(int i=start;i<=n;i++){
        final_ans += dp[n-1][i];
    }
    printf("%0.17Lf\n",final_ans);
    return 0;
}
