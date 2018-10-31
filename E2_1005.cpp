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

const int N = 2e5 + 5;
int n, m;
int arr[N], brr[N], cumu[N];
const int MAX_IND = N*2 + 10;
int bit[2][2*N + 100];

void update(int ind, int val, int typ){
    ind += N;
    if(typ == 0){
        while(ind <= MAX_IND){
            bit[0][ind] += val;
            ind += (ind & -ind);
        }
    }
    else{
        while(ind <= MAX_IND){
            bit[1][ind] += val;
            ind += (ind & -ind);
        }
    }
}

int query(int ind, int typ){
    int ans = 0;
    ind += N;
    if(typ == 0){
        while(ind > 0){
            ans += bit[0][ind];
            ind -= (ind & -ind);
        }
    }
    else{
        while(ind > 0){
            ans += bit[1][ind];
            ind -= (ind & -ind);
        }
    }
    return ans;
}

int calc(int no){
    for(int i = 0; i < n; i++){
        if(arr[i] >= no){
            brr[i] = 1;
        }
        else{
            brr[i] = -1;
        }
    }
    cumu[0] = brr[0];
    for(int i = 1; i < n; i++){
        cumu[i] = cumu[i-1] + brr[i];
    }
    int ans = 0;
    MEMS(bit, 0);
    update(0, 1, 1);
    for(int i = 0; i < n; i++){
        int temp = cumu[i];
        int a, b;
        if(i%2==0){
            a = query(temp, 1);
            b = query(temp - 1, 0);
            update(temp, 1, 0);
        }
        else{
            a = query(temp, 0);
            b = query(temp - 1, 1);
            update(temp, 1, 1);
        }
        ans += (a + b);
    }
    return ans;
}

int32_t main(){ _
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << calc(m) - calc(m + 1) << endl;
    return 0;
}
