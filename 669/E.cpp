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

const int MAX_IND = 6e5 + 10;

const int N = 1e5 + 100;
const int eps = 1e9;

int n;
vector<vector<int> > q;
vector<int> val;
map<int,int> cc;
int bit[MAX_IND];

void update(int no, int tim, int val){
    int hash = no*eps + tim;
    int ind = cc[hash];
    while(ind <= MAX_IND){
        bit[ind] += val;
        ind += (ind & -ind);
    }
}

int query(int no, int tim){
    int hash = no*eps + tim;
    int ind = cc[hash];
    int ans = 0;
    while(ind > 0){
        ans += bit[ind];
        ind -= (ind & -ind);
    }
    return ans;
}

int query_range(int no1, int t1, int no2, int t2){
    return (query(no1, t1) - query(no2, t2));
}


int32_t main(){
    cin >> n;
    q.resize(n);
    for(int i = 0; i < n; i++){
        q[i].resize(3);
        cin >> q[i][0] >> q[i][1] >> q[i][2];
        val.pb(q[i][1] + q[i][2]*eps);
        val.pb(q[i][2]*eps);
    }
    sort(val.begin(), val.end());
    int curr = 1;
    for(int i = 0; i < val.size(); i++){
        if(i == 0){
            cc[val[i]] = curr;
            curr++;
        }
        else{
            if(val[i] != val[i-1]){
                cc[val[i]] = curr;
                curr++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        int type, a, b;
        type = q[i][0];
        a = q[i][1];
        b = q[i][2];
        if(type == 1){
            update(b, a, 1);
        }
        if(type == 2){
            update(b, a, -1);
        }
        if(type == 3){
            cout << query_range(b, a, b, 0) << endl;
        }
    }
    return 0;
}
