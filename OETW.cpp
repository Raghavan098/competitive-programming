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

int solve(){
    int n;
    cin >> n;
    vector<int> arr(n), c(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i){
            c[i] = c[i-1] + arr[i];
        }
        else{
            c[0] = arr[0];
        }
    }
    int cur = n;
    for(int i = n-1; i >= 0; i--){
        if(arr[i] == 1){
            cur = i;
        }
        else{
            b[i] = cur;
        }
    }
    int ans = 0;
    // tr(arr, b, c);
    for(int i = 1; i <= c[n-1]; i++){
        int l = 0;
        int r = n-1;
        int mid, a = -1;
        while(l <= r){
            mid = (l + r)/2;
            if(c[mid] >= i){
                a = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        // tr(i, a, ans);
        if(a != -1){
            if(c[a] == i){
                ans++;
            }
            else{
                int l = 0;
                int r = a;
                if((b[a] - a) < b[0]){
                    if(b[a] != n)
                        ans++;
                }
                else if((b[a] - a) > b[0]){
                    int off = b[0];
                    if((a + off) < n){
                        ans++;
                    }
                }
                else{
                    if(b[a] != n)
                        ans++;
                }
            }
        }
    }
    cout << ans << endl;
}

int32_t main(){ _
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
