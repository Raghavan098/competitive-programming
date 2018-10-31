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

int n;
int cnt[N];
vector<int> v;
set<int> s;
vector<pair<int, int> > edg;

int32_t main(){ _
    cin >> n;
    for(int i = 1; i < n; i++){
        s.insert(i);
    }
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        if(a > b){
            swap(a, b);
        }
        if(b != n){
            cout << "NO\n";
            return 0;
        }
        cnt[a]++;
        s.erase(a);
    }
    for(int i = 1; i <= n; i++){
        if(cnt[i] != 0){
            int curr = i;
            for(int j = 0; j < cnt[i] - 1; j++){
                if(s.empty()){
                    cout << "NO\n";
                    return 0;
                }
                int temp = *s.begin();
                s.erase(temp);
                if(temp > i){
                    cout << "NO\n";
                    return 0;
                }
                edg.pb(mp(curr, temp));
                curr = temp;
            }
            edg.pb(mp(curr, n));
        }
    }
    for(auto i: s){
        edg.pb(mp(i, n));
    }
    cout << "YES\n";
    for(auto i: edg){
        cout << i.fi << " " << i.se << endl;
    }
    return 0;
}
