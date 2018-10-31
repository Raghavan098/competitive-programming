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

const int N = 1e5 + 10;
const int LOG = 25;

int n, q, arr[N], cumu[N], l, r, a, b, near[N];
int st[N][LOG][2];

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

pair<int,int> query(int a, int b){
    int k = log2(b-a+1);
    if(st[a][k][0] >= st[b - (1<<k) +1][k][0]){
        return mp(st[a][k][0], st[a][k][1]);
    }
    else{
        return mp(st[b - (1<<k) +1][k][0], st[b - (1<<k) +1][k][1]);
    }
}



int32_t main(){
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    pre_process();
    for(int i = 1; i < n; i++){
        if(arr[i-1] >= arr[i])continue;
        int l = 0;
        int r = i - 1;
        int mid, ans;
        while(l <= r){
            mid = (l + r)/2;
            if(query(mid, i - 1).fi < arr[i]){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cumu[ans] += 1;
        cumu[i] -= 1;
    }
    for(int i = 1; i < n; i ++){
        cumu[i] += cumu[i-1];
    }
    int ans = 0;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        l = (a + ans) % n;
        r = (b + ans) % n;
        if(l > r){
            swap(l, r);
        }
        ans = cumu[l] - cumu[query(l, r).se] + 1;
        cout << ans << endl;
    }
    return 0;
}
