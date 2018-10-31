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

int solve(int test){
    int n,k;
    cin>>n>>k;
    if(n==2 or k==2){

        cout<<"Case #"<<test<<": "<<0<<endl;
        cout<<1<<endl;
        cout<<1<<" "<<n<<" "<<k<<endl;
        return 0;
    }

    int inter = min(k-1,n-2);

    int ur = 1;
    int pre = 2;
    int q = k-1;
    vector<pair<int,pair<int,int> > > ans;
    ans.pb(mp(k,mp(1,n)));
    int s = 0;
    int i;
    for(i=0;i<inter && q>1;i++){
        ans.pb(mp(q,mp(ur,pre)));
        ur = pre;
        pre++;
        s += q;
        q--;
    }
    tr(q,s,k,pre,ur);
    ans.pb(mp(q,mp(ur,n)));
    s += q;
    cout<<"Case #"<<test<<": "<<abs(s - k)<<endl;
    cout<<ans.size()<<endl;
    for(auto i: ans){
        cout<<i.se.fi<<" "<<i.se.se<<" "<<i.fi<<endl;
    }
    return 0;
}

int32_t main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}
