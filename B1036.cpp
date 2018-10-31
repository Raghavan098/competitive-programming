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

int32_t main(){
    int test, t;
    cin >> test;
    for(int t = 0; t < test; t++){
        int n, m, k;
        cin >> n >> m >> k;
        int d = min(n, m);
        int steps = d;
        int min_steps = abs(n - d) + abs(m - d) + d;
        if(n < m){
            swap(n, m);
        }
        if(min_steps > k){
            cout << -1 << endl;
            continue;
        }
        if((n - m) % 2 == 0){
            d += (n - m);
            steps += (n - m);
            if((k - steps) == 1){
                d -= 1;
            }
            else if((k - steps) % 2 == 0){
                d += (k - steps);
            }
            else{
                d += (k - steps - 2);
            }
        }
        else{
            d += (n - m - 1);
            steps += (n - m - 1);
            if((k - steps) == 1){
            }
            else if((k - steps) % 2 == 1){
                d += (k - steps - 1);
            }
            else{
                d += (k - steps - 1);
            }
        }
        cout << d << endl;
    }
    return 0;
}
