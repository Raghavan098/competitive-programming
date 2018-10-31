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

const int N = 1e5 + 10;
const int LOG = 25;

int st[N][LOG][2];
int arr[N], n;
int dp[N];
int nl[N], nr[N];

void pre_process(){
    for(int i = 0; i < n; i++){
        st[i][0][0] = arr[i];
        st[i][0][1] = i;
    }
    for(int j = 1; j<LOG; j++){
        for(int i = 0; i + (1<<j) <= n; i++){
            if(st[i][j-1][0] >= st[i+(1 <<(j-1))][j-1][0]){
                st[i][j][0] = st[i][j-1][0];
                st[i][j][1] = st[i][j-1][1];
            }
            else{
                st[i][j][0] = st[i+(1 <<(j-1))][j-1][0];
                st[i][j][1] = st[i+(1 <<(j-1))][j-1][1];
            }
        }
    }
}

void pre_process2(){
    stack<int> st;
    for(int i=N-1;i>=0;i--){
        while(!st.empty() and arr[st.top()]<arr[i])
            st.pop();
        if(st.empty())
            nr[i]=n;
        else
            nr[i]=st.top();
        st.push(i);
    }
    while(!st.empty())
        st.pop();
    for(int i=0;i<n;i++){
        while(!st.empty() and arr[st.top()]<arr[i])
            st.pop();
        if(st.empty())
            nl[i]=-1;
        else
            nl[i]=st.top();
        st.push(i);
    }
}

pair<int,int> query(int a, int b){
    int k = log2(b-a+1);
    if(st[a][k][0] >= st[b - (1<<k) +1][k][0]){
        return mp(st[a][k][0], st[a][k][1]);
    }
    else{
        return mp(st[b - (1<<k) +1][k][0], st[b - (1<<k) +1][k][1]);
    }
}

pair<int, int> get_interval(int idx){
    return mp(nl[idx], nr[idx]);
}

int f(int idx){
    if(idx == -1 or idx == n){
        return 0;
    }
    if(dp[idx] != -1){
        return dp[idx];
    }
    auto interval = get_interval(idx);
    if(interval.se - interval.fi == 2){
        return dp[idx] = 1;
    }
    int a = 1;
    int b = 1;
    if(interval.se != idx + 1){
        int temp = query(idx + 1, interval.se - 1).se;
        a += f(temp);
    }
    if(interval.fi != idx - 1){
        int temp = query(interval.fi + 1, idx - 1).se;
        b += f(temp);
    }
    return dp[idx] = min(a, b);
}

void clear_all(){
    MEMS(st, 0);
    MEMS(arr, 0);
    MEMS(dp, 0);
    MEMS(nl, 0);
    MEMS(nr, 0);
    for(int i = 0; i < N; i++){
        dp[i] = -1;
    }
}

int solve(){
    clear_all();
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    pre_process();
    pre_process2();
    int idx = query(0, n - 1).se;
    cout << f(idx) << endl;
}

int32_t main(){ _
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
