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


int main(){ _
    int t;
    cin >> t;
    while(t--){
        ll arr[3],brr[3],crr[3];
        ll l,r;
        for(int i=0;i<3;i++){
            cin >> arr[i];
        }
        for(int i=0;i<3;i++){
            cin >> brr[i];
        }
        cin >> l >> r;
        crr[0] = (arr[0]-brr[0])*2;
        crr[1] = (arr[1]-brr[1])*3;
        crr[2] = (arr[2]-brr[2])*6;
        ll ans = crr[0]*pow(r,3) + crr[1]*pow(r,2) + crr[2]*r;
        ans -= crr[0]*pow(l,3) + crr[1]*pow(l,2) + crr[2]*l;
        if(ans<0){
            ans *=-1;
        }
        ll x = __gcd(ans,6ll);
        cout << ans/x << "/" << 6/x << "\n";
    }
    return 0;
}
