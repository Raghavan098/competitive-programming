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

const int N = 2e6 + 100;

int arr[N], n, q, e, o, off, typ, x;


int32_t main(){ _
    cin >> n >> q;
    for(int i = 0; i < q; i++){
        cin >> typ;
        if(typ == 1){
            cin >> off;
            e += off;
            o += off;
            if(abs(off) % 2 == 1){
                swap(e, o);
                x ^= 1;
            }
        }
        else{
            e -= 1;
            o += 1;
            swap(e, o);
            x ^= 1;
        }
    }
    for(int i = 1; i <= n; i++){
        int temp = i%2;
        temp ^= x;
        int ind;
        if(temp % 2 == 0){
            ind = (i + e);
        }
        else{
            ind = (i + o);
        }
        ind = (ind%n);
        while(ind < 0){
            ind += n;
        }
        if(ind == 0){
            ind = n;
        }
        arr[ind] = i;
    }
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }cout << endl;
    return 0;
}
