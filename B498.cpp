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

// #define int ll

const int N = 5001;

// http://codeforces.com/blog/entry/15353?#comment-203427

int t[N], n, T;
lld p[N];
vector<lld> A(N), B(N);

int32_t main(){
    scanf("%d %d", &n, &T);
    for(int i = 1; i <= n; i++){
        scanf("%Lf %d", &p[i], &t[i]);
        p[i] /= 100.00;
    }
    lld ans = 0.0;
    A[0] = 1.0;
    for(int i = 1; i <= n; i++){
        lld full = 1.0;
        for(int j = 1; j <= t[i]; j++){
            full = (full * (1.0 - p[i]));
        }
        lld temp = 0;
        for(int j = 1; j <= T; j++){
            temp = temp + A[j-1];
            if(j > t[i]){
                temp = temp - A[j-t[i]-1]*full;
            }
            B[j] = temp*p[i];
            if(j >= t[i]){
                B[j] += A[j-t[i]]*full;
            }
            ans += B[j];
            temp = temp*(1.0 - p[i]);
        }
        swap(A, B);
        B.clear();
        B.resize(N);
    }
    printf("%0.12Lf\n", ans);
    return 0;
}
