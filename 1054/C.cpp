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
int l[N], r[N], n, ans[N];
int done[N];

int32_t main(){ _
    cin >> n;
    queue<pair<int, int> > q;
    for(int i = 0; i < n; i++){
        cin >> l[i];
    }
    int cur_max = 2000;
    for(int i = 0; i < n; i++){
        cin >> r[i];
        if(r[i] == 0 and l[i] == 0){
            q.push(mp(i, cur_max));
        }
    }
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        done[temp.fi] = 1;
        ans[temp.fi] = temp.se;
        for(int i = 0; i < n; i++){
            if(i > temp.fi and done[i] == 0){
                l[i]--;
            }
            else{
                r[i]--;
            }
        }
        if(q.empty()){
            cur_max--;
            for(int i = 0; i < n; i++){
                if(l[i] == 0 and r[i] == 0 and done[i] == 0){
                    q.push(mp(i, cur_max));
                }
            }
        }
    }
    int mi = inf;
    for(int i = 0; i < n; i++){
        if(ans[i] == 0){
            cout << "NO\n";
            return 0;
        }
        mi = min(mi, ans[i]);
    }
    mi--;
    for(int i = 0; i < n; i++){
        ans[i] -= mi;
        if(ans[i] > n){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }cout << endl;
    return 0;
}
