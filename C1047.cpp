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


const int MAXN = 15000001;
const int N = 3e5 + 123;


int n, spf[MAXN];
int prime[MAXN];
int arr[N];


void sieve(){
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
    for (int i=3; i*i<MAXN; i++){
        if (spf[i] == i){
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}


map<int, int> getFactorization(int x){
    vector<int> ret;
    int temp = x;
    int xx = -1;
    while (x != 1){
        if(spf[x] != xx){
            ret.push_back(spf[x]);
            xx = spf[x];
        }
        x = x / spf[x];
    }
    // auto ip = unique(all(ret));
    // ret.resize(std::distance(ret.begin(), ip));
    vector<int> count((int)ret.size());
    int sz = (int)ret.size();
    int j = 0;
    for(auto i: ret){
        while(temp % i == 0){
            count[j]++;
            temp /= i;
        }
        j++;
    }
    map<int, int> a;
    for(int i = 0; i < sz; i++){
        a[ret[i]] = count[i];
    }
    return a;
}



int32_t main(){ _
    cin >> n;
    sieve();
    int gcd = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        gcd = __gcd(gcd, arr[i]);
    }
    auto tot = getFactorization(gcd);
    for(int i = 0; i < n; i++){
        auto temp = getFactorization(arr[i]);
        for(auto j: temp){
            // tr(arr[i], j);
            if(tot.find(j.fi) == tot.end()){
                prime[j.fi]++;
            }
            else{
                if(tot[j.fi] < j.se){
                    prime[j.fi]++;
                }
            }
        }
    }
    int ans = 4e5;
    // for(int i = 0; i < 10; i++){
    //     cout << prime[i] << " " << i << endl;
    // }
    for(int i = 0; i < MAXN; i++){
        if(prime[i] > 0){
            ans = min(ans, (n - prime[i]));
        }
    }
    if(ans == (int)4e5){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
    return 0;
}
