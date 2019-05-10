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

const int N = 2e5;

int n, arr[N], st[8*N], L[8*N], R[8*N], nodes = 0;
map<int, int> m;

int newLeaf(int val){
    int p = ++nodes;
    L[p] = R[p] = 0; //null
    st[p] = val;
    return p;
}

int newParent(int left, int right){
    int p = ++nodes;
    L[p] = left;
    R[p] = right;
    st[p] = st[left] + st[right];
    return p;
}

// building [0, n-1]
int build(int l = 0, int r = n - 1){
    if(l == r){
        return newLeaf(arr[l]);
    }
    int mid = (l + r) / 2;
    return newParent(build(l, mid), build(mid + 1, r));
}

int update(int i, int x, int p, int l = 0, int r = n - 1){
    if(l == r){
        return newLeaf(st[p] + x);
    }
    int mid = (l + r) / 2;
    if(i <= mid){
        return newParent(update(i, x, L[p], l, mid), R[p]);
    }
    else{
        return newParent(L[p], update(i, x, R[p], mid + 1, r));
    }
}

int query(int v, int l, int r, int ql, int qr){
    if(ql > qr){
        return 0;
    }
    if(ql == l and qr == r){
        return st[v];
    }
    int mid = (l + r) / 2;
    return (query(L[v], l, mid, ql, min(qr, mid)) + query(R[v], mid + 1, r, max(ql, mid + 1), qr));
}


int32_t main(){ _
    int root = build();
    // updating with update(ind, val, version) will return the root of new version 
    // query with(version's root, 0, n - 1, l, r)
    return 0;
}
