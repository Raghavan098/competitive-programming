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
#define inf 10000000000000001

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

const int N = 1e5 + 100;
const int LOG = 40;


int n, k;
int bin[N][LOG];
int cost[N][LOG];
int min_val[N][LOG];

pair<int, int> query(int v){
    int curr = v;
    int curr_cost = 0;
    int curr_min = inf;
    for(int i = LOG - 1; i >= 0; i--){
        if(k & (1LL << i)){
            curr_cost += cost[curr][i];
            curr_min = min(curr_min, min_val[curr][i]);
            curr = bin[curr][i];
        }
    }
    return mp(curr_cost, curr_min);
}

int32_t main(){ _
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> bin[i][0];
        bin[i][0]++;
    }
    for(int i = 1; i <= n; i++){
        cin >> cost[i][0];
        min_val[i][0] = cost[i][0];
    }
    for(int i = 1; i < LOG; i++){
        for(int j = 1; j <= n; j++){
            bin[j][i] = bin[bin[j][i-1]][i-1];
            cost[j][i] = cost[j][i-1] + cost[bin[j][i-1]][i-1];
            min_val[j][i] = min(min_val[j][i-1], min_val[bin[j][i-1]][i-1]);
        }
    }
    for(int i = 1; i <= n; i++){
        auto temp = query(i);
        cout << temp.fi << " " << temp.se << endl;
    }
}
