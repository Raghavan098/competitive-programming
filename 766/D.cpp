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

const int N = 1e5 + 100;
int n, m, q, parent[N], size[N], opp[N];
string arr[N];
map<string, int> ind;


void make_set(ll x){
    parent[x] = x;
    size[x] = 1;
}

ll find_set(ll v){
    if(v==parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a,ll b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

void yes(){
    cout << "YES\n";
}

void no(){
    cout << "NO\n";
}

int32_t main(){
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        ind[arr[i]] = i;
        opp[i] = -1;
    }
    for(int i = 0; i < n; i++){
        make_set(i);
    }
    for(int i = 0; i < m; i++){
        int typ;
        string aa, ba;
        cin >> typ;
        cin >> aa >> ba;
        int a, b;
        a = find_set(ind[aa]);
        b = find_set(ind[ba]);
        if(typ == 1){
            if(a == b){
                yes();
                continue;
            }
            if(opp[a] == b){
                no();
                continue;
            }
            if(opp[b] == a){
                no();
                continue;
            }
            yes();
            union_sets(a, b);
            if(opp[a] != -1 and opp[b] != -1){
                int x = opp[a];
                union_sets(opp[a], opp[b]);
                x = find_set(x);
                opp[find_set(a)] = x;
                opp[x] = find_set(a);
            }
            else if(opp[a] == -1 and opp[b] != -1){
                opp[find_set(a)] = opp[b];
            }
            else if(opp[a] != -1 and opp[b] == -1){
                opp[find_set(b)] = opp[a];
            }
        }
        else{
            if(a == b){
                no();
                continue;
            }
            if(opp[a] == b){
                yes();
                continue;
            }
            if(opp[b] == a){
                yes();
                continue;
            }
            yes();
            if(opp[a] != -1){
                int q, w;
                q = opp[a];
                union_sets(q, b);
            }
            if(opp[b] != -1){
                int q, w;
                q = opp[b];
                union_sets(q, a);
            }
            opp[find_set(a)] = find_set(b);
            opp[find_set(b)] = find_set(a);
        }
    }
    for(int i = 0; i < q; i++){
        string a, b;
        cin >> a >> b;
        int q = find_set(ind[a]);
        int w = find_set(ind[b]);
        if(q == w){
            cout << 1 << endl;
        }
        else if(opp[q] == w or opp[w] == q){
            cout << 2 << endl;
        }
        else{
            cout << 3 << endl;
        }
    }
}
