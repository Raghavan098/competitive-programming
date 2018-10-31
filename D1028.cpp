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


const int N = 4e5 + 10;
const int MAX_P = 4e8;
const int mod = 1e9 + 7;
int n;
set<int> buy, sell, done;
queue<pair<int, int> > acc;
vector<pair<string, int> > arr;

// highest buyer and lowest seller

int32_t main(){ _
    cin >> n;
    for(int i = 0; i < n; i++){
        string temp;
        int a;
        cin >> temp >> a;
        arr.pb(mp(temp, a));
        if(temp == "ACCEPT"){
            acc.push(mp(a, i));
        }
    }
    int curp = 0;
    buy.insert(-1);
    sell.insert(MAX_P);
    int ans = 1;
    while(!acc.empty()){
        auto temp = acc.front();
        acc.pop();
        int top_buy = *(buy.rbegin());
        int top_sell = *(sell.begin());
        if(temp.fi < top_buy or temp.fi > top_sell){
            cout << 0 << endl;
            return 0;
        }
        if(done.find(temp.fi) == done.end()){
            done.insert(temp.fi);
            ans = (ans * 2) % mod;
        }
        for(int i = curp; i < temp.se; i++){
            if(arr[i].se > temp.fi){
                sell.insert(arr[i].se);
            }
            else if(arr[i].se < temp.fi){
                buy.insert(arr[i].se);
            }
            done.insert(arr[i].se);
        }
        if(buy.find(temp.fi) != buy.end()){
            buy.erase(temp.fi);
        }
        if(sell.find(temp.fi) != sell.end()){
            sell.erase(temp.fi);
        }
        curp = temp.se + 1;
    }
    int top_buy = *(buy.rbegin());
    int top_sell = *(sell.begin());
    int cnt = 0;
    for(int i = curp; i < n; i++){
        if(arr[i].se > top_buy and arr[i].se < top_sell){
            cnt ++;
        }
    }
    cout << (ans * (cnt + 1)) % mod << endl;
    return 0;
}
