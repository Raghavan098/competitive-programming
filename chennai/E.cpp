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

int solve(){
    int n;
    cin >> n;
    cout << 1 << " " << 1 << endl;
    fflush(stdout);
    int fir;
    cin >> fir;
    int l = 1;
    int r = n;
    int mid, k, temp;
    while(l <= r){
        mid = (l + r)/2;
        cout << 1 << " " << mid << endl;
        fflush(stdout);
        cin >> temp;
        if(temp <= fir){
            k = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    // tr(k);
    int a, b;
    if(2*k>n or 2*k+1>n){
        cout<<1<<" "<<n<<endl;
        fflush(stdout);
        cin>>a;
        cout<<2<<" "<<a<<endl;
        fflush(stdout);
        return 0;
    }
    // tr(k);
    int c;
    cout << 1 << " " << k + 1 << endl;
    fflush(stdout);
    cin >> c;
    cout << 1 << " " << 2*k << endl;
    fflush(stdout);
    cin >> a;
    cout << 1 << " " << 2*k +1 << endl;
    fflush(stdout);
    cin >> b;
    if(a == b and b == c){
        cout << 2 << " " << fir << endl;
        fflush(stdout);
        return 0;
    }
    l = 1;
    r = n/k;
    int ans = 0;
    while(l <= r){
        mid = (l + r)/2;
        cout << 1 << " " << k*mid << endl;
        fflush(stdout);
        cin >> a;
        cout << 1 << " " << k*mid + 1 << endl;
        fflush(stdout);
        cin >> b;
        if(a != b){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    // tr(ans);
    cout << 1 << " " << ans*k + 1 << endl;
    fflush(stdout);
    cin >> a;
    cout << 2 << " " << a << endl;
    fflush(stdout);
    return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
