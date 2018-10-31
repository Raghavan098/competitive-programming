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

const int N = 2000;

int w, b;
lld dp[N][N][2];

lld f(int x, int y, int typ){
    if(x < 0 or y < 0){
        return 0.0;
    }
    if(dp[x][y][typ] != -1){
        return dp[x][y][typ];
    }
    if(x == 0 and y == 0){
        return dp[x][y][typ] = 0.0;
    }
    if(typ == 0){
        // princess :)
        if(x == 0){
            return dp[x][y][typ] = 0.0;
        }
        if(y == 0){
            return dp[x][y][typ] = 1.0;
        }
        lld win = lld(x)/lld(x + y);
        lld lose = lld(y)/lld(x + y);
        lld dr_ls = f(x, y - 1, 1);
        return dp[x][y][typ] = (win + lose*dr_ls);
    }
    else{
        if(x >= 1 and y == 0){
            return dp[x][y][typ] = 0.0;
        }
        if(x == 0){
            return dp[x][y][typ] = 0.0;
        }
        lld lose = lld(y)/lld(y + x);
        lld pr_win1 = f(x - 1, y - 1, 0);
        lld pr_win2 = f(x, y - 2, 0);
        pr_win1 *= lld(x)/lld(x + y - 1);
        pr_win2 *= lld(y - 1)/lld(x + y - 1);
        return dp[x][y][typ] = (lose*(pr_win1 + pr_win2));
    }
}

int32_t main(){ _
    cin >> w >> b;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
    printf("%.12Lf\n", f(w, b, 0));
    return 0;
}
