// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
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
int n,m;
const int N = 3000+4;
int p[N],c[N];
unordered_map<int,vector<int> > cnt;
int32_t main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>p[i]>>c[i];
        cnt[p[i]].pb(c[i]);
    }
    for(int i=2;i<=m;i++){
        sort(cnt[i].begin(), cnt[i].end());
    }
    int best = inf;
    for(int votes = 1; votes <= n; votes++){
        int cost = 0;
        int req = votes - (int)cnt[1].size();
        vector<int> remaining;
        for(int i = 2;i <= m;i++){
            int st_idx = max((int)cnt[i].size() - votes + 1, 0LL);
            for(int j = 0;j < st_idx;j++){
                cost += cnt[i][j];
                req--;
            }
            for(int j = st_idx; j < (int)cnt[i].size(); j++){
                remaining.pb(cnt[i][j]);
            }
        }
        if(req > 0){
            sort(remaining.begin(),remaining.end());
            for(int i = 0; i < req; i++){
                cost += remaining[i];
            }
        }
        best = min(best,cost);
    }
    cout << best << endl;
    return 0;
}
