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
#define inf -1

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

const ll N = 2e5 + 3;

ll a[N],b[N];
ll n,k;
ll c;
vector<pair<ll,pair<ll,ll> > > v;

int main(){ _
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
    for(ll i=0;i<n;i++){
        if(a[i]<=b[i]){
            k--;
            c += a[i];
            a[i] = inf;
            b[i] = 2*inf;
        }
    }
    // tr(c,k);
    if(k<=0){
        for(ll i=0;i<n;i++){
            if(b[i]!=2*inf){
                c += b[i];
            }
        }
        cout<<c<<endl;
        return 0;
    }
    else{
        for(ll i=0;i<n;i++){
            if(a[i]!=inf){
                v.pb(mp((a[i] - b[i]),mp(a[i],b[i])));
            }
        }
        sort(v.begin(),v.end());
        for(ll i=0;i<v.size();i++){
            if(k>0){
                c += v[i].se.fi;
                k--;
            }
            else{
                c += v[i].se.se;
            }
        }
        cout<<c<<endl;
        return 0;
    }
    return 0;
}
