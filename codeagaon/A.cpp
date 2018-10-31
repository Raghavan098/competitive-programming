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
    vector<pair<int, int> > v;
    vector<pair<int, int> > v2;
    for(int i = 0; i < 5; i++){
        int a, b;
        cin >> a >> b;
        v.pb(mp(a, b));
        v2.pb(mp(b, a));
    }
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    vector<pair<int,int> > hori, vert;
    for(int i = 0; i < 5 - 2; i++){
        if(v[i].fi == v[i+1].fi and v[i+1].fi == v[i+2].fi){
            hori.pb(v[i]);
            hori.pb(v[i+1]);
            hori.pb(v[i+2]);
        }
    }
    for(int i = 0; i < 5 - 2; i++){
        if(v2[i].fi == v2[i+1].fi and v2[i+1].fi == v2[i+2].fi){
            vert.pb(mp(v2[i].se, v2[i].fi));
            vert.pb(mp(v2[i+1].se, v2[i+1].fi));
            vert.pb(mp(v2[i+2].se, v2[i+2].fi));
        }
    }
    sort(hori.begin(), hori.end());
    sort(vert.begin(), vert.end());
    auto temp = hori;
    hori = vert;
    vert = temp;
    if(!hori.empty() and !vert.empty()){
        if(!(hori[0].fi == hori[1].fi -1 and hori[1].fi == hori[2].fi -1)){
            cout << "No\n";
            return 0;
        }
        if(!(vert[0].se == vert[1].se -1 and vert[1].se == vert[2].se -1)){
            cout << "No\n";
            return 0;
        }
        if(vert[1] == hori[0] or vert[1] == hori[2]){
            cout << "Yes\n";
            return 0;
        }
        if(hori[1] == vert[0] or hori[1] == vert[2]){
            cout << "Yes\n";
            return 0;
        }
        cout << "No\n";
        return 0;
    }
    else{
        cout << "No\n";
    }
    return 0;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
