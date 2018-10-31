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
const int N = 4100;
const ll M = 1e9 + 7;
vector<pair<int,int> > v[N];
vector<int> cumm[N];
int cnt[N];
int w[13];
int n,m,q;
// int cost[N][N];

ll pow(ll a, ll p) {
	if (!p) return 1;
	ll ret = pow(a, p >> 1);
	ret = (ret * ret) % M;
	if (p & 1LL) ret = (ret * a) % M;
	return ret;
}

int get_number(string s){
    reverse(s.begin(),s.end());
    int ans = 0;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '1'){
            ans += pow(2, i);
        }
    }
    return ans;
}

int cost(int i,int j){
    int k = i^j;
    int cost_pair = 0;
    for(int bit = 0; bit < n; bit++){
        if((k&1) == 0){
            cost_pair += w[bit];
        }
        k = k/2;
    }
    return cost_pair;
}




int32_t main(){
    char tmp[101];
    sd3(n,m,q);
    for(int i = 0; i < n; i++){
        sd(w[i]);
    }
    reverse(w, w + n);
    for(int i = 0; i < m; i++){
        string s;
        scanf("%s", tmp);
        s = tmp;
		int val = 0;
		for(auto &it:s)
			val=val*2 + (it-'0');
        cnt[val]++;
    }
	int dp[1<<n][101];
	MEMS(dp,0);
    for(int i = 0; i < (1<<n); i++){
        for(int j = 0; j < (1<<n); j++){
            if(cnt[j]==0)continue;
            v[i].pb(mp(cost(i,j),cnt[j]));
        }
    }
    for(int i = 0; i < (1<<n); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j].fi > 100)continue;
            dp[i][v[i][j].fi] += v[i][j].se;
        }
    }
    for(int i = 0; i <(1<<n); i++){
        for(int j = 1; j <= 100; j++){
            dp[i][j] += dp[i][j-1];
        }
    }
    while( q-- ){
        int temp;
        scanf("%s", tmp);
        string s = tmp;
        sd(temp);
        int num = get_number(s);
        printf("%d\n",dp[num][temp]);
    }
}
