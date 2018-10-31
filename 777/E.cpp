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

const int N = 1e6;

struct data{
    int val;
};

data seg_tree[8*N];

int n;
int a_mx[2*N + 100];
int dp[N];
vector<pair<int, pair<int, int> > > arr;
map<int, int> ac;

data combine(data l, data r){
    data res;
    res.val = max(l.val, r.val);
    return res;
}
void build(int v, int l, int r){
    if(l == r){
        seg_tree[v].val = 0;
        return;
    }
    int m = (l + r) / 2;
    build(2*v, l, m);
    build(2*v + 1, m + 1, r);
    seg_tree[v] = combine(seg_tree[2*v], seg_tree[2*v + 1]);
    return;
}

void update(int v, int l, int r, int pos, int new_val){
    if(l == r){
        seg_tree[v].val = new_val;
        return;
    }
    int m = (l + r) / 2;
    if(pos <= m){
        update(2*v, l, m, pos, new_val);
    }
    else{
        update(2*v + 1, m + 1, r, pos, new_val);
    }
    seg_tree[v] = combine(seg_tree[2*v], seg_tree[2*v + 1]);
}
data query(int v, int l, int r, int ql, int qr){
    if(ql > qr){
        data ans;
        ans.val = 0;
        return ans;
    }
    if(ql == l and qr == r){
        return seg_tree[v];
    }
    int m = (l + r) / 2;
    return combine(query(2*v, l, m, ql, min(qr, m)), query(2*v + 1, m + 1, r, max(ql, m + 1), qr));
}

bool cmp(pair<int, pair<int, int> > &a, pair<int, pair<int, int> > &b){
    if(a.fi != b.fi){
        return a.fi > b.fi;
    }
    else{
        return a.se.fi > b.se.fi;
    }
}

int32_t main(){ _
    cin >> n;
    set<int> a_val;
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a_val.insert(a), a_val.insert(b - 1);
        arr.pb(mp(b, mp(a, c)));
    }
    sort(arr.begin(), arr.end(), cmp);
    int curr = 1;
    for(auto i: a_val){
        ac[i] = curr;
        curr++;
    }
    build(1, 0, 2*N);
    curr = 0;
    int ans = -1;
    for(auto i: arr){
        data node = query(1, 0, 2*N, 1, ac[i.fi - 1]);
        dp[curr] = node.val + i.se.se;
        ans = max(ans, dp[curr]);
        if(a_mx[ac[i.se.fi]] < dp[curr]){
            a_mx[ac[i.se.fi]] = dp[curr];
            update(1, 0, 2*N, ac[i.se.fi], dp[curr]);
        }
        curr++;
    }
    cout << ans << endl;
    return 0;
}
