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

vector<int> v;

void build(int s, int e, int k){
    int tot = e - s + 1;
    if((tot - 2*k) >= 2*k){
        build(s, s + 2*k -1, k);
        build(s + 2*k, e, k);
    }
    else{
        set<int> st;
        set<int> visited;
        for(int i = s + k; i <= e; i++){
            st.insert(i);
        }
        for(int i = e; i > e-k; i--){
            v[i-k] = i;
            st.erase(i);
            visited.insert(i);
        }
        int curp = s;
        for(int i = s; i <= e; i++){
            if(v[i] == 0){
                int temp = *st.begin();
                v[i] = temp;
                st.erase(temp);
                visited.insert(temp);
            }
            if(i + 1 - curp >= k and visited.find(curp) == visited.end()){
                st.insert(curp);
                curp++;
            }
        }
    }
}

int solve(){
    int n, k;
    cin >> n >> k;
    v.clear();
    v.resize(n+1);
    if(k == 0){
        for(int i = 1; i <= n; i++){
            cout << i << " " ;
        }cout << endl;
        return 0;
    }
    if(k > n/2){
        cout << -1 << endl;
        return 0;
    }
    build(1, n, k);
    for(int i  = 1; i <= n; i++){
        cout << v[i] << " ";
    }cout << endl;
    return 0;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
